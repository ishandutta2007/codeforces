import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Museum implements Runnable {
    static class Student {
        int mark = 0;
        Student friend;
        List<Student> friendOf = new ArrayList<Student>(1);
        boolean gender;
        int index;
    }

    static abstract class Answer implements Comparable<Answer> {
        final int numPairs;
        final int numGoodPairs;

        Answer(int numPairs, int numGoodPairs) {
            this.numPairs = numPairs;
            this.numGoodPairs = numGoodPairs;
        }

        public int compareTo(Answer answer) {
            if (numPairs != answer.numPairs)
                return numPairs - answer.numPairs;
            else
                return numGoodPairs - answer.numGoodPairs;
        }

        abstract void outputPairs(PrintWriter writer);
    }

    static class EmptyAnswer extends Answer {
        EmptyAnswer() {
            super(0, 0);
        }

        @Override
        void outputPairs(PrintWriter writer) {
            // Do nothing.
        }
    }

    static class SinglePairAnswer extends Answer {
        Student first;
        Student second;

        SinglePairAnswer(Student first, Student second) {
            super(1, first.gender == second.gender ? 0 : 1);
            this.first = first;
            this.second = second;
        }

        @Override
        void outputPairs(PrintWriter writer) {
            writer.println(first.index + " " + second.index);
        }
    }

    static Answer combine(final Answer a, final Answer b) {
        return new Answer(a.numPairs + b.numPairs, a.numGoodPairs + b.numGoodPairs){
            @Override
            void outputPairs(PrintWriter writer) {
                a.outputPairs(writer);
                b.outputPairs(writer);
            }
        };
    }

    private void solve() throws IOException {
        int n = nextInt();
        Student[] s = new Student[n];
        for (int i = 0; i < n; ++i) s[i] = new Student();
        for (int i = 0; i < n; ++i) {
            s[i].friend = s[nextInt() - 1];
            s[i].friend.friendOf.add(s[i]);
            s[i].gender = nextInt() == 1;
            s[i].index = i + 1;
        }
        List<Answer> bestAnswers = new ArrayList<Answer>();
        for (int i = 0; i < n; ++i) if (s[i].mark == 0) {
            Student root = s[i];
            while (root.mark == 0) {
                root.mark = 1;
                root = root.friend;
            }
            Answer ans1 = solveForTree(root, 2)[0];
            root = root.friend;
            Answer ans2 = solveForTree(root, 3)[0];
            if (ans1.compareTo(ans2) > 0) {
                bestAnswers.add(ans1);
            } else {
                bestAnswers.add(ans2);
            }
        }
        Answer allTogether = new EmptyAnswer();
        for (Answer ans : bestAnswers)
            allTogether = combine(allTogether, ans);
        writer.println(allTogether.numPairs + " " + allTogether.numGoodPairs);
        allTogether.outputPairs(writer);
    }

    private Answer[] solveForTree(Student root, int markToUse) {
        if (root.mark >= markToUse) throw new RuntimeException();
        root.mark = markToUse;
        List<Answer[]> children = new ArrayList<Answer[]>(root.friendOf.size());
        long[] bestChildScore = new long[2];
        Arrays.fill(bestChildScore, Long.MIN_VALUE);
        Answer[][] bestChildAnswer = new Answer[2][];
        Student[] bestChildFor = new Student[2];
        for (Student child : root.friendOf) {
            if (child.mark < markToUse) {
                Answer[] childAnswer = solveForTree(child, markToUse);
                children.add(childAnswer);
                long childScore = (childAnswer[1].numPairs - childAnswer[0].numPairs) * 1000000L + (childAnswer[1].numGoodPairs - childAnswer[0].numGoodPairs);
                int genderId = child.gender ? 1 : 0;
                if (childScore > bestChildScore[genderId]) {
                    bestChildScore[genderId] = childScore;
                    bestChildAnswer[genderId] = childAnswer;
                    bestChildFor[genderId] = child;
                }
            }
        }
        Answer notTake = new EmptyAnswer();
        for (Answer[] childAnswer : children) notTake = combine(notTake, childAnswer[0]);
        Answer take = notTake;
        for (int genderId = 0; genderId < 2; ++genderId) {
            Answer[] best = bestChildAnswer[genderId];
            if (best != null) {
                Answer cur = new SinglePairAnswer(root, bestChildFor[genderId]);
                cur = combine(cur, best[1]);
                for (Answer[] childAnswer : children)
                    if (childAnswer != best)
                        cur = combine(cur, childAnswer[0]);
                if (cur.compareTo(take) > 0)
                    take = cur;
            }
        }
        return new Answer[]{take, notTake};
    }

    public static void main(String[] args) {
        new Museum().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
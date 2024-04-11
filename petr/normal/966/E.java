import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int BUBEN = 600;
        TaskE.Employee[] seq;
        int seqPos;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskE.Employee[] employees = new TaskE.Employee[n];
            for (int i = 0; i < n; ++i) {
                employees[i] = new TaskE.Employee();
            }
            for (int i = 1; i < n; ++i) employees[i].boss = employees[in.nextInt() - 1];
            for (int i = 0; i < n; ++i) employees[i].tolerance = in.nextInt();
            for (TaskE.Employee e : employees)
                if (e.boss != null) {
                    e.nextSibling = e.boss.firstChild;
                    e.boss.firstChild = e;
                }
            TaskE.Employee ceo = employees[0];
            seq = new TaskE.Employee[n];
            seqPos = 0;
            writeOut(ceo);
            if (seqPos != n) throw new RuntimeException();
            for (int i = 0; i < n; ++i) seq[i].inSeq = i;

            int[] parent = new int[n];
            for (int i = 0; i < n; ++i) {
                if (seq[i].boss == null) parent[i] = -1;
                else parent[i] = seq[i].boss.inSeq;
            }
            int[] tolerance = new int[n];
            for (int i = 0; i < n; ++i) {
                tolerance[i] = seq[i].tolerance;
            }
            int[] actual = new int[n];
            boolean[] onVacation = new boolean[n];

            int[] interestingChildren = new int[n];
            boolean[] interesting = new boolean[n];

            int[] jumpParent = new int[n];
            int[] first = new int[n];
            int[] last = new int[n];
            int[] all = new int[n];
            int[] delta = new int[n];
            int[] unhappyThere = new int[n];

            int[] events = new int[m];
            for (int i = 0; i < m; ++i) events[i] = employees[Math.abs(in.nextInt()) - 1].inSeq;
            for (int start = 0; start < m; start += BUBEN) {
                int end = Math.min(m, start + BUBEN);

                Arrays.fill(actual, 0);
                for (int i = n - 1; i >= 0; --i) {
                    if (onVacation[i]) {
                        ++actual[i];
                    }
                    if (i > 0) actual[parent[i]] += actual[i];
                }

                int unhappy = 0;
                for (int i = 0; i < n; ++i) if (!onVacation[i] && actual[i] > tolerance[i]) ++unhappy;

                Arrays.fill(interesting, false);
                for (int i = start; i < end; ++i) interesting[events[i]] = true;

                Arrays.fill(interestingChildren, 0);
                for (int i = n - 1; i > 0; --i) {
                    if (interesting[i] || interestingChildren[i] > 0) {
                        ++interestingChildren[parent[i]];
                    }
                }

                for (int i = 0; i < n; ++i) if (interestingChildren[i] >= 2) interesting[i] = true;

                int overallPos = 0;

                for (int i = 0; i < n; ++i)
                    if (interesting[i]) {
                        first[i] = overallPos;
                        int at = parent[i];
                        unhappyThere[i] = 0;
                        while (at >= 0 && !interesting[at]) {
                            if (!onVacation[at]) {
                                all[overallPos++] = tolerance[at] - actual[at];
                                if (all[overallPos - 1] < 0) ++unhappyThere[i];
                            }
                            at = parent[at];
                        }
                        jumpParent[i] = at;
                        last[i] = overallPos;
                        delta[i] = 0;
                        Arrays.sort(all, first[i], last[i]);
                    }

                for (int i = start; i < end; ++i) {
                    int event = events[i];
                    onVacation[event] ^= true;
                    int change = onVacation[event] ? 1 : -1;
                    if (onVacation[event]) {
                        if (tolerance[event] < actual[event] + delta[event]) --unhappy;
                    } else {
                        if (tolerance[event] < actual[event] + delta[event]) ++unhappy;
                    }
                    int cur = event;
                    while (cur >= 0) {
                        if (!onVacation[cur] && tolerance[cur] < actual[cur] + delta[cur]) --unhappy;
                        delta[cur] += change;
                        if (!onVacation[cur] && tolerance[cur] < actual[cur] + delta[cur]) ++unhappy;
                        unhappy -= unhappyThere[cur];
                        int left = first[cur] - 1;
                        int right = last[cur];
                        while (right - left > 1) {
                            int middle = (left + right) >> 1;
                            if (all[middle] < delta[cur]) {
                                left = middle;
                            } else {
                                right = middle;
                            }
                        }
                        unhappyThere[cur] = right - first[cur];
                        unhappy += unhappyThere[cur];
                        cur = jumpParent[cur];
                    }
                    out.print(unhappy + " ");
                }
            }
            out.println();
        }

        private void writeOut(TaskE.Employee e) {
            seq[seqPos++] = e;
            TaskE.Employee u = e.firstChild;
            while (u != null) {
                writeOut(u);
                u = u.nextSibling;
            }
        }

        static class Employee {
            int tolerance;
            int inSeq;
            TaskE.Employee boss;
            TaskE.Employee firstChild;
            TaskE.Employee nextSibling;

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
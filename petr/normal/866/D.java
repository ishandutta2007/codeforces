import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TreeSet<TaskD.Candidate> candidates = new TreeSet<>();
            long res = 0;
            for (int step = 0; step < n; ++step) {
                int p = in.nextInt();
                TaskD.Candidate left = new TaskD.Candidate(p, step * 2);
                candidates.add(left);
                TaskD.Candidate c = candidates.pollFirst();
                res += p - c.p;
                TaskD.Candidate right = new TaskD.Candidate(p, step * 2 + 1);
                candidates.add(right);
            }
            out.println(res);
        }

        static class Candidate implements Comparable<TaskD.Candidate> {
            int p;
            int index;

            public Candidate(int p, int index) {
                this.p = p;
                this.index = index;
            }


            public int compareTo(TaskD.Candidate o) {
                if (p != o.p) return p - o.p;
                return index - o.index;
            }

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
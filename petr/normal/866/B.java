import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long S = in.nextLong();
            TaskB.Person[] p = new TaskB.Person[n];
            for (int i = 0; i < n; ++i) p[i] = new TaskB.Person();
            long need = 0;
            for (int i = 0; i < n; ++i) {
                p[i].s = in.nextInt();
                p[i].a = in.nextInt();
                p[i].b = in.nextInt();
                need += p[i].s;
            }
            long am = (need + S - 1) / S;
            long extra = am * S - need;
            p = Arrays.copyOf(p, n + 1);
            p[n] = new TaskB.Person();
            p[n].s = extra;
            ++n;
            Arrays.sort(p, new Comparator<TaskB.Person>() {

                public int compare(TaskB.Person o1, TaskB.Person o2) {
                    return (o1.a - o1.b) - (o2.a - o2.b);
                }
            });
            long res = 0;
            for (TaskB.Person pp : p) res += pp.s * pp.a;
            long cur = res;
            long tail = 0;
            for (TaskB.Person pp : p) {
                if (tail + pp.s < S) {
                    tail += pp.s;
                    cur += pp.s * (pp.b - pp.a);
                    continue;
                }
                long by = S - tail;
                tail += by;
                pp.s -= by;
                cur += (pp.b - pp.a) * by;
                res = Math.max(res, cur);
                long whole = pp.s / S;
                cur += (pp.b - pp.a) * S * whole;
                pp.s -= S * whole;
                res = Math.max(res, cur);
                tail = pp.s;
                cur += tail * (pp.b - pp.a);
            }
            if (tail != 0) throw new RuntimeException();
            out.println(res);
        }

        static class Person {
            long s;
            int a;
            int b;

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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}
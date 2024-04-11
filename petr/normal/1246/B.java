import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
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
            int k = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextInt();
            int maxa = 3;
            for (int x : a) maxa = Math.max(maxa, x + 1);
            int[] d = new int[maxa];
            for (int i = 2; i < maxa; ++i) d[i] = i;
            for (int i = 2; i * i < maxa; ++i)
                if (d[i] == i) {
                    for (int j = i * i; j < maxa; j += i) if (d[j] == j) d[j] = i;
                }
            int[] v = new int[1000];
            int[] v2 = new int[1000];
            Map<TaskB.Signature, Integer> sofar = new HashMap<>();
            long res = 0;
            for (int x : a) {
                int nv = 0;
                while (x > 1) {
                    int q = d[x];
                    int pw = 0;
                    while (x % q == 0) {
                        x /= q;
                        ++pw;
                    }
                    if (pw % k != 0) {
                        v[nv] = q;
                        v[nv + 1] = pw % k;
                        v2[nv] = q;
                        v2[nv + 1] = k - pw % k;
                        nv += 2;
                    }
                }
                TaskB.Signature s1 = new TaskB.Signature(Arrays.copyOf(v, nv));
                TaskB.Signature s2 = new TaskB.Signature(Arrays.copyOf(v2, nv));
                Integer old = sofar.get(s2);
                if (old != null)
                    res += old;
                old = sofar.get(s1);
                if (old == null) {
                    sofar.put(s1, 1);
                } else {
                    sofar.put(s1, old + 1);
                }
            }
            out.println(res);
        }

        static class Signature {
            int[] vals;

            public Signature(int[] vals) {
                this.vals = vals;
            }

            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                TaskB.Signature signature = (TaskB.Signature) o;
                return Arrays.equals(vals, signature.vals);
            }

            public int hashCode() {
                return Arrays.hashCode(vals);
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
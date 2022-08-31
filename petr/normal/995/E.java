import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Random;
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
        Random random = new Random(7435431513L);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int u = in.nextInt();
            int v = in.nextInt();
            int p = in.nextInt();
            double phi = (1 + Math.sqrt(5)) / 2;
            int[] seq1 = reduce(u, p, phi);
            int[] seq2 = reduce(v, p, phi);
            if (seq1.length + seq2.length > 200) {
                while (true) ;
            }
            out.println(seq1.length + seq2.length);
            int sofar = u;
            for (int i = 0; i < seq1.length; ++i) {
                sofar = doit(sofar, p, seq1[i]);
                out.print(seq1[i] + " ");
            }
            for (int i = seq2.length - 1; i >= 0; --i) {
                int a = seq2[i];
                if (a != 3) a = 3 - a;
                sofar = doit(sofar, p, a);
                out.print(a + " ");
            }
            if (sofar != v) throw new RuntimeException();
            out.println();
        }

        private int doit(int sofar, int p, int a) {
            if (a == 1) {
                sofar = (sofar + 1) % p;
            } else if (a == 2) {
                sofar = (sofar + p - 1) % p;
            } else if (a == 3) {
                if (sofar == 0) throw new RuntimeException();
                sofar = pow(sofar, p - 2, p);
            } else {
                throw new RuntimeException();
            }
            return sofar;
        }

        private int pow(int a, int k, int p) {
            if (k == 0) return 1;
            if (k % 2 == 0) {
                return pow((int) (a * (long) a % p), k / 2, p);
            }
            return (int) (a * (long) pow(a, k - 1, p) % p);
        }

        private int[] reduce(int u, int p, double phi) {
            if (u == 0) return new int[0];
            int upto = (int) Math.max(1, Math.floor((p - 2) / phi));
            outer:
            while (true) {
                int bi = random.nextInt(upto) + 1;
                int a = (int) (u * (long) bi % p);
                int b = bi;
                int[] res = new int[101];
                int rescnt = 0;
                while (true) {
                    int k = a / b;
                    for (int i = 0; i < k; ++i) {
                        res[rescnt++] = 2;
                        if (rescnt > 100) continue outer;
                    }
                    a -= b * k;
                    if (a == 0) break;
                    res[rescnt++] = 3;
                    if (rescnt > 100) continue outer;
                    int tmp = a;
                    a = b;
                    b = tmp;
                }
                return Arrays.copyOf(res, rescnt);
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
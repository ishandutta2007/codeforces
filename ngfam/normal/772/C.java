import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ngfam
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CVulnerableKerbals solver = new CVulnerableKerbals();
        solver.solve(1, in, out);
        out.close();
    }

    static class CVulnerableKerbals {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            int dp[] = new int[m + 5];
            int count[] = new int[m + 5];
            Arrays.fill(count, 1);

            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                count[x] = 0;
            }

            ArrayList<Integer> a[] = new ArrayList[m + 5];
            for (int i = 0; i < a.length; ++i) {
                a[i] = new ArrayList<>();
            }

            for (int i = 1; i < m; ++i) {
                if (count[i] == 0) continue;
                int g = gcd(i, m);
                a[g].add(i);
                dp[g]++;
            }

            int next[] = new int[m + 5];
            for (int i = m - 1; i > 0; --i) {
                int best = 0;
                for (int j = i + i; j < m; j += i) {
                    if (best < dp[j]) {
                        best = dp[j];
                        next[i] = j;
                    }
                }
                int j = next[i];
                dp[i] += best;
            }

            out.println(dp[1] + count[0]);

            int last = -1;
            for (int x = 1; x > 0; x = next[x]) {
                //out.println(x);
                if (x > a.length) {
                    out.println(x);
                    return;
                }
                for (int cur : a[x]) {
                    if (last == -1) {
                        out.print(cur + " ");
                        last = cur;
                        continue;
                    }

                    int w = (extended_gcd(last, m) + m) % m;
                    long r = cur / gcd(last, m);
                    r = (r * w) % m;
                    out.print(r + " ");
                    last = cur;
                }
            }
            if (count[0] == 1) out.print(0);
        }

        private int extended_gcd(int a, int b) {
            int req = gcd(a, b);
            int r = a, s = 1, t = 0;
            int ar = b, as = 0, at = 1;
            while (true) {
                int q = r / ar;
                int br = r - q * ar;
                int bs = s - q * as;
                int bt = t - q * at;
                r = ar;
                s = as;
                t = at;
                ar = br;
                as = bs;
                at = bt;
                if (ar == req) return as;
            }
        }

        private int gcd(int a, int b) {
            return (b > 0 ? gcd(b, a % b) : a);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}
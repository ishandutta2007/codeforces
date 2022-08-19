import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        long[] a;
        long[] b;
        long[] c;
        long[] d;
        int n;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            long k = in.nextLong() - 1;
            a = new long[n];
            for (int i = 1; i < n; ++i) {
                int p = in.nextInt() - 1;
                a[i] = a[p] ^ in.nextLong();
            }
            Random random = new Random(534515151L + System.currentTimeMillis());
            for (int i = 1; i < n; ++i) {
                int j = random.nextInt(i + 1);
                long t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            Arrays.sort(a);
            b = a.clone();
            c = new long[n];
            d = new long[n];
            long pmask = 0;
            for (int bit = 62; bit >= 0; --bit) {
                pmask <<= 1;
                long am = countCommon(bit);
            /*if (n < 1000 && am != countCommonStupid(bit)) {
                throw new RuntimeException();
            }*/
                if (am <= k) {
                    k -= am;
                    pmask ^= 1;
                    flipBit(bit);
                }
            }
//        if (k != 0) throw new RuntimeException();
            out.println(pmask);
        }

        private void flipBit(int bit) {
        /*for (int i = 0; i < n; ++i) b[i] ^= (1L << bit);
        Arrays.sort(b);*/
            int pos = 0;
            int pc = 0;
            int pd = 0;
            while (pos < n) {
                int spos = pos;
                long val = b[pos] ^ (1L << bit);
                long v = val >> bit;
                long vv = v >> 1;
                while (true) {
                    if ((v & 1) == 0) c[pc++] = val;
                    else d[pd++] = val;
                    ++pos;
                    if (pos >= n) break;
                    val = b[pos] ^ (1L << bit);
                    v = val >> bit;
                    if ((v >> 1) != vv) break;
                }
                for (int i = 0; i < pc; ++i) b[spos++] = c[i];
                for (int i = 0; i < pd; ++i) b[spos++] = d[i];
                pc = 0;
                pd = 0;
                if (spos != pos) throw new RuntimeException();
            }
        }

        private long countCommon(int bit) {
            int pa = 0;
            int pb = 0;
            long va = a[pa] >> bit;
            long vb = b[pb] >> bit;
            long res = 0;
            while (true) {
                if (va < vb) {
                    ++pa;
                    if (pa >= n) break;
                    va = a[pa] >> bit;
                } else if (va > vb) {
                    ++pb;
                    if (pb >= n) break;
                    vb = b[pb] >> bit;
                } else {
                    int sa = pa++;
                    int sb = pb++;
                    long sv = va;
                    while (pa < n) {
                        va = a[pa] >> bit;
                        if (va != sv) break;
                        ++pa;
                    }
                    while (pb < n) {
                        vb = b[pb] >> bit;
                        if (vb != sv) break;
                        ++pb;
                    }
                    res += (pa - sa) * (long) (pb - sb);
                    if (pa >= n || pb >= n) break;
                }
            }
            return res;
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
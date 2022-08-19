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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextInt();
            int maxa = 3;
            for (int x : a) maxa = Math.max(maxa, x + 1);
            int[] divisor = new int[maxa];
            for (int i = 2; i < maxa; ++i)
                if (divisor[i] == 0) {
                    divisor[i] = i;
                    long jj = i * (long) i;
                    if (jj < maxa) {
                        for (int j = (int) jj; j < maxa; j += i) if (divisor[j] == 0) divisor[j] = i;
                    }
                }
            int[] count = new int[maxa];
            for (int i = 0; i < a.length; ++i) {
                int x = a[i];
                while (x > 1) {
                    int q = divisor[x];
                    ++count[q];
                    while (x % q == 0) x /= q;
                }
            }
            for (int d = 0; d < maxa; ++d)
                if (count[d] >= k) {
                    int togo = k;
                    for (int i = 0; i < n && togo > 0; ++i)
                        if (a[i] % d == 0) {
                            --togo;
                            out.print((i + 1) + " ");
                        }
                    if (togo != 0) throw new RuntimeException();
                    out.println();
                    return;
                }
            Random random = new Random(574315315151L + System.currentTimeMillis());
            boolean[] used = new boolean[n];
            int[] r = new int[k];
            int[] extra = new int[n];
            outer:
            while (true) {
                Arrays.fill(used, false);
                int ptr = 0;
                while (ptr < k) {
                    int at;
                    do {
                        at = random.nextInt(n);
                    } while (used[at]);
                    int val = a[at];
                    boolean alreadyGood = false;
                    int numExtra = 0;
                    for (int i = 0; i < n; ++i) {
                        if (gcd(val, a[i]) == 1) {
                            if (used[i]) {
                                alreadyGood = true;
                            } else {
                                extra[numExtra++] = i;
                            }
                        }
                    }
                    if (alreadyGood || (ptr + 1 < k && numExtra > 0)) {
                        used[at] = true;
                        r[ptr] = at;
                        ++ptr;
                        numExtra = Math.min(k - ptr, numExtra);
                        for (int i = 0; i < numExtra; ++i) {
                            at = extra[i];
                            used[at] = true;
                            r[ptr] = at;
                            ++ptr;
                        }
                    } else {
                        continue outer;
                    }
                }
                for (int x : r) out.print(x + 1 + " ");
                out.println();
                return;
            }
        }

        private int gcd(int a, int b) {
            while (b > 0) {
                int t = a % b;
                a = b;
                b = t;
            }
            return a;
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
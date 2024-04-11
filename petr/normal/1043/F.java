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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        int MAX_DIVISORS = 6;
        int INF = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            int maxa = 1;
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                maxa = Math.max(maxa, a[i]);
            }
            int[] divisor = new int[maxa + 1];
            for (int i = 2; i <= maxa; ++i)
                if (divisor[i] == 0) {
                    divisor[i] = i;
                    for (int j = 2 * i; j <= maxa; j += i) if (divisor[j] == 0) divisor[j] = i;
                }
            for (int i = 0; i < n; ++i) {
                int q = a[i];
                int p = 1;
                while (q > 1) {
                    int d = divisor[q];
                    while (q % d == 0) {
                        q /= d;
                    }
                    p *= d;
                }
                a[i] = p;
            }
            int[] count = new int[maxa + 1];
            for (int x : a) ++count[x];
            for (int d = 2; d <= maxa; ++d)
                if (divisor[d] == d) {
                    for (int i = d; i <= maxa; i += d) count[i / d] += count[i];
                }

            int[] curDivisors = new int[MAX_DIVISORS];
            int[] curProd = new int[1 << MAX_DIVISORS];
            int[] curCount = new int[1 << MAX_DIVISORS];
            int[] minOps = new int[1 << MAX_DIVISORS];
            int res = INF;
            for (int first = 0; first < n; ++first) {
                int f = a[first];
                int k = 0;
                while (f > 1) {
                    curDivisors[k++] = divisor[f];
                    f /= divisor[f];
                }
                for (int set = 0; set < (1 << k); ++set) {
                    int prod = 1;
                    if (set > 0) {
                        int tz = Integer.numberOfTrailingZeros(set);
                        prod = curProd[set ^ (1 << tz)] * curDivisors[tz];
                    }
                    curProd[set] = prod;
                    curCount[set] = count[prod];
                }
                for (int bit = 0; bit < k; ++bit) {
                    for (int i = 0; i < (1 << k); ++i) {
                        if ((i & (1 << bit)) == 0) {
                            curCount[i] -= curCount[i ^ (1 << bit)];
                        }
                    }
                }
                Arrays.fill(minOps, INF);
                for (int i = 0; i < (1 << k); ++i) {
                    if (curCount[i] > 0)
                        minOps[(1 << k) - 1 - i] = 1;
                }
                for (int bit = 0; bit < k; ++bit) {
                    for (int i = 0; i < (1 << k); ++i) {
                        if ((i & (1 << bit)) == 0) {
                            if (minOps[i ^ (1 << bit)] == 1) minOps[i] = 1;
                        }
                    }
                }
                minOps[0] = 0;
                for (int i = 1; i < (1 << k); ++i) {
                    for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
                        minOps[i] = Math.min(minOps[i], minOps[j] + minOps[i ^ j]);
                    }
                }
                res = Math.min(res, 1 + minOps[(1 << k) - 1]);
            }
            if (res >= INF) {
                out.println(-1);
            } else {
                out.println(res);
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
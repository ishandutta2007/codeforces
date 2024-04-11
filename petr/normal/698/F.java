import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] p = new int[n + 1];
            for (int i = 1; i <= n; ++i) {
                p[i] = in.nextInt();
            }
            int[] invp = new int[n + 1];
            for (int i = 1; i <= n; ++i) {
                if (p[i] > 0) {
                    invp[p[i]] = i;
                }
            }
            int[] fact = new int[n + 1];
            fact[0] = 1;
            for (int i = 1; i <= n; ++i) {
                fact[i] = (int) (i * (long) fact[i - 1] % MODULO);
            }
            int[] smallestDivisor = new int[n + 1];
            int[] freedomByFrac = new int[n + 1];
            for (int prime = 2; prime <= n; ++prime)
                if (smallestDivisor[prime] == 0) {
                    smallestDivisor[prime] = prime;
                    if (prime * (long) prime <= n) {
                        for (int j = prime * prime; j <= n; j += prime) {
                            if (smallestDivisor[j] == 0) {
                                smallestDivisor[j] = prime;
                            }
                        }
                    }
                    ++freedomByFrac[n / prime];
                }
            int[] startFreedomByFrac = freedomByFrac.clone();
            int oneGroupFreedoms = 1 + freedomByFrac[1];
            for (int i = 1; i <= n; ++i) {
                if (i == 1 || (2 * i > n && smallestDivisor[i] == i)) {
                    int j = p[i];
                    if (j > 0) {
                        if (j == 1 || (2 * j > n && smallestDivisor[j] == j)) {
                            --oneGroupFreedoms;
                        } else {
                            out.println(0);
                            return;
                        }
                    }
                    j = invp[i];
                    if (j > 0) {
                        if (j == 1 || (2 * j > n && smallestDivisor[j] == j)) {
                        } else {
                            out.println(0);
                            return;
                        }
                    }
                }
            }
            int[] trickyDirect = new int[n + 1];
            int[] trickyInverse = new int[n + 1];
            int[] freedomInGroup = new int[n + 1];
            for (int i = 2; i <= n; ++i) {
                if (2 * i > n && smallestDivisor[i] == i) {
                    continue;
                }
                int group = 1;
                int tmp = i;
                int largest = -1;
                while (tmp > 1) {
                    int d = smallestDivisor[tmp];
                    largest = d;
                    group *= d;
                    while (tmp % d == 0) {
                        tmp /= d;
                    }
                }
                if (p[i] == 0) {
                    ++freedomInGroup[group];
                } else {
                    int group2 = 1;
                    int tmp2 = p[i];
                    int largest2 = -1;
                    while (tmp2 > 1) {
                        int d = smallestDivisor[tmp2];
                        largest2 = d;
                        group2 *= d;
                        while (tmp2 % d == 0) {
                            tmp2 /= d;
                        }
                    }
                    if (n / largest != n / largest2) {
                        out.println(0);
                        return;
                    }
                    if (group / largest != group2 / largest2) {
                        out.println(0);
                        return;
                    }
                    if (startFreedomByFrac[n / largest] > 1) {
                        if (trickyDirect[largest] != 0) {
                            if (trickyDirect[largest] != largest2) {
                                out.println(0);
                                return;
                            }
                        } else {
                            trickyDirect[largest] = largest2;
                            --freedomByFrac[n / largest];
                        }
                        if (trickyInverse[largest2] != 0) {
                            if (trickyInverse[largest2] != largest) {
                                out.println(0);
                                return;
                            }
                        } else {
                            trickyInverse[largest2] = largest;
                        }
                    } else {
                        if (largest != largest2) {
                            out.println(0);
                            return;
                        }
                    }
                }
            }
            long res = fact[oneGroupFreedoms];
            for (int i = 2; i <= n; ++i) {
                int cur = freedomInGroup[i];
                if (cur > 1) {
                    res = res * fact[cur] % MODULO;
                }
            }
            for (int i = 2; i <= n; ++i) {
                int cur = freedomByFrac[i];
                if (cur > 1) {
                    res = res * fact[cur] % MODULO;
                }
            }
            out.println(res);
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
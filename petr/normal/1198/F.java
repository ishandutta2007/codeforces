import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long finish = System.currentTimeMillis() + 300;
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            int[] b = new int[n];
            Random random = new Random(754315351L + System.currentTimeMillis());
            int[] bads = new int[100000];
            int numBads = 0;
            int[] interesting = new int[n];
            boolean[] isInteresting = new boolean[n];
            int[] remainder = a.clone();
            int numInteresting = n;
            for (int i = 0; i < numInteresting; ++i) {
                interesting[i] = i;
            }
            int sg1 = 0;
            int sg2 = 0;
            while (System.currentTimeMillis() < finish) {
                int g1 = sg1;
                int g2 = sg2;
                for (int ii = 0; ii < numInteresting; ++ii) {
                    int i = interesting[ii];
                    int w = random.nextInt(2) + 1;
                    b[i] = w;
                    int u = a[i];
                    if (w == 1) {
                        g1 = gcd(g1, u);
                    } else {
                        g2 = gcd(g2, u);
                    }
                }
                if (g1 == 1 && g2 == 1) {
                    out.println("YES");
                    for (int x : b) {
                        out.print(x + " ");
                    }
                    out.println();
                    return;
                }
                int oldBads = numBads;
                if (g1 != 1) numBads = addBad(numBads, bads, g1);
                if (numBads != oldBads) {
                    System.err.println("Updating " + bads[numBads - 1]);
                    for (int i = 0; i < n; ++i)
                        if (!isInteresting[i]) {
                            if (remainder[i] % bads[numBads - 1] == 0) {
                                remainder[i] /= bads[numBads - 1];
                            } else {
                                isInteresting[i] = true;
                            }
                        }
                    sg1 = 0;
                    sg2 = 0;
                    numInteresting = 0;
                    for (int i = 0; i < n; ++i)
                        if (isInteresting[i]) {
                            interesting[numInteresting++] = i;
                        } else {
                            b[i] = random.nextInt(2) + 1;
                            if (b[i] == 1) {
                                sg1 = gcd(sg1, a[i]);
                            } else {
                                sg2 = gcd(sg2, a[i]);
                            }
                        }
                }
                oldBads = numBads;
                if (g2 != 1) numBads = addBad(numBads, bads, g2);
                if (numBads != oldBads) {
                    System.err.println("Updating " + bads[numBads - 1]);
                    for (int i = 0; i < n; ++i)
                        if (!isInteresting[i]) {
                            if (remainder[i] % bads[numBads - 1] == 0) {
                                remainder[i] /= bads[numBads - 1];
                            } else {
                                isInteresting[i] = true;
                            }
                        }
                    sg1 = 0;
                    sg2 = 0;
                    numInteresting = 0;
                    for (int i = 0; i < n; ++i)
                        if (isInteresting[i]) {
                            interesting[numInteresting++] = i;
                        } else {
                            b[i] = random.nextInt(2) + 1;
                            if (b[i] == 1) {
                                sg1 = gcd(sg1, a[i]);
                            } else {
                                sg2 = gcd(sg2, a[i]);
                            }
                        }
                }
            }
            out.println("NO");
        }

        private int addBad(int numBads, int[] bads, int what) {
            for (int i = 0; i < numBads; ++i) {
                what /= gcd(what, bads[i]);
            }
            if (what > 1) {
                bads[numBads++] = what;
            }
            return numBads;
        }

        private int gcd(int v, int u) {
            while (u > 0) {
                int t = v % u;
                v = u;
                u = t;
            }
            return v;
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
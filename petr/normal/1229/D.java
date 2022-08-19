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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int[][] perms;
        int[][] prod;
        int unit;
        int[] interesting;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            perms = generate(k);
            int[] u = new int[k];
            for (int i = 0; i < k; ++i) u[i] = i;
            unit = encode(u);
            generateProd();
            int[] p = new int[n];
            for (int i = 0; i < n; ++i) {
                p[i] = readPermutation(k, in);
            }
            interesting = new int[n + 1];
            out.println(doit(p, 0, n));
        }

        int[] mul(int[] a, int[] b) {
            int[] c = new int[a.length];
            for (int i = 0; i < c.length; ++i) {
                c[i] = a[b[i]];
            }
            return c;
        }

        int encode(int[] perm) {
            for (int k = 0; k < perms.length; ++k)
                if (same(perms[k], perm)) {
                    return k;
                }
            throw new RuntimeException();
        }

        private void generateProd() {
            int n = perms.length;
            int[][] res = new int[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int[] c = mul(perms[i], perms[j]);
                    res[i][j] = encode(c);
                }
            }
            prod = res;
        }

        private boolean same(int[] a, int[] b) {
            for (int i = 0; i < a.length; ++i) if (a[i] != b[i]) return false;
            return true;
        }

        private int[][] generate(int k) {
            if (k == 1) return new int[][]{new int[]{0}};
            int[][] before = generate(k - 1);
            int[][] res = new int[k * before.length][];
            for (int i = 0; i < before.length; ++i) {
                for (int p = 0; p < k; ++p) {
                    int[] a = new int[k];
                    System.arraycopy(before[i], 0, a, 0, p);
                    a[p] = k - 1;
                    System.arraycopy(before[i], p, a, p + 1, k - 1 - p);
                    res[i * k + p] = a;
                }
            }
            return res;
        }

        private int readPermutation(int n, InputReader in) {
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) a[i] = in.nextInt() - 1;
            return encode(a);
        }

        private long doit(int[] p, int left, int right) {
            if (left >= right) return 0;
            int mid = (left + right) / 2;
            long res = doit(p, left, mid) + doit(p, mid + 1, right);
            int[] lhave = new int[perms.length];
            for (int i = 0; i < lhave.length; ++i) lhave[i] = i;
            int nlhave = lhave.length;
            int ninteresting = 0;
            {
                int[] rhave = lhave.clone();
                int nrhave = nlhave;
                for (int j = mid; j < right; ++j) {
                    int pj = p[j];
                    int rold = nrhave;
                    nrhave = expand(rhave, nrhave, pj);
                    if (rold != nrhave || j == mid) {
                        interesting[ninteresting++] = j;
                    }
                }
            }
            interesting[ninteresting] = right;
            long sofar = 0;
            for (int i = mid; i >= left; --i) {
                int pi = p[i];
                int old = nlhave;
                nlhave = expand(lhave, nlhave, pi);
                if (old == nlhave && i < mid) {
                    res += sofar;
                    continue;
                }
                sofar = 0;
                int[] rhave = lhave.clone();
                int nrhave = nlhave;
                for (int jj = 0; jj < ninteresting; ++jj) {
                    int pj = p[interesting[jj]];
                    nrhave = expand(rhave, nrhave, pj);
                    long rsofar = perms.length / nrhave;
                    sofar += rsofar * (interesting[jj + 1] - interesting[jj]);
                }
                res += sofar;
            }

            return res;
        }

        private int expand(int[] have, int nhave, int pi) {
            int[] pr = prod[pi];
            if (get(have, pi) != get(have, unit)) {
                for (int s = 0; s < have.length; ++s) {
                    int a = get(have, s);
                    int b = get(have, pr[s]);
                    if (a != b) {
                        have[a] = b;
                        --nhave;
                    }
                }
            }
            return nhave;
        }

        private int get(int[] have, int a) {
            int r = a;
            while (have[r] != r) r = have[r];
            int t = a;
            while (have[t] != r) {
                int n = have[t];
                have[t] = r;
                t = n;
            }
            return r;
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
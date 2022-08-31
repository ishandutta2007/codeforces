import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] p = new int[30];
        for (int i = 0; i < p.length; ++i) {
            outer: for (int j = 2;; ++j) {
                for (int k = 0; k < i; ++k) if (j % p[k] == 0) continue outer;
                p[i] = j;
                break;
            }
        }
        for (int maxp = 1; maxp <= p.length; ++maxp) {
            long[][] need = new long[maxp + 1][n + 1];
            int max = 2 * n * n;
            Arrays.fill(need[maxp], max + 1);
            need[maxp][1] = 1;
            for (int cp = maxp - 1; cp >= 0; --cp) {
                Arrays.fill(need[cp], max + 1);
                need[cp][0] = 1;
                int x = p[cp];
                int[] pow = new int[30];
                int np = 0;
                pow[np] = 1;
                while (pow[np] * x <= max) {
                    pow[np + 1] = pow[np] * x;
                    ++np;
                }
                ++np;
                for (int count = 1; count <= n; ++count) {
                    int half = count / 2;
                    int left = 0;
                    int right = max + 1;
                    while (right - left > 1) {
                        int middle = (left + right) / 2;
                        int togo = count;
                        for (int cpow = 0; cpow < np; ++cpow) {
                            int tleft = 0;
                            int tright = togo + 1;
                            while (tright - tleft > 1) {
                                int tmiddle = (tleft + tright) / 2;
                                if (need[cp + 1][tmiddle] * pow[cpow] <= middle && (cpow > 0 || tmiddle <= half)) {
                                    tleft = tmiddle;
                                } else {
                                    tright = tmiddle;
                                }
                            }
                            int take = tleft;
                            togo -= take;
                        }
                        if (togo == 0) {
                            right = middle;
                        } else {
                            left = middle;
                        }
                    }
                    need[cp][count] = right;
                    if (right == max + 1) break;
                }
            }
            int maxsol = 1;
            for (int i = 1; i <= n; ++i) if (need[0][i] <= max) maxsol = i;
            //System.out.println(maxp + " " + maxsol);
            if (need[0][n] <= max) {
                int[] res = new int[n];
                Arrays.fill(res, 1);
                buildRes(res, 0, n, need, p, maxp, 0, max);
                Arrays.sort(res);
                for (int i =0 ; i < n; ++i) {
                    if (i > 0) out.print(" ");
                    out.print(res[i]);
                }
                out.println();
                return;
            }
        }
        throw new RuntimeException();
    }

    private void buildRes(int[] res, int offset, int n, long[][] need, int[] p, int maxp, int cp, int max) {
        if (n == 0) return;
        if (cp == maxp) {
            if (n > 1) throw new RuntimeException();
            return;
        }
        int middle = (int) need[cp][n];
        int x = p[cp];
        int[] pow = new int[30];
        int np = 0;
        pow[np] = 1;
        while (pow[np] * x <= max) {
            pow[np + 1] = pow[np] * x;
            ++np;
        }
        ++np;
        int togo = n;
        int half = n / 2;
        for (int cpow = 0; cpow <= np; ++cpow) {
            int tleft = 0;
            int tright = togo + 1;
            while (tright - tleft > 1) {
                int tmiddle = (tleft + tright) / 2;
                if (need[cp + 1][tmiddle] * pow[cpow] <= middle && (cpow > 0 || tmiddle <= half)) {
                    tleft = tmiddle;
                } else {
                    tright = tmiddle;
                }
            }
            int take = tleft;
            buildRes(res, offset + n - togo, take, need, p, maxp, cp + 1, max);
            for (int i = offset + n - togo; i < offset + n - togo + take; ++i)
                res[i] *= pow[cpow];
            togo -= take;
        }
        if (togo != 0) {
            throw new RuntimeException();
        }
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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
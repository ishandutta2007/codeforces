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
        int[] d = new int[6];
        int[][] v = new int[4][4];
        int vid = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                d[vid] = in.nextInt();
                v[i][j] = v[j][i] = vid++;
            }
        }
        int[][] eq = new int[6][7];
        for (int set = 1; set < 15; set += 2) {
            for (int i = 0; i < 4; ++i) {
                for (int j = i + 1; j < 4; ++j) {
                    if (((set & (1 << i)) == 0) ^ ((set & (1 << j)) == 0))
                        eq[v[i][j]][set / 2] = 1;
                }
            }
        }
        int[] u = new int[7];
        Arrays.fill(u, -1);
        for (int i = 0; i < 6; ++i) {
            int j;
            for (j = 0; j < 7; ++j) if (u[j] < 0 && eq[i][j] != 0) {
                break;
            }
            if (j >= 7) {
                throw new RuntimeException();
            }
            u[j] = i;
            for (int ii = 0; ii < 6; ++ii)
                if (ii != i) {
                    int dd = -eq[ii][j];
                    int mby = eq[i][j];
                    for (int k = 0; k < 7; ++k)
                        eq[ii][k] = eq[ii][k] * mby + eq[i][k] * dd;
                    d[ii] = d[ii] * mby + d[i] * dd;
                }
        }
        int[] vv = new int[7];
        int bsum = Integer.MAX_VALUE;
        int[] bestvv = new int[7];
        for (int v6 = 0; v6 <= 100000; ++v6) {
            vv[6] = v6;
            boolean ok = true;
            for (int i = 0; i < 6; ++i) {
                int a = d[u[i]] - v6 * eq[u[i]][6];
                int b = eq[u[i]][i];
                if (a % b != 0) {
                    ok = false;
                    break;
                }
                vv[i] = a / b;
                if (vv[i] < 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                int sum = 0;
                for (int x : vv) sum += x;
                if (sum < bsum) {
                    bsum = sum;
                    System.arraycopy(vv, 0, bestvv, 0, 7);
                }
            }
        }
        if (bsum == Integer.MAX_VALUE) {
            out.println(-1);
        } else {
            out.println(bsum);
            for (int r = 0; r < 4; ++r) {
                int[] tmp = bestvv.clone();
                int tmpPos = 0;
                for (int i = 0; i < bsum; ++i) {
                    while (tmp[tmpPos] == 0) ++tmpPos;
                    --tmp[tmpPos];
                    if (((tmpPos * 2 + 1) & (1 << r)) != 0)
                        out.print('a');
                    else
                        out.print('b');
                }
                out.println();
            }
        }
	}
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

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
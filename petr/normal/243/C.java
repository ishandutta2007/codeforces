import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		Beetle solver = new Beetle();
		solver.solve(1, in, out);
		out.close();
	}
}

class Beetle {
    static final int[] dirdx = new int[]{-1, 1, 0, 0};
    static final int[] dirdy = new int[]{0, 0, -1, 1};
    static final int INF = (int) (1e9 + 10);

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] dir = new int[n];
        int[] by = new int[n];
        int[] allX = new int[n + 1];
        int[] allY = new int[n + 1];
        allX[0] = 0;
        allY[0] = 0;
        for (int i = 0; i < n; ++i) {
            dir[i] = "LRUD".indexOf(in.next().charAt(0));
            by[i] = in.nextInt();
            allX[i + 1] = allX[i] + by[i] * dirdx[dir[i]];
            allY[i + 1] = allY[i] + by[i] * dirdy[dir[i]];
        }
        Random random = new Random(5943871584731L + System.currentTimeMillis());
        for (int i = 0; i < allX.length; ++i) {
            int j = random.nextInt(allX.length - i);
            int tmp = allX[i];
            allX[i] = allX[j];
            allX[j] = tmp;
            tmp = allY[i];
            allY[i] = allY[j];
            allY[j] = tmp;
        }
        Arrays.sort(allX);
        int[] leftX = new int[2 * n + 5];
        int[] rightX = new int[2 * n + 5];
        int cntX = 0;
        int start = -INF;
        for (int i = 0; i < allX.length; ++i) {
            if (start < allX[i]) {
                leftX[cntX] = start;
                rightX[cntX] = allX[i] - 1;
                ++cntX;
                start = allX[i];
            }
            if (start == allX[i]) {
                leftX[cntX] = start;
                rightX[cntX] = start;
                ++cntX;
                start = allX[i] + 1;
            }
        }
        leftX[cntX] = start;
        rightX[cntX] = INF;
        ++cntX;
        Arrays.sort(allY);
        int[] leftY = new int[2 * n + 5];
        int[] rightY = new int[2 * n + 5];
        int cntY = 0;
        start = -INF;
        for (int i = 0; i < allY.length; ++i) {
            if (start < allY[i]) {
                leftY[cntY] = start;
                rightY[cntY] = allY[i] - 1;
                ++cntY;
                start = allY[i];
            }
            if (start == allY[i]) {
                leftY[cntY] = start;
                rightY[cntY] = start;
                ++cntY;
                start = allY[i] + 1;
            }
        }
        leftY[cntY] = start;
        rightY[cntY] = INF;
        ++cntY;
        boolean[] mark = new boolean[cntX * cntY];
        int ix = -1;
        for (int i = 0; i < cntX; ++i)
            if (leftX[i] == 0 && rightX[i] == 0)
                ix = i;
        int iy = -1;
        for (int i = 0; i < cntY; ++i)
            if (leftY[i] == 0 && rightY[i] == 0)
                iy = i;
        mark[ix * cntY + iy] = true;
        int cx = 0;
        int cy = 0;
        for (int i = 0; i < n; ++i) {
            int nx = cx + dirdx[dir[i]] * by[i];
            int ny = cy + dirdy[dir[i]] * by[i];
            if (nx > cx) {
                while (leftX[ix] != nx || rightX[ix] != nx) {
                    ++ix;
                    mark[ix * cntY + iy] = true;
                }
            }
            if (nx < cx) {
                while (leftX[ix] != nx || rightX[ix] != nx) {
                    --ix;
                    mark[ix * cntY + iy] = true;
                }
            }
            if (ny > cy) {
                while (leftY[iy] != ny || rightY[iy] != ny) {
                    ++iy;
                    mark[ix * cntY + iy] = true;
                }
            }
            if (ny < cy) {
                while (leftY[iy] != ny || rightY[iy] != ny) {
                    --iy;
                    mark[ix * cntY + iy] = true;
                }
            }
            cx = nx;
            cy = ny;
        }
        boolean[] killed = new boolean[cntX * cntY];
        int[] qix = new int[cntX * cntY + 10];
        int[] qiy = new int[cntX * cntY + 10];
        int qt = 0;
        int qh = 1;
        killed[0] = true;
        while (qt < qh) {
            ix = qix[qt];
            iy = qiy[qt];
            ++qt;
            for (int i = 0; i < 4; ++i) {
                int nix = ix + dirdx[i];
                int niy = iy + dirdy[i];
                if (nix < 0 || nix >= cntX || niy < 0 || niy >= cntY || mark[nix * cntY + niy] || killed[nix * cntY + niy])
                    continue;
                killed[nix * cntY + niy] = true;
                qix[qh] = nix;
                qiy[qh] = niy;
                ++qh;
            }
        }
        long res = 0;
        for (ix = 0; ix < cntX; ++ix)
            for (iy = 0; iy < cntY; ++iy) {
                if (!killed[ix * cntY + iy])
                    res += (rightX[ix] - leftX[ix] + 1) * (long) (rightY[iy] - leftY[iy] + 1);
            }
        out.println(res);
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
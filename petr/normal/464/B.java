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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static int[][] perms = new int[][]{
            new int[]{0, 1, 2},
            new int[]{0, 2, 1},
            new int[]{1, 0, 2},
            new int[]{1, 2, 0},
            new int[]{2, 0, 1},
            new int[]{2, 1, 0},
    };
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int[][] coord = new int[8][3];
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 3; ++j)
                coord[i][j] = in.nextInt();
        int[] zero = new int[3];
        for (int v1 = 1; v1 < 8; ++v1)
            for (int[] p1 : perms)
                for (int v2 = v1 + 1; v2 < 8; ++v2)
                    for (int[] p2 : perms)
                        for (int v3 = v2 + 1; v3 < 8; ++v3)
                            for (int[] p3 : perms) {
                                int[] d1 = new int[]{
                                        coord[v1][p1[0]] - coord[0][0],
                                        coord[v1][p1[1]] - coord[0][1],
                                        coord[v1][p1[2]] - coord[0][2],
                                };
                                int[] d2 = new int[]{
                                        coord[v2][p2[0]] - coord[0][0],
                                        coord[v2][p2[1]] - coord[0][1],
                                        coord[v2][p2[2]] - coord[0][2],
                                };
                                int[] d3 = new int[]{
                                        coord[v3][p3[0]] - coord[0][0],
                                        coord[v3][p3[1]] - coord[0][1],
                                        coord[v3][p3[2]] - coord[0][2],
                                };
                                if (dotprod(d1, d2) != 0) continue;
                                if (dotprod(d1, d3) != 0) continue;
                                if (dotprod(d2, d3) != 0) continue;
                                if (dotprod(d1, d1) != dotprod(d2, d2)) continue;
                                if (dotprod(d1, d1) != dotprod(d3, d3)) continue;
                                if (dotprod(d1, d1) == 0) continue;
                                int[][] need = new int[4][3];
                                fillCell(need[0], coord[0], d1, d2, zero);
                                fillCell(need[1], coord[0], d1, d3, zero);
                                fillCell(need[2], coord[0], d2, d3, zero);
                                fillCell(need[3], coord[0], d1, d2, d3);
                                int[][] got = new int[4][3];
                                int ptr = 0;
                                for (int i = 1; i < 8; ++i) if (i != v1 && i != v2 && i != v3) {
                                    got[ptr++] = coord[i].clone();
                                    Arrays.sort(got[ptr - 1]);
                                }
                                int[] which = new int[4];
                                Arrays.fill(which, -1);
                                if (matches(need, got, which, 0)) {
                                    out.println("YES");
                                    printPoint(out, coord[0], new int[]{0, 1, 2});
                                    ptr = 0;
                                    for (int i = 1; i < 8; ++i) {
                                        if (i == v1) {
                                            printPoint(out, coord[i], p1);
                                            continue;
                                        }
                                        if (i == v2) {
                                            printPoint(out, coord[i], p2);
                                            continue;
                                        }
                                        if (i == v3) {
                                            printPoint(out, coord[i], p3);
                                            continue;
                                        }
                                        printPoint(out, need[which[ptr++]], new int[]{0, 1, 2});
                                    }
                                    return;
                                }
                            }
        out.println("NO");
    }

    private boolean matches(int[][] need, int[][] got, int[] which, int at) {
        if (at == 4) return true;
        int[] tmp = need[at].clone();
        Arrays.sort(tmp);
        for (int i = 0; i < 4; ++i) if (which[i] < 0) {
            if (tmp[0] == got[i][0] && tmp[1] == got[i][1] && tmp[2] == got[i][2]) {
                which[i] = at;
                if (matches(need, got, which, at + 1)) return true;
                which[i] = -1;
            }
        }
        return false;
    }

    private void printPoint(PrintWriter out, int[] coord, int[] perm) {
        out.print(coord[perm[0]]);
        out.print(" ");
        out.print(coord[perm[1]]);
        out.print(" ");
        out.print(coord[perm[2]]);
        out.println();
    }

    private void fillCell(int[] dest, int[] a, int[] b, int[] c, int[] d) {
        dest[0] = a[0] + b[0] + c[0] + d[0];
        dest[1] = a[1] + b[1] + c[1] + d[1];
        dest[2] = a[2] + b[2] + c[2] + d[2];
    }

    private long dotprod(int[] d1, int[] d2) {
        return d1[0] * (long) d2[0] + d1[1] * (long) d2[1] + d1[2] * (long) d2[2];
    }
}

class InputReader {
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
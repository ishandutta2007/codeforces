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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    int q;
    int[] depth;
    int[][] jump;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        q = in.nextInt();
        int maxJump = q + 1;
        int p2 = 0;
        while ((1 << p2) <= maxJump) ++p2;
        depth = new int[4 + 2 * q];
        jump = new int[4 + 2 * q][p2];
        Arrays.fill(jump[0], -1);
        addChild(0, 1);
        addChild(0, 2);
        addChild(0, 3);
        int x = 1;
        int y = 2;
        int diam = 2;
        for (int i = 0; i < q; ++i) {
            int v = in.nextInt() - 1;
            addChild(v, 4 + 2 * i);
            addChild(v, 4 + 2 * i + 1);
            if (getdist(x, 4 + 2 * i) > diam) {
                ++diam;
                y = 4 + 2 * i;
            } else if (getdist(y, 4 + 2 * i) > diam) {
                ++diam;
                x = 4 + 2 * i;
            }
            out.println(diam);
        }
    }

    private int getdist(int a, int b) {
        int res = Math.abs(depth[a] - depth[b]);
        a = jumpUp(a, depth[a] - depth[b]);
        b = jumpUp(b, depth[b] - depth[a]);
        if (a == b) return res;
        int p2 = 0;
        while ((1 << p2) <= depth[a]) ++p2;
        while (p2 >= 0) {
            while ((1 << p2) > depth[a]) --p2;
            if (jump[a][p2] != jump[b][p2]) {
                res += 2 << p2;
                a = jump[a][p2];
                b = jump[b][p2];
            } else {
                --p2;
            }
        }
        return res + 2;
    }

    private int jumpUp(int x, int by) {
        int p2 = 0;
        while ((1 << p2) <= by) ++p2;
        while (by > 0) {
            while ((1 << p2) > by) --p2;
            x = jump[x][p2];
            by -= (1 << p2);
        }
        return x;
    }

    private void addChild(int a, int b) {
        depth[b] = depth[a] + 1;
        Arrays.fill(jump[b], -1);
        jump[b][0] = a;
        for (int i = 1; i < jump[b].length; ++i) {
            jump[b][i] = jump[jump[b][i - 1]][i - 1];
            if (jump[b][i] < 0) break;
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
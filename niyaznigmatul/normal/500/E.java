import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] pos = new int[n];
        int[] len = new int[n];
        for (int i = 0; i < n; i++) {
            pos[i] = in.nextInt();
            len[i] = in.nextInt();
        }
        int[] which = new int[n];
        MaxSegmentTree wTree = new MaxSegmentTree(n);
        for (int i = n - 1; i >= 0; i--) {
            int l = -1;
            int r = n;
            while (l < r - 1) {
                int mid = (l + r) >> 1;
                if (pos[mid] > pos[i] + len[i]) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            which[i] = wTree.getMax(i + 1, r);
            if (which[i] < i) which[i] = i;
            wTree.set(i, which[i]);
        }
        MaxSegmentTree hTree = new MaxSegmentTree(n);
        for (int i = 0; i < n; i++) {
            hTree.set(i, pos[i] + len[i]);
        }
        int[] need = new int[n];
        for (int i = 0; i < n; i++) {
            int to = which[i];
            if (to + 1 >= n) {
                continue;
            }
            need[i] = Math.max(0, pos[to + 1] - hTree.getMax(i, to + 1));
        }
        final int K = 20;
        int[][] pp = new int[K][n];
        int[][] w = new int[K][n];
        for (int i = 0; i < n; i++) {
            pp[0][i] = which[i] + 1;
            w[0][i] = need[i];
        }
        for (int i = 1; i < K; i++) {
            for (int v = 0; v < n; v++) {
                pp[i][v] = pp[i - 1][v] < n ? pp[i - 1][pp[i - 1][v]] : pp[i - 1][v];
                w[i][v] = w[i - 1][v] + (pp[i - 1][v] < n ? w[i - 1][pp[i - 1][v]] : 0);
            }
        }
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int left = in.nextInt() - 1;
            int right = in.nextInt() - 1;
            if (which[left] >= right) {
                out.println(0);
                continue;
            }
            int ans = 0;
            for (int j = K - 1; j >= 0; j--) {
                if (pp[j][left] >= n || which[pp[j][left]] >= right) {
                    continue;
                }
                ans += w[j][left];
                left = pp[j][left];
            }
            ans += need[left];
            out.println(ans);
        }
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

class MaxSegmentTree {
    int[] max;
    int[] maxId;
    int n;

    public MaxSegmentTree(int n) {
        this.n = Integer.highestOneBit(n) << 1;
        max = new int[this.n * 2];
        maxId = new int[this.n * 2];
        Arrays.fill(max, Integer.MIN_VALUE);
        for (int i = 0; i < n; i++) {
            maxId[i + n] = i;
        }
        for (int i = 0; i < n; i++) {
            set(i, Integer.MIN_VALUE);
        }
    }

    public void set(int x, int y) {
        x += n;
        max[x] = y;
        while (x > 1) {
            x >>= 1;
            int left = max[x << 1];
            int right = max[(x << 1) | 1];
            if (left >= right) {
                max[x] = left;
                maxId[x] = maxId[x << 1];
            } else {
                max[x] = right;
                maxId[x] = maxId[(x << 1) | 1];
            }
        }
    }

    public int getMax(int left, int right) {
        --right;
        left += n;
        right += n;
        int ret = Integer.MIN_VALUE;
        while (left <= right) {
            if ((left & 1) == 1) {
                ret = Math.max(ret, max[left]);
                left++;
            }
            if ((right & 1) == 0) {
                ret = Math.max(ret, max[right]);
                right--;
            }
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

}
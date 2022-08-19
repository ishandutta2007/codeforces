import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

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
    int[] counts;
    int[] countGeneration;
    int generation;
    int[] maxTree;
    int[] maxPos;
    int[] retMaxPos;
    int[] a;
    int[] b;
    int n;
    int k;
    int[] psums;
    long res;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        k = in.nextInt();
        a = new int[n];
        b = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            b[i] = a[i] % k;
        }
        psums = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            psums[i + 1] = (psums[i] + b[i]) % k;
        }
        maxTree = new int[4 * n + 10];
        maxPos = new int[4 * n + 10];
        retMaxPos = new int[4 * n + 10];
        initMaxTree(0, 0, n - 1);
        counts = new int[k];
        countGeneration = new int[k];
        generation = 0;
        res = 0;
        solveFresh(0, n);
        out.println(res - n);
    }

    private void initMaxTree(int root, int rl, int rr) {
        if (rl == rr) {
            maxTree[root] = a[rl];
            maxPos[root] = rl;
            return;
        }
        int rm = (rl + rr) / 2;
        initMaxTree(root * 2 + 1, rl, rm);
        initMaxTree(root * 2 + 2, rm + 1, rr);
        if (maxTree[root * 2 + 1] > maxTree[root * 2 + 2]) {
            maxTree[root] = maxTree[root * 2 + 1];
            maxPos[root] = maxPos[root * 2 + 1];
        } else {
            maxTree[root] = maxTree[root * 2 + 2];
            maxPos[root] = maxPos[root * 2 + 2];
        }
    }

    private void solveFresh(int left, int right) {
        if (left == right) return;
        ++generation;
        for (int i = left; i <= right; ++i) {
            int what = psums[i];
            if (countGeneration[what] < generation) {
                countGeneration[what] = generation;
                counts[what] = 0;
            }
            ++counts[what];
        }
        solveStale(left, right);
    }

    private void solveStale(int left, int right) {
        if (left == right) return;
        int max = getMax(0, 0, n - 1, left, right - 1);
        int maxPos = retMaxPos[0];
        if (maxPos - left >= right - maxPos - 1) {
            for (int i = maxPos + 1; i <= right; ++i) {
                --counts[psums[i]];
            }
            for (int i = maxPos + 1; i <= right; ++i) {
                int need = psums[i] - b[maxPos];
                if (need < 0) need += k;
                if (countGeneration[need] == generation) {
                    res += counts[need];
                }
            }
            solveStale(left, maxPos);
            solveFresh(maxPos + 1, right);
        } else {
            for (int i = left; i <= maxPos; ++i) {
                --counts[psums[i]];
            }
            for (int i = left; i <= maxPos; ++i) {
                int need = psums[i] + b[maxPos];
                if (need >= k) need -= k;
                if (countGeneration[need] == generation) {
                    res += counts[need];
                }
            }
            solveStale(maxPos + 1, right);
            solveFresh(left, maxPos);
        }
    }

    private int getMax(int root, int rl, int rr, int left, int right) {
        if (left > right) {
            return -1;
        }
        if (rl == left && rr == right) {
            retMaxPos[root] = maxPos[root];
            return maxTree[root];
        }
        int rm = (rl + rr) / 2;
        int leftMax = getMax(root * 2 + 1, rl, rm, left, Math.min(right, rm));
        int rightMax = getMax(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right);
        if (leftMax > rightMax) {
            retMaxPos[root] = retMaxPos[root * 2 + 1];
            return leftMax;
        } else {
            retMaxPos[root] = retMaxPos[root * 2 + 2];
            return rightMax;
        }
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
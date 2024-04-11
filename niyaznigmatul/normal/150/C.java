import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int c = in.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
        }
        double[] prob = new double[n];
        for (int i = 0; i + 1 < n; i++) {
            prob[i] = in.nextInt() * .01;
        }
        SegmentTree tree = new SegmentTree(n - 1);
        for (int i = 0; i + 1 < n; i++) {
            tree.set(i, -.5 * (x[i + 1] - x[i]) + prob[i] * c);
        }
        double answer = 0;
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            double profit = tree.getMin(a, b);
            profit = -profit;
            answer += profit;
        }
        out.println(answer);
    }

    static class SegmentTree {
        double[] sum;
        double[] min;
        double[] pref;
        double[] suf;
        int n;

        SegmentTree(int n) {
            this.n = Integer.highestOneBit(n) << 1;
            sum = new double[this.n << 1];
            min = new double[this.n << 1];
            pref = new double[this.n << 1];
            suf = new double[this.n << 1];
            answer = new double[4];
        }

        void set(int x, double v) {
            set(1, 0, n, x, v);
        }

        double getMin(int left, int right) {
            return getMin(1, 0, n, left, right);
        }

        double[] answer;    // min, pref, suf, sum

        double getMin(int node, int left, int right, int l, int r) {
            if (r <= left || right <= l) {
                Arrays.fill(answer, Double.POSITIVE_INFINITY);
                answer[3] = 0;
                return Double.POSITIVE_INFINITY;
            }
            if (l <= left && right <= r) {
                answer[0] = min[node];
                answer[1] = pref[node];
                answer[2] = suf[node];
                answer[3] = sum[node];
                return answer[0];
            }
            int mid = left + right >> 1;
            getMin(node * 2, left, mid, l, r);
            double min1 = answer[0];
            double pref1 = answer[1];
            double suf1 = answer[2];
            double sum1 = answer[3];
            getMin(node * 2 + 1, mid, right, l, r);
            double min2 = answer[0];
            double pref2 = answer[1];
            double suf2 = answer[2];
            double sum2 = answer[3];
            answer[0] = Math.min(Math.min(min1, min2), suf1 + pref2);
            answer[1] = Math.min(pref1, sum1 + pref2);
            answer[2] = Math.min(suf2, sum2 + suf1);
            answer[3] = sum1 + sum2;
            return answer[0];
        }

        void set(int node, int left, int right, int x, double v) {
            if (left == right - 1) {
                sum[node] = v;
                pref[node] = Math.min(v, 0);
                suf[node] = Math.min(v, 0);
                min[node] = Math.min(v, 0);
                return;
            }
            int mid = left + right >> 1;
            if (x < mid) {
                set(node * 2, left, mid, x, v);
            } else {
                set(node * 2 + 1, mid, right, x, v);
            }
            up(node);
        }

        void up(int node) {
            sum[node] = sum[node * 2] + sum[node * 2 + 1];
            pref[node] = Math.min(pref[node * 2], sum[node * 2] + pref[node * 2 + 1]);
            suf[node] = Math.min(suf[node * 2 + 1], sum[node * 2 + 1] + suf[node * 2]);
            min[node] = Math.min(Math.min(min[node * 2], min[node * 2 + 1]), suf[node * 2] + pref[node * 2 + 1]);
        }
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    IOException happened;

    public FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                String line = br.readLine();
                st = new StringTokenizer(line);
            } catch (IOException e) {
                happened = e;
                return null;
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
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
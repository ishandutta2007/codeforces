import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static class BadArea {
        int lmin;
        int lmax;
        int rmin;
        int rmax;
        BadArea nextByLmin;
        BadArea nextByLmax;
    }
    
    static class SegmentTree {
        int[] delta;
        int n;
        int[][] cnt;

        public SegmentTree(int n) {
            this.n = n;
            delta = new int[4 * n + 10];
            cnt = new int[4][4 * n + 10];
            initCnts(0, 0, n - 1);
        }

        private void initCnts(int root, int rl, int rr) {
            if (rl != rr) {
                int rm = (rl + rr) / 2;
                initCnts(root * 2 + 1, rl, rm);
                initCnts(root * 2 + 2, rm + 1, rr);
            }
            updateCnts(root, rl, rr);
        }

        public void update(int left, int right, int by) {
            internalUpdate(0, 0, n - 1, left, right, by);
        }

        private void internalUpdate(int root, int rl, int rr, int left, int right, int by) {
            if (left > right) return;
            if (rl == left && rr == right) {
                delta[root] += by;
                updateCnts(root, rl, rr);
            } else {
                int rm = (rl + rr) / 2;
                internalUpdate(root * 2 + 1, rl, rm, left, Math.min(right, rm), by);
                internalUpdate(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right, by);
                updateCnts(root, rl, rr);
            }
        }

        private void updateCnts(int root, int rl, int rr) {
            if (delta[root] < 0) throw new RuntimeException();
            for (int i = 0; i < 4; ++i) {
                cnt[i][root] = 0;
            }
            if (rl == rr) {
                ++cnt[Math.min(3, delta[root])][root];
            } else {
                for (int i = 0; i < 4; ++i) {
                    cnt[Math.min(3, i + delta[root])][root] += cnt[i][root * 2 + 1] + cnt[i][root * 2 + 2];
                }
            }
        }

        public int getAnswer(int left, int right) {
            return internalGetAtMost(0, 0, n - 1, left, right, 2);
        }

        private int internalGetAtMost(int root, int rl, int rr, int left, int right, int most) {
            if (left > right || most < 0) return 0;
            if (rl == left && rr == right) {
                int res = 0;
                for (int i = 0; i <= most; ++i) {
                    res += cnt[i][root];
                }
                return res;
            } else {
                int rm = (rl + rr) / 2;
                return
                        internalGetAtMost(root * 2 + 1, rl, rm, left, Math.min(right, rm), most - delta[root]) +
                        internalGetAtMost(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right, most - delta[root]);
            }
        }
    }
    
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) p[i] = in.nextInt() - 1;
        BadArea[] areas = new BadArea[n];
        for (int i = 0; i < n; ++i) {
            areas[i] = new BadArea();
            int prev;
            if (i == 0) prev = -1; else prev = p[i - 1];
            int cur = p[i];
            if (cur > prev) {
                areas[i].lmin = prev + 1;
                areas[i].lmax = cur;
                areas[i].rmin = cur;
                areas[i].rmax = n - 1;
            } else {
                areas[i].lmin = 0;
                areas[i].lmax = cur;
                areas[i].rmin = cur;
                areas[i].rmax = prev - 1;
            }
        }
        BadArea[] firstByLmin = new BadArea[n];
        BadArea[] firstByLmax = new BadArea[n];
        for (BadArea a : areas) {
            if (a.lmin > a.lmax || a.rmin > a.rmax) continue;
            a.nextByLmin = firstByLmin[a.lmin];
            firstByLmin[a.lmin] = a;
            a.nextByLmax = firstByLmax[a.lmax];
            firstByLmax[a.lmax] = a;
        }
        SegmentTree s = new SegmentTree(n);
        long res = 0;
        for (int left = 0; left < n; ++left) {
            BadArea a = firstByLmin[left];
            while (a != null) {
                s.update(a.rmin, a.rmax, 1);
                a = a.nextByLmin;
            }
            res += s.getAnswer(left + 1, n - 1);
            a = firstByLmax[left];
            while (a != null) {
                s.update(a.rmin, a.rmax, -1);
                a = a.nextByLmax;
            }
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
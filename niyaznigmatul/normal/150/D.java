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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int len = in.nextInt();
        int[] a = new int[len];
        for (int i = 0; i < len; i++) {
            a[i] = in.nextInt();
        }
        char[] c = in.next().toCharArray();
        out.println(solveStupid(a, c));
    }

    static int[][] dpCostAll;
    static int[][][] dpLeavePalindrom;
    static int[] cost;
    static char[] str;
    static boolean[][] isPalindrom;

    static int costAll(int left, int right) {
        if (left > right) {
            return -1;
        }
        if (left == right) {
            return 0;
        }
        if (dpCostAll[left][right] != Integer.MIN_VALUE) {
            return dpCostAll[left][right];
        }
        int ret = -1;
        for (int len = 1; left + len <= right; len++) {
            if (cost[len] >= 0) {
                int got = leavePalindrom(left, right, len);
                if (got < 0) {
                    continue;
                }
                ret = Math.max(ret, got + cost[len]);
            }
        }
        for (int mid = left + 1; mid < right; mid++) {
            int got1 = costAll(left, mid);
            int got2 = costAll(mid, right);
            if (got1 < 0 || got2 < 0) {
                continue;
            }
            ret = Math.max(ret, got1 + got2);
        }
        return dpCostAll[left][right] = ret;
    }

    static int leavePalindrom(int left, int right, int len) {
        if (len == 0) {
            return costAll(left, right);
        }
        if (left >= right) {
            return -1;
        }
        if (dpLeavePalindrom[left][right][len] != Integer.MIN_VALUE) {
            return dpLeavePalindrom[left][right][len];
        }
        if (len == left - right) {
            return dpLeavePalindrom[left][right][len] = (isPalindrom[left][right] ? 0 : -1);
        }
        if (len == 1) {
            int ret = -1;
            for (int i = left; i < right; i++) {
                int got1 = costAll(left, i);
                int got2 = costAll(i + 1, right);
                if (got1 < 0 || got2 < 0) {
                    continue;
                }
                ret = Math.max(ret, got1 + got2);
            }
            return dpLeavePalindrom[left][right][len] = ret;
        }
        int ret = -1;
        for (int newLeft = left + 1; newLeft < right; newLeft++) {
            int got1 = costAll(left, newLeft);
            if (got1 < 0) {
                continue;
            }
            int got2 = leavePalindrom(newLeft, right, len);
            if (got1 < 0 || got2 < 0) {
                continue;
            }
            ret = Math.max(ret, got1 + got2);
        }
        for (int newRight = right - 1; newRight > left; newRight--) {
            int got1 = leavePalindrom(left, newRight, len);
            if (got1 < 0) {
                continue;
            }
            int got2 = costAll(newRight, right);
            if (got2 < 0) {
                continue;
            }
            ret = Math.max(ret, got1 + got2);
        }
        if (str[left] == str[right - 1]) {
            ret = Math.max(ret, leavePalindrom(left + 1, right - 1, len - 2));
        }
        return dpLeavePalindrom[left][right][len] = ret;
    }

    static int solveStupid(int[] a, char[] c) {
        str = c.clone();
        int n = a.length;
        cost = new int[n + 1];
        cost[0] = -1;
        for (int i = 1; i <= n; i++) {
            cost[i] = a[i - 1];
        }
        dpCostAll = new int[n][n + 1];
        dpLeavePalindrom = new int[n][n + 1][n + 1];
        for (int[] d : dpCostAll) {
            Arrays.fill(d, Integer.MIN_VALUE);
        }
        for (int[][] d1 : dpLeavePalindrom) {
            for (int[] d : d1) {
                Arrays.fill(d, Integer.MIN_VALUE);
            }
        }
        isPalindrom = new boolean[n][n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                boolean is = true;
                for (int k = 0; k < j - i; k++) {
                    if (str[i + k] != str[j - k - 1]) {
                        is = false;
                        break;
                    }
                }
                isPalindrom[i][j] = is;
            }
        }
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (int j = 0; j < i; j++) {
                int got = costAll(j, i);
                if (got < 0) {
                    continue;
                }
                dp[i] = Math.max(dp[i], dp[j] + got);
            }
        }
        return dp[n];
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
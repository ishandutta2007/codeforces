import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int goal = in.nextInt();
        int n = in.nextInt();
        Segment[] a = new Segment[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Segment(in.nextInt(), in.nextInt());
        }
        Arrays.sort(a, new Comparator<Segment>() {
            public int compare(Segment o1, Segment o2) {
                return o1.b - o2.b;
            }
        });
        final int MOD = 1000000007;
        int[] dp = new int[n + 1];
        dp[0] = 1;
        int answer = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[i].b == a[j].b) {
                ++j;
            }
            for (int k = i; k < j; k++) {
                int left = -1;
                int right = i;
                while (left < right - 1) {
                    int mid = left + right >> 1;
                    if (a[mid].b < a[k].a) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                }
                dp[k + 1] = dp[k];
                int add = dp[i];
                if (a[k].a > 0) {
                    add -= dp[left + 1];
                }
                if (add < 0) {
                    add += MOD;
                }
                if (a[k].b == goal) {
                    answer += add;
                    if (answer >= MOD) {
                        answer -= MOD;
                    }
                }
                dp[k + 1] += add;
                if (dp[k + 1] >= MOD) {
                    dp[k + 1] -= MOD;
                }
            }
            i = j;
        }
        out.println(answer);
    }

    static class Segment {
        int a;
        int b;

        Segment(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
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
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
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
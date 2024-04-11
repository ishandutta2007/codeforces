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
    static final int MAX = (int) (1e5);
    static final long MODULO = (long) (1e9 + 7);

    int[] nums;
    int[] divs;
    int nc;
    int c;

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] cnt = new int[MAX + 1];
        for (int i = 0; i < n; ++i)
            ++cnt[in.nextInt()];
        for (int i = 1; i <= MAX; ++i)
            cnt[i] += cnt[i - 1];
        long[] res = new long[MAX + 1];
        int[] div = new int[MAX + 1];
        for (int i = 2; i * i <= MAX; ++i) if (div[i] == 0)
            for (int j = i * i; j <= MAX; j += i)
                if (div[j] == 0) div[j] = i;
        divs = new int[100];
        nums = new int[10000];
        long sum = 0;
        for (int what = 1; what <= MAX; ++what) {
            c = 0;
            int tmp = what;
            while (tmp > 1) {
                int by = div[tmp];
                if (by == 0) by = tmp;
                divs[c++] = by;
                tmp /= by;
            }
            nc = 0;
            Arrays.sort(divs, 0, c);
            buildAll(0, 1);
            Arrays.sort(nums, 0, nc);
            int pcnt = 0;
            long r = 1;
            for (int i = 0; i < nc; ++i) {
                int ccnt = cnt[nums[i] - 1];
                int delta = ccnt - pcnt;
                r = r * pw(i, delta) % MODULO;
                pcnt = ccnt;
            }
            r = r * (pw(nc, n - pcnt) - pw(nc - 1, n - pcnt) + MODULO) % MODULO;
            res[what] = r;
            /*nc = 0;
            for (int i = 0; i < c; ++i) {
                if (i == 0 || divs[i] != divs[i - 1]) {
                    divs[nc++] = divs[i];
                }
            }
            for (int mask = 1; mask < (1 << nc); ++mask) {
                int by = 1;
                int rem = what;
                for (int i = 0; i < nc; ++i)
                    if ((mask & (1 << i)) != 0) {
                        by *= -1;
                        rem /= divs[i];
                    }
                r = ((r + res[rem] * by) % MODULO + MODULO) % MODULO;
            } */
            sum = ((sum + r) % MODULO);
        }
        out.println(sum);
    }

    private long pw(long a, int k) {
        if (k == 0) return 1;
        if (k % 2 == 0) return pw(a * a % MODULO, k / 2);
        return a * pw(a, k - 1) % MODULO;
    }

    private void buildAll(int at, int prod) {
        if (at == c) {
            nums[nc++] = prod;
            return;
        }
        int right = at;
        while (right < c && divs[right] == divs[at]) ++right;
        for (int pw = 0; pw <= right - at; ++pw) {
            buildAll(right, prod);
            if (pw < right - at) prod *= divs[at];
        }
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

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
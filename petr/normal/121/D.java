import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class HappySegments implements Runnable {
    static final long INF = 3 * (long) (1e9) * (long) (1e9);

    private void solve() throws IOException {
        long[] happy = new long[(1 << 19) - 2];
        int pos = 0;
        for (int len = 1; len <= 18; ++len) {
            for (int mask = 0; mask < (1 << len); ++mask) {
                long num = 0;
                for (int i = 0; i < len; ++i)
                    if ((mask & (1 << (len - 1 - i))) != 0) num = num * 10 + 7; else num = num * 10 + 4;
                happy[pos++] = num;
            }
        }
        if (pos != happy.length) throw new RuntimeException();
        int n = nextInt();
        long k = nextLong();
        long[] l = new long[n];
        long[] r = new long[n];
        long minLen = INF;
        for (int i = 0; i < n; ++i) {
            l[i] = nextLong();
            r[i] = nextLong();
            minLen = Math.min(minLen, r[i] - l[i] + 1);
        }
        Random random = new Random(49731795431L + System.currentTimeMillis());
        for (int i = 0; i < n; ++i) {
            int j = random.nextInt(n - i) + i;
            long tmp = l[i];
            l[i] = l[j];
            l[j] = tmp;
            tmp = r[i];
            r[i] = r[j];
            r[j] = tmp;
        }
        Arrays.sort(l);
        Arrays.sort(r);
        long[] leftCost = new long[happy.length];
        long[] rightCost = new long[happy.length];
        long curPos = happy[0];
        double curCost = 0.0;
        long curCostLong = 0;
        int firstGreater = n;
        for (int i = 0; i < n; ++i) {
            if (l[i] > curPos) {
                long delta = l[i] - curPos;
                curCost += delta;
                curCostLong += delta;
                firstGreater = Math.min(firstGreater, i);
            }
        }
        for (int i = 0; i < happy.length; ++i) {
            long cur = happy[i];
            while (firstGreater < n && l[firstGreater] <= cur) {
                long delta = l[firstGreater] - curPos;
                curCost -= delta * (double) (n - firstGreater);
                curCostLong -= delta * (n - firstGreater);
                curPos = l[firstGreater];
                ++firstGreater;
            }
            {
                long delta = cur - curPos;
                curCost -= delta * (double) (n - firstGreater);
                curCostLong -= delta * (n - firstGreater);
                curPos = cur;
            }
            if (curCost > 2e18)
                leftCost[i] = INF;
            else
                leftCost[i] = curCostLong;
        }
        firstGreater = -1;
        curCost = 0;
        curCostLong = 0;
        curPos = happy[happy.length - 1];
        for (int i = 0; i < n; ++i) {
            if (r[i] < curPos) {
                long delta = curPos - r[i];
                curCost += delta;
                curCostLong += delta;
                firstGreater = Math.max(firstGreater, i);
            }
        }
        for (int i = happy.length - 1; i >= 0; --i) {
            long cur = happy[i];
            while (firstGreater >= 0 && r[firstGreater] >= cur) {
                long delta = curPos - r[firstGreater];
                curCost -= delta * (double) (firstGreater + 1);
                curCostLong -= delta * (firstGreater + 1);
                curPos = r[firstGreater];
                --firstGreater;
            }
            {
                long delta = curPos - cur;
                curCost -= delta * (double) (firstGreater + 1);
                curCostLong -= delta * (firstGreater + 1);
                curPos = cur;
            }
            if (curCost > 2e18)
                rightCost[i] = INF;
            else
                rightCost[i] = curCostLong;
        }
        int j = 0;
        int res = 0;
        for (int i = 0; i < happy.length; ++i) {
            if (j < i)
                j = i;
            while (j < happy.length && leftCost[i] + rightCost[j] <= k && happy[j] - happy[i] + 1 <= minLen) {
                res = Math.max(res, j - i + 1);
                ++j;
            }
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new HappySegments().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
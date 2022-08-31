import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
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
    static class Good {
        int c;
        int h;
        int t;
    }

    static class Query {
        int a;
        int b;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int p = in.nextInt();
        Good[] goods = new Good[n];
        for (int i = 0; i < n; ++i) {
            goods[i] = new Good();
            goods[i].c = in.nextInt();
            goods[i].h = in.nextInt();
            goods[i].t = in.nextInt() + p;
        }
        Arrays.sort(goods, new Comparator<Good>() {
            public int compare(Good o1, Good o2) {
                return o1.t - o2.t;
            }
        });
        int q = in.nextInt();
        Query[] queries = new Query[q];
        for (int i = 0; i < q; ++i) {
            queries[i] = new Query();
            queries[i].a = in.nextInt() + p;
            queries[i].b = in.nextInt();
        }

        int maxMoney = 0;
        for (Query qq : queries)
            maxMoney = Math.max(maxMoney, qq.b);
        ++maxMoney;

        int[][] prefix = new int[n][maxMoney];
        int[][] suffix = new int[n][maxMoney];

        for (int i = 0; i < n; ++i) {
            Good g = goods[i];
            boolean newBucket = (i == 0 || goods[i - 1].t / p != goods[i].t / p);
            if (!newBucket) {
                System.arraycopy(prefix[i - 1], 0, prefix[i], 0, maxMoney);
            }
            for (int j = maxMoney - 1; j >= g.c; --j) {
                prefix[i][j] = Math.max(prefix[i][j], prefix[i][j - g.c] + g.h);
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            Good g = goods[i];
            boolean newBucket = (i == n - 1 || goods[i + 1].t / p != goods[i].t / p);
            if (!newBucket) {
                System.arraycopy(suffix[i + 1], 0, suffix[i], 0, maxMoney);
            }
            for (int j = maxMoney - 1; j >= g.c; --j) {
                suffix[i][j] = Math.max(suffix[i][j], suffix[i][j - g.c] + g.h);
            }
        }

        for (Query qq : queries) {
            int leftT = qq.a - p + 1;
            int rightT = qq.a;

            int left = -1;
            int right = n;
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (goods[middle].t >= leftT) {
                    right = middle;
                } else {
                    left = middle;
                }
            }
            int leftInd = right;
            left = -1;
            right = n;
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (goods[middle].t <= rightT) {
                    left = middle;
                } else {
                    right = middle;
                }
            }
            int rightInd = left;
            if (leftInd > rightInd) {
                out.println(0);
                continue;
            }
            if (goods[leftInd].t / p == rightT / p) {
                out.println(prefix[rightInd][qq.b]);
                continue;
            }
            if (goods[rightInd].t / p == leftT / p) {
                out.println(suffix[leftInd][qq.b]);
                continue;
            }
            int res = 0;
            int[] pre = prefix[rightInd];
            int[] suf = suffix[leftInd];
            for (int lm = 0; lm <= qq.b; ++lm) {
                res = Math.max(res, pre[lm] + suf[qq.b - lm]);
            }
            out.println(res);
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class BigArray implements Runnable {
    static Random random = new Random(493714315351L);

    private void solve() throws IOException {
        int n = nextInt();
        int t = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = nextInt();
        int[] b = a.clone();
        Arrays.sort(b);
        int[] index = new int[1000001];
        Arrays.fill(index, -1);
        int last = 0;
        for (int i = 0; i < b.length; ++i)
            if (i == 0 || b[i] != b[i - 1])
                index[b[i]] = last++;
        int[] what = new int[last];
        for (int i = 0; i < index.length; ++i)
            if (index[i] >= 0)
                what[index[i]] = i;
        for (int i = 0; i < n; ++i) a[i] = index[a[i]];
        int block = (int) Math.sqrt(n);
        int numPivot = (n - 1) / block + 1;
        int[][] first = new int[numPivot][numPivot];
        for (int i = 0; i < numPivot; ++i)
            Arrays.fill(first[i], -1);
        int[] left = new int[t];
        int[] right = new int[t];
        int[] nextSame = new int[t];
        long[] answer = new long[t];
        for (int i = 0; i < t; ++i) {
            left[i] = nextInt() - 1;
            right[i] = nextInt();
            int lb = left[i] / block;
            int rb = (right[i] - 1) / block;
            nextSame[i] = first[lb][rb];
            first[lb][rb] = i;
        }
        int[] cnt = new int[last];
        for (int leftPivot = 0; leftPivot < numPivot; ++leftPivot) {
            Arrays.fill(cnt, 0);
            int at = leftPivot * block;
            int start = at;
            long curAnswer = 0;
            for (int rightPivot = leftPivot; rightPivot < numPivot; ++rightPivot) {
                int cPtr = first[leftPivot][rightPivot];
                while (cPtr >= 0) {
                    answer[cPtr] = calculate(curAnswer, cnt, a, what, start, at, left[cPtr], right[cPtr]);
                    cPtr = nextSame[cPtr];
                }
                if (rightPivot + 1 < numPivot) {
                    for (int i = 0; i < block; ++i) {
                        int cur = a[at];
                        ++at;
                        curAnswer += what[cur] * (2 * (cnt[cur]++) + 1);
                    }
                }
            }
        }
        for (int req = 0; req < t; ++req) {
            writer.println(answer[req]);
        }
    }

    private long calculate(long curAnswer, int[] cnt, int[] a, int[] what, int haveLeft, int haveRight, int needLeft, int needRight) {
        for (int at = haveRight; at < needRight; ++at) {
            int cur = a[at];
            curAnswer += what[cur] * (2 * (cnt[cur]++) + 1);
        }
        for (int at = haveLeft; at < needLeft; ++at) {
            int cur = a[at];
            curAnswer -= what[cur] * (2 * (--cnt[cur]) + 1);
        }
        for (int at = haveRight; at < needRight; ++at) {
            int cur = a[at];
            --cnt[cur];
        }
        for (int at = haveLeft; at < needLeft; ++at) {
            int cur = a[at];
            ++cnt[cur];
        }
        return curAnswer;
    }

    public static void main(String[] args) {
        new BigArray().run();
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
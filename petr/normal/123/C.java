import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Parens implements Runnable {
    static final long INF = 2 * (long) 1e9 * (long) 1e9;

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        long k = nextLong();
        int[] pri = new int[n * m];
        for (int i = 0; i < n * m; ++i) pri[i] = nextInt();
        final int[] minPri = new int[n + m - 1];
        Arrays.fill(minPri, 1000000);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                minPri[i + j] = Math.min(minPri[i + j], pri[i * m + j]);
        Integer[] perm = new Integer[n + m - 1];
        for (int i = 0; i < perm.length; ++i) perm[i] = i;
        Arrays.sort(perm, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return minPri[a] - minPri[b];
            }
        });
        char[] res = new char[n + m - 1];
        for (int pi = 0; pi < n + m - 1; ++pi) {
            int pos = perm[pi];
            res[pos] = '(';
            long am = count(res);
            if (am < k) {
                k -= am;
                res[pos] = ')';
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                writer.print(res[i + j]);
            }
            writer.println();
        }
    }

    private long count(char[] res) {
        long[] num = new long[res.length + 1];
        long[] nnum = new long[res.length + 1];
        num[0] = 1;
        for (int pos = 0; pos < res.length; ++pos) {
            Arrays.fill(nnum, 0);
            if (res[pos] == '(') {
                for (int i = 0; i < res.length; ++i)
                    nnum[i + 1] += num[i];
            } else if (res[pos] == ')') {
                for (int i = 0; i < res.length; ++i)
                    nnum[i] += num[i + 1];
            } else {
                for (int i = 0; i < res.length; ++i) {
                    nnum[i + 1] += num[i];
                    nnum[i] += num[i + 1];
                }
            }
            for (int i = 0; i <= res.length; ++i)
                if (nnum[i] >= INF) nnum[i] = INF;
            long[] tmp = num;
            num = nnum;
            nnum = tmp;
        }
        return num[0];
    }

    public static void main(String[] args) {
        new Parens().run();
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Roots implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        long res = 0;
        int[] left = new int[n];
        int[] right = new int[n];
        int until = 0;
        int delta = 0;
        int globalLeft = 0;
        for (int b = 1; b <= n; ++b) {
            delta += b + b - 1;
            while (delta > m) {
                ++until;
                delta -= until + until - 1;
            }
            left[b - 1] = -b - b + 1;
            right[b - 1] = -b - until;
            globalLeft = Math.min(globalLeft, -b + until);
            if (until > 0) {
                res += (m - (b - until)) * 2;
            } else {
                res += (b * b - (b - until)) * 2;
            }
        }
        boolean gotGlobal = false;
        int curRight = Integer.MIN_VALUE / 2;
        for (int i = n - 1; i >= 0; --i) {
            if (!gotGlobal && left[i] >= globalLeft) {
                res += Math.max(0, (-1) - Math.max(curRight, globalLeft - 1));
                curRight = Math.max(curRight, -1);
                gotGlobal = true;
            }
            res += Math.max(0, right[i] - Math.max(curRight, left[i] - 1));
            curRight = Math.max(curRight, right[i]);
        }
        if (!gotGlobal) {
            res += Math.max(0, (-1) - Math.max(curRight, globalLeft - 1));
            curRight = Math.max(curRight, -1);
            gotGlobal = true;
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new Roots().run();
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
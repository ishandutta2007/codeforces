import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class HappyPermutation implements Runnable {
    private void solve() throws IOException {
        List<Long> happy = new ArrayList<Long>();
        for (int len = 1; len <= 10; ++len) {
            for (int mask = 0; mask < (1 << len); ++mask) {
                long num = 0;
                for (int i = 0; i < len; ++i)
                    if ((mask & (1 << i)) != 0) num = num * 10 + 4; else num = num * 10 + 7;
                happy.add(num);
            }
        }
        Collections.sort(happy);
        long[] fact = new long[20];
        fact[0] = 1;
        for (int i = 1; i < 20; ++i) {
            fact[i] = i * fact[i - 1];
        }
        long n = nextLong();
        long k = nextLong() - 1;
        if (n < 20 && (k >= fact[(int) n])) {
            writer.println(-1);
            return;
        }
        long start = 1;
        long res = 0;
        List<Long> remaining = new ArrayList<Long>();
        if (n > 20) {
            start = n - 19;
            res += lowerBound(happy, start);
        }
        for (long pos = start; pos <= n; ++pos) {
            remaining.add(pos);
        }
        for (long pos = start; pos <= n; ++pos) {
            long remFact = fact[(int) (n - pos)];
            int index = (int) (k / remFact);
            k -= index * remFact;
            long what = remaining.get(index);
            if (isHappy(happy, pos) && isHappy(happy, what)) {
                ++res;
            }
            remaining.remove(index);
        }
        writer.println(res);
    }

    private boolean isHappy(List<Long> happy, long what) {
        return happy.get(lowerBound(happy, what)) == what;
    }

    int lowerBound(List<Long> happy, long what) {
        int left = -1;
        int right = happy.size();
        while (right - left > 1) {
            int middle = (left + right)/ 2;
            if (happy.get(middle) < what)
                left = middle;
            else
                right = middle;
        }
        return right;
    }

    public static void main(String[] args) {
        new HappyPermutation().run();
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
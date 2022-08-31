import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class HappySum implements Runnable {
    private void solve() throws IOException {
        List<Long> happy = new ArrayList<Long>();
        happy.add(0L);
        for (int len = 1; len <= 10; ++len) {
            for (int mask = 0; mask < (1 << len); ++mask) {
                long num = 0;
                for (int i = 0; i < len; ++i)
                    if ((mask & (1 << i)) != 0) num = num * 10 + 4; else num = num * 10 + 7;
                happy.add(num);
            }
        }
        Collections.sort(happy);
        long res = 0;
        long l = nextLong();
        long r = nextLong();
        for (int i = 0; i + 1 < happy.size(); ++i) {
            long cl = happy.get(i) + 1;
            long cr = happy.get(i + 1);
            cl = Math.max(cl, l);
            cr = Math.min(cr, r);
            if (cl <= cr)
                res += (cr - cl + 1) * happy.get(i + 1);
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new HappySum().run();
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
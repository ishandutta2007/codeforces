import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Min implements Runnable {
    private void solve() throws IOException {
        List<Long> a = new ArrayList<Long>();
        for (int i =0 ; i < 4; ++i) a.add(nextLong());
        List<Character> op = new ArrayList<Character>();
        for (int i = 0; i < 3; ++i) op.add(nextToken().charAt(0));
        writer.println(getMin(a, op));
    }

    private long getMin(List<Long> a, List<Character> op) {
        if (op.isEmpty())
            return a.get(0);
        long ret = Long.MAX_VALUE;
        for (int i = 0; i < a.size(); ++i)
            for (int j = i + 1; j < a.size(); ++j) {
                List<Long> b = new ArrayList<Long>(a);
                b.remove(j);
                b.remove(i);
                long res;
                if (op.get(0) == '+')
                    res = a.get(i) + a.get(j);
                else
                    res = a.get(i) * a.get(j);
                b.add(res);
                List<Character> or = new ArrayList<Character>(op);
                or.remove(0);
                ret = Math.min(ret, getMin(b, or));
            }
        return ret;
    }

    public static void main(String[] args) {
        new Min().run();
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
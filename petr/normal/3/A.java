import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Chess implements Runnable {
    private void solve() throws IOException {
        String p1 = nextToken();
        String p2 = nextToken();
        List<String> res = new ArrayList<String>();
        while (!p1.equals(p2)) {
            char c1 = p1.charAt(0);
            char c2 = p2.charAt(0);
            String cur = "";
            if (c1 != c2) {
                if (c1 < c2) {
                    ++c1;
                    cur += "R";
                } else if (c1 > c2) {
                    --c1;
                    cur += "L";
                }
            }
            char d1 = p1.charAt(1);
            char d2 = p2.charAt(1);
            if (d1 != d2) {
                if (d1 < d2) {
                    ++d1;
                    cur += "U";
                } else if (d1 > d2) {
                    --d1;
                    cur += "D";
                }
            }
            res.add(cur);
            p1 = c1 + "" + d1;
        }
        writer.println(res.size());
        for (String x : res)
            writer.println(x);
    }


    public static void main(String[] args) {
        new Chess().run();
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
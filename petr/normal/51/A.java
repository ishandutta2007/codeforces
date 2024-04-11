import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Amulets implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        Set<String> res = new HashSet<String>();
        for (int i = 0; i < n; ++i) {
            if (i > 0) nextToken();
            String s = nextToken();
            String u = nextToken();
            s += u.charAt(1);
            s += u.charAt(0);
            String t = s;
            for (int j = 1; j < 4; ++j) {
                String cur = s.substring(j) + s.substring(0, j);
                if (cur.compareTo(t) < 0)
                    t = cur;
            }
            res.add(t);
        }
        writer.println(res.size());
    }

    public static void main(String[] args) {
        new Amulets().run();
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
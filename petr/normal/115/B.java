import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Plants implements Runnable {
    private void solve() throws IOException {
        int height = nextInt();
        int width = nextInt();
        String[] field = new String[height];
        for (int r = 0; r < height; ++r) field[r] = nextToken();
        while (height > 0) {
            boolean ok = true;
            for (int c = 0; c < width; ++c)
                if (field[height - 1].charAt(c) == 'W') {
                    ok = false;
                    break;
                }
            if (ok) {
                --height;
            } else {
                break;
            }
        }
        int res = 0;
        int c = 0;
        for (int r = 0; r < height; ++r) {
            int dir = (r % 2 == 0 ? 1 : -1);
            int mx = 0;
            for (int cc = 0; cc < width; ++cc) {
                if (field[r].charAt(cc) == 'W' || (r + 1 < height && field[r + 1].charAt(cc) == 'W')) {
                    int cur = (cc - c) / dir;
                    mx = Math.max(mx, cur);
                }
            }
            res += mx;
            c += mx * dir;
            if (r + 1 < height) ++res;
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new Plants().run();
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
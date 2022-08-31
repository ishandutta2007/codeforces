import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Cows implements Runnable {
    static class Cow implements Comparable<Cow> {
        int x;
        int y;

        public int compareTo(Cow o) {
            return x - o.x;
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        Cow[] cow = new Cow[n];
        int miny = Integer.MAX_VALUE / 2;
        int maxy = Integer.MIN_VALUE / 2;
        int minx = Integer.MAX_VALUE / 2;
        int maxx = Integer.MIN_VALUE / 2;
        for (int i = 0; i < n; ++i) {
            cow[i] = new Cow();
            cow[i].x = nextInt();
            cow[i].y = nextInt();
            miny = Math.min(miny, cow[i].y);
            maxy = Math.max(maxy, cow[i].y);
            minx = Math.min(minx, cow[i].x);
            maxx = Math.min(maxx, cow[i].x);
        }
        --miny;
        ++maxy;
        --minx;
        ++maxx;
        int[] d = new int[4];
        for (int di = 0; di < 4; ++di) {
            int sx = (di / 2) == 0 ? 1 : -1;
            int sy = (di % 2) == 0 ? 1 : -1;
            d[di] = Integer.MAX_VALUE / 2;
            for (Cow c : cow) {
                int sum = 0;
                if (sx > 0)
                    sum += c.x - minx;
                else
                    sum += maxx - c.x;
                if (sy > 0)
                    sum += c.y - miny;
                else
                    sum += maxy - c.y;
                d[di] = Math.min(d[di], sum);
            }
        }
        int res = (maxx - minx) * 2 + (maxy - miny) * 2;
        for (int x : d) res -= (x - 1);
        writer.println(res);
    }

    public static void main(String[] args) {
        new Cows().run();
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
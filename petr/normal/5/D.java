import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Berland implements Runnable {
    private void solve() throws IOException {
        double a = nextInt();
        double v = nextInt();
        double l = nextInt();
        double d = nextInt();
        double w = nextInt();
        double res;
        if (v <= w) {                                                         
            res = simpleCase(a, v, l, 0);
        } else {
            double vMax = Math.sqrt(2 * d * a);
            if (vMax <= w) {
                res = simpleCase(a, v, l, 0);
            } else {
                double tFullSpeed = v / a;
                double tSlowdown = (v - w) / a;
                if (a * tFullSpeed * tFullSpeed / 2 + v * tSlowdown - a * tSlowdown * tSlowdown / 2 <= d) {
                    res = tFullSpeed + tSlowdown + (d - (a * tFullSpeed * tFullSpeed / 2 + v * tSlowdown - a * tSlowdown * tSlowdown / 2)) / v + simpleCase(a, v, l - d, w);
                } else {
                    double min = w;
                    double max = v;
                    for (int i = 0; i < 1000; ++i) {
                        double cur = (min + max) / 2;
                        double cFullSpeed = cur / a;
                        double cSlowdown = (cur - w) / a;
                        if (a * cFullSpeed * cFullSpeed / 2 + cur * cSlowdown - a * cSlowdown * cSlowdown / 2 <= d)
                            min = cur;
                        else
                            max = cur;
                    }
                    res = min / a + (min - w) / a + simpleCase(a, v, l - d, w);
                }
            }
        }
        writer.printf("%.20f\n", res);
    }

    private double simpleCase(double a, double v, double l, double v0) {
        double tFullSpeed = (v - v0) / a;
        if (v0 * tFullSpeed + a * tFullSpeed * tFullSpeed / 2 <= l) {
            return tFullSpeed + (l - (v0 * tFullSpeed + a * tFullSpeed * tFullSpeed / 2)) / v; 
        } else {
            double min = 0;
            double max = tFullSpeed;
            for (int i = 0; i < 1000; ++i) {
                double cur = (min + max) / 2;
                if (v0 * cur + a * cur * cur / 2 <= l)
                    min = cur;
                else
                    max = cur;
            }
            return min;
        }
    }


    public static void main(String[] args) {
        new Berland().run();
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
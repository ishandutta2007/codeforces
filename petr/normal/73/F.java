import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Tanks implements Runnable {
    class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }

    Point readPoint() throws IOException {
        int x = nextInt();
        int y = nextInt();
        return new Point(x, y);
    }

    private void solve() throws IOException {
        Point A = readPoint();
        Point B = readPoint();
        int n = nextInt();
        Point[] tank = new Point[n];
        double[] alpha = new double[n];
        double[] w = new double[n];
        for (int i = 0; i < n; ++i) {
            tank[i] = readPoint();
            alpha[i] = nextDouble();
            if (alpha[i] > Math.PI) alpha[i] -= 2 * Math.PI;
            w[i] = nextDouble();
        }
        int canSuffer = nextInt();
        double[] maxHit = new double[n + 1];
        for (int i = 0; i < n; ++i) {
            maxHit[i] = processTank(A, B, tank[i], alpha[i], w[i]);
        }
        Arrays.sort(maxHit);
        writer.println(maxHit[n - canSuffer]);
    }

    private double processTank(Point A, Point B, Point tank, double alpha, double w) {
        if (w == 0)
            return 0;
        return Math.max(process(A, B, tank, alpha, w), process(A, B, tank, alpha, -w));
    }

    private double process(Point a, Point b, Point tank, double alpha, double w) {
        double alphaA = Math.atan2(a.y - tank.y, a.x - tank.x);
        double alphaB = Math.atan2(b.y - tank.y, b.x - tank.x);
        if (Math.signum(alphaA - alpha) != Math.signum(w)) alphaA += Math.PI * 2 * Math.signum(w);
        if (Math.signum(alphaB - alpha) != Math.signum(w)) alphaB += Math.PI * 2 * Math.signum(w);
        double tA = (alphaA - alpha) / w;
        double tB = (alphaB - alpha) / w;
        double dy = b.y - a.y;
        double dx = b.x - a.x;
        double dist = Math.sqrt(dx * dx + dy * dy);
        if (tB <= tA) {
            return dist / tB;
        } else {
            double best = 0;
            double bestVal = 0;
            double res = dist / tB;
            for (int i = 0; i <= 100; ++i) {
                double middle = i / 100.0;
                double x = a.x + middle * dx;
                double y = a.y + middle * dy;
                double alphaM2 = Math.atan2(y - tank.y, x - tank.x);
                if (Math.signum(alphaM2 - alpha) != Math.signum(w)) alphaM2 += Math.PI * 2 * Math.signum(w);
                double tM = (alphaM2 - alpha) / w;
                double cur = middle * dist / tM;
                res = Math.max(res, cur);
                if (cur > bestVal) {
                    bestVal = cur;
                    best = middle;
                }
            }
            double left = Math.max(0, best - 0.03);
            double right = Math.min(1, best + 0.03);
            for (int i = 0; i < 300; ++i) {
                double middle2;
                double tM2;
                {
                    middle2 = (left + 2 * right) / 3;
                    double x = a.x + middle2 * dx;
                    double y = a.y + middle2 * dy;
                    double alphaM2 = Math.atan2(y - tank.y, x - tank.x);
                    if (Math.signum(alphaM2 - alpha) != Math.signum(w)) alphaM2 += Math.PI * 2 * Math.signum(w);
                    tM2 = (alphaM2 - alpha) / w;
                }
                double middle1;
                double tM1;
                {
                    middle1 = (2 * left + right) / 3;
                    double x = a.x + middle1 * dx;
                    double y = a.y + middle1 * dy;
                    double alphaM1 = Math.atan2(y - tank.y, x - tank.x);
                    if (Math.signum(alphaM1 - alpha) != Math.signum(w)) alphaM1 += Math.PI * 2 * Math.signum(w);
                    tM1 = (alphaM1 - alpha) / w;
                }
                double valM1 = dist * middle1 / tM1;
                double valM2 = dist * middle2 / tM2;
                res = Math.max(res, valM1);
                res = Math.max(res, valM2);
                if (valM1 > valM2) {
                    right = middle2;
                } else {
                    left = middle1;
                }
            }
            return res;
        }
    }

    public static void main(String[] args) {
        new Tanks().run();
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
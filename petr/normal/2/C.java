import java.io.*;
import java.util.*;

public class Comments implements Runnable {
    static class Circle {
        double x;
        double y;
        double r;

        Circle(double x, double y, double r) {
            this.x = x;
            this.y = y;
            this.r = r;
        }

        public Circle swapXY() {
            return new Circle(y, x, r);
        }
    }

    static class SecondOrderCurve {
        double x2;
        double y2;
        double x1;
        double y1;
        double free;

        public SecondOrderCurve(Circle a, Circle b) {
            x2 = b.r * b.r - a.r * a.r;
            y2 = x2;
            x1 = -2 * (b.r * b.r * a.x - a.r * a.r * b.x);
            y1 = -2 * (b.r * b.r * a.y - a.r * a.r * b.y);
            free = b.r * b.r * (a.x * a.x + a.y * a.y) - a.r * a.r * (b.x * b.x + b.y * b.y);
        }

        SecondOrderCurve(double x2, double y2, double x1, double y1, double free) {
            this.x2 = x2;
            this.y2 = y2;
            this.x1 = x1;
            this.y1 = y1;
            this.free = free;
        }

        public SecondOrderCurve multiply(double by) {
            return new SecondOrderCurve(x2 * by, y2 * by, x1 * by, y1 * by, free * by); 
        }

        public SecondOrderCurve subtract(SecondOrderCurve a) {
            return new SecondOrderCurve(x2 - a.x2, y2 - a.y2, x1 - a.x1, y1 - a.y1, free - a.free);
        }

        public SecondOrderCurve swapXY() {
            return new SecondOrderCurve(y2, x2, y1, x1, free);
        }

        public SecondOrderCurve substituteY(double k, double a) {
            return new SecondOrderCurve(x2 + y2 * k * k, 0, x1 + y2 * 2 * k * a + y1 * k, 0, free + y2 * a * a + y1 * a);
        }
    }

    private void solve() throws IOException {
        Circle[] c = new Circle[3];
        for (int i = 0; i < 3; ++i) {
            int x = nextInt();
            int y = nextInt();
            int r = nextInt();
            c[i] = new Circle(x, y, r);
        }
        SecondOrderCurve c1 = new SecondOrderCurve(c[0], c[1]);
        SecondOrderCurve c2 = new SecondOrderCurve(c[0], c[2]);
        SecondOrderCurve line;
        SecondOrderCurve check;
        if (c1.x2 == 0) {
            line = c1;
            check = c2;
        } else if (c2.x2 == 0) {
            line = c2;
            check = c1;
        } else {
            line = c1.multiply(c2.x2).subtract(c2.multiply(c1.x2));
            check = c1;
        }
        boolean needSwap = false;
        if (line.y1 == 0) {
            needSwap = true;
            c1 = c1.swapXY();
            c2 = c2.swapXY();
            line = line.swapXY();
            for (int i = 0; i < 3; ++i)
                c[i] = c[i].swapXY();
        }
        if (line.y1 == 0)
            throw new RuntimeException();
        double k = -line.x1 / line.y1;
        double a = -line.free / line.y1;
        SecondOrderCurve quad = check.substituteY(k, a);
        double mx = Math.max(Math.abs(quad.x2), Math.max(Math.abs(quad.x1), Math.abs(quad.free)));
        quad.x2 /= mx;
        quad.x1 /= mx;
        quad.free /= mx;
        if (Math.abs(quad.x2) < 1e-12) {
            if (Math.abs(quad.x1) < 1e-9) {
                return;
            }
            double x = -quad.free / quad.x1;
            double y = k * x + a;
            if (needSwap)
                writer.printf("%.5f %.5f\n", y, x);
            else {
                writer.printf("%.5f %.5f\n", x, y);
            }
        } else {
            double d = quad.x1 * quad.x1 - 4 * quad.x2 * quad.free;
            if (d >= -1e-12 && d < 0)
                d = 0;
            if (d < 0)
                return;
            double x1 = (-quad.x1 + Math.sqrt(d)) / (2 * quad.x2);
            double x2 = (-quad.x1 - Math.sqrt(d)) / (2 * quad.x2);
            double y1 = k * x1 + a;
            double y2 = k * x2 + a;
/*            System.out.println(quad.x2 * x1 * x1 + quad.x1 * x1 + quad.free);
            System.out.println(c1.x2 * x1 * x1 + c1.x1 * x1 + c1.y2 * y1 * y1 + c1.y1 * y1 + c1.free);
            for (int i = 0; i < 3; ++i) {
                System.out.println(Math.hypot(c[i].x - x1, c[i].y - y1) / c[i].r);
            }*/
            if (Math.hypot(c[0].x - x1, c[0].y - y1) <= Math.hypot(c[0].x - x2, c[0].y - y2)) {
                if (needSwap)
                    writer.printf("%.5f %.5f\n", y1, x1);
                else {
                    writer.printf("%.5f %.5f\n", x1, y1);
                }
            } else {
                if (needSwap)
                    writer.printf("%.5f %.5f\n", y2, x2);
                else {
                    writer.printf("%.5f %.5f\n", x2, y2);
                }
            }
        }
    }


    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new Comments().run();
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
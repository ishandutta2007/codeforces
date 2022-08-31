import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int xp = in.nextInt();
        int yp = in.nextInt();
        int vp = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        int v = in.nextInt();
        int r = in.nextInt();
        double R = Math.sqrt(xp * xp + yp * yp);
        double left = 0;
        double right = 1e7;
        while ((right - left) / right > 1e-10) {
            double middle = (left + right) / 2;
            double alpha = middle / (R / vp);
            double nx = xp * Math.cos(alpha) - yp * Math.sin(alpha);
            double ny = xp * Math.sin(alpha) + yp * Math.cos(alpha);
            double a = ny - y;
            double b = x - nx;
            double c = -(a * x + b * y);
            double z = Math.sqrt(a * a + b * b);
            a /= z;
            b /= z;
            c /= z;
            double need;
            if (Math.abs(c) < r - 1e-8) {
                double mx = a * (-c);
                double my = b * (-c);
                if (dist(x, y, mx, my) + dist(mx, my, nx, ny) > dist(x, y, nx, ny) + 1e-8) {
                    need = dist(x, y, nx, ny);
                } else {
                    need = catet(dist(x, y, 0, 0), r) + catet(dist(nx, ny, 0, 0), r);
                    double alp = Math.abs(Math.atan2(y, x) - Math.atan2(ny, nx));
                    if (alp > Math.PI) alp = 2 * Math.PI - alp;
                    alp -= Math.acos(Math.min(1.0, r / dist(x, y, 0, 0)));
                    alp -= Math.acos(Math.min(1.0, r / dist(nx, ny, 0, 0)));
                    need += alp * r;
                }
            } else {
                need = dist(x, y, nx, ny);
            }
            if (need / v <= middle)
                right = middle;
            else
                left = middle;
        }
        out.println(right);
	}

    private double catet(double a, int b) {
        double z = a * a - b * b;
        if (z < 1e-12) z = 0;
        return Math.sqrt(z);
    }

    private double dist(double x1, double y1, double x2, double y2) {
        double dx = x1 - x2;
        double dy = y1 - y2;
        return Math.sqrt(dx * dx + dy * dy);
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }
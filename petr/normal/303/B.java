import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long maxx = in.nextInt();
        long maxy = in.nextInt();
        long x = in.nextInt();
        long y = in.nextInt();
        long a = in.nextInt();
        long b = in.nextInt();
        long g = BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).intValue();
        a /= g;
        b /= g;
        long bdist = Long.MAX_VALUE;
        long x1 = -1;
        long y1 = -1;
        long x2 = -1;
        long y2 = -1;
        long mult = Math.min(maxx / a, maxy / b);
        {
            long sx = a * mult;
            long sy = b * mult;
            long xl = Math.max(0, Math.min(maxx - sx, x - sx / 2));
            for (long dx = 0; dx < 2 && xl >= 0; ++dx, --xl) {
                long yl = Math.max(0, Math.min(maxy - sy, y - sy / 2));
                for (long dy = 0; dy < 2 && yl >= 0; ++dy, --yl) {
                    long xr = xl + sx;
                    long yr = yl + sy;
                    long distx = (xl + xr - 2 * x);
                    long disty = (yl + yr - 2 * y);
                    long dist = distx * distx + disty * disty;
                    boolean ok;
                    if (dist < bdist) {
                        ok = true;
                    } else if (dist > bdist) {
                        ok = false;
                    } else if (xl < x1) {
                        ok = true;
                    } else if (xl > x1) {
                        ok = false;
                    } else if (yl < y1) {
                        ok = true;
                    } else if (yl > y1) {
                        ok = false;
                    } else if (xr < x2) {
                        ok = true;
                    } else if (xr > x2) {
                        ok = false;
                    } else if (yr < y2) {
                        ok = true;
                    } else {
                        ok = false;
                    }
                    if (ok) {
                        bdist = dist;
                        x1 = xl;
                        y1 = yl;
                        x2 = xr;
                        y2 = yr;
                    }
                }
            }
        }
        out.println(x1 + " " + y1 + " " + x2 + " " + y2);
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

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
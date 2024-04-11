import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    static class Point implements Comparable<Point> {
        int x;
        int y;

        public int compareTo(Point point) {
            if (x != point.x) return x - point.x; else return y - point.y;
        }

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        Point() {
        }
    }
    
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        Point[] p = new Point[n];
        for (int i = 0; i < n; ++i) {
            p[i] = new Point();
            p[i].x = in.nextInt();
            p[i].y = in.nextInt();
            //p[i].x = 57;
            //p[i].y = 43;
        }
        Arrays.sort(p);
        if (k >= n) {
            out.println(-1);
            return;
        }
        Point[] res = new Point[100];
        int numRes = 0;
        for (int first = 0; first <= k; ++first)
            for (int second = 0; second + first <= k; ++second) {
                int sx = p[first].x + p[n - 1 - second].x;
                int sy = p[first].y + p[n - 1 - second].y;
                int p1 = first;
                int p2 = n - 1 - second;
                int skipped = first + second;
                while (skipped <= k && p1 <= p2) {
                    int cx = p[p1].x + p[p2].x;
                    int cy = p[p1].y + p[p2].y;
                    if (cx < sx) {
                        ++p1;
                        ++skipped;
                    } else if (cx > sx) {
                        --p2;
                        ++skipped;
                    } else if (cy < sy) {
                        ++p1;
                        ++skipped;
                    } else if (cy > sy) {
                        --p2;
                        ++skipped;
                    } else {
                        ++p1;
                        --p2;
                    }
                }
                if (skipped <= k) {
                    res[numRes++] = new Point(sx, sy);
                }
            }
        Arrays.sort(res, 0, numRes);
        int cnt = 0;
        for (int i = 0; i < numRes; ++i) {
            if (i == 0 || res[i].compareTo(res[i - 1]) != 0) {
                res[cnt++] = res[i];
            }
        }
        out.println(cnt);
        for (int i = 0; i < cnt; ++i) {
            out.println(res[i].x / 2.0 + " " + res[i].y / 2.0);
        }
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
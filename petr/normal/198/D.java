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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static class Point {
        int x;
        int y;
        int z;

        Point(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Point point = (Point) o;

            if (x != point.x) return false;
            if (y != point.y) return false;
            if (z != point.z) return false;

            return true;
        }

        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            result = 31 * result + z;
            return result;
        }
    }
    
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        Point[][] ans = new Point[51][];
        ans[1] = new Point[]{new Point(0, 0, 0)};
        ans[2] = new Point[]{new Point(0, 0, 0), new Point(0, 1, 0), new Point(1, 1, 0), new Point(1, 0, 0), new Point(1, 0, 1), new Point(1, 1, 1), new Point(0, 1, 1), new Point(0, 0, 1)};
        for (int n = 3; n < ans.length; ++n) {
            Point[] prev = ans[n - 1];
            int prevSize = (n - 1) * (n - 1) * (n - 1);
            if (prev.length != prevSize) throw new RuntimeException();
            int sideSize = (n - 1) * (n - 1);
            if (!prev[prevSize - sideSize - 1].equals(new Point(n - 2, 0, n - 3))) throw new RuntimeException();
            if (!prev[prevSize - sideSize].equals(new Point(n - 2, 0, n - 2))) throw new RuntimeException();
            if (!prev[prevSize - 1].equals(new Point(0, 0, n - 2))) throw new RuntimeException();
            if (!prev[0].equals(new Point(0, 0, 0))) throw new RuntimeException();
            Point[] cur = new Point[n * n * n];
            ans[n] = cur;
            int curPtr = 0;
            for (int i = 0; i < sideSize; ++i) {
                Point old = prev[prevSize - 1 - i];
                cur[curPtr++] = new Point(old.x, old.y, 0);
            }
            for (int i = 0; i < prevSize; ++i) {
                Point old = prev[i];
                cur[curPtr++] = new Point(n - 2 - old.x, old.y, old.z + 1);
            }
            Point[] rect = getRectangleTraversal(n - 1, n);
            for (int i = 0; i < rect.length; ++i) {
                cur[curPtr++] = new Point(n - 1, rect[i].x, rect[i].y);
            }
            rect = getRectangleTraversal2(n);
            for (int i = 0; i < rect.length; ++i) {
                cur[curPtr++] = new Point(rect[i].x, n - 1, rect[i].y);
            }
            if (curPtr != cur.length) throw new RuntimeException();
            for (int i = 0; i < cur.length; ++i) {
                int tmp = cur[i].y;
                cur[i].y = cur[i].z;
                cur[i].z = tmp;
            }
        }
        int n = in.nextInt();
        int[][][] field = new int[n][n][n];
        Point prev = null;
        int at = 0;
        for (Point p : ans[n]) {
            if (prev != null) {
                int d = Math.abs(p.x - prev.x) + Math.abs(p.y - prev.y) + Math.abs(p.z - prev.z);
                if (d != 1) throw new RuntimeException();
            }
            prev = p;
            ++at;
            if (field[p.x][p.y][p.z] != 0) throw new RuntimeException();
            field[p.x][p.y][p.z] = at;
        }
        boolean xf = true;
        for (int[][] x : field) {
            if (xf) xf = false; else out.println();
            for (int[] y : x) {
                boolean zf = true;
                for (int z : y) {
                    if (zf) zf = false; else out.print(" ");
                    if (z == 0) throw new RuntimeException();
                    out.print(z);
                }
                out.println();
            }
        }
	}

    private Point[] getRectangleTraversal2(int n) {
        int sx = n;
        int sy = n; 
        Point[] res = new Point[sx * sy];
        int resPtr = 0;
        if (sy % 2 == 0) {
            for (int y = sy - 1; y >= 0; --y) {
                if (y % 2 != 0) {
                    for (int x = 0; x < sx; ++x)
                        res[resPtr++] = new Point(y, x, 0);
                } else {
                    for (int x = sx - 1; x >= 0; --x)
                        res[resPtr++] = new Point(y, x, 0);
                }
            }
        } else {
            for (int y = sy - 1; y >= 2; --y) {
                if (y % 2 == 0) {
                    for (int x = 0; x < sx; ++x)
                        res[resPtr++] = new Point(y, x, 0);
                } else {
                    for (int x = sx - 1; x >= 0; --x)
                        res[resPtr++] = new Point(y, x, 0);
                }
            }
            for (int x = sx - 1; x >= 0; --x) {
                if (x % 2 == 0) {
                    res[resPtr++] = new Point(1, x, 0);
                    res[resPtr++] = new Point(0, x, 0);
                } else {
                    res[resPtr++] = new Point(0, x, 0);
                    res[resPtr++] = new Point(1, x, 0);
                }
            }
        }
        if (resPtr != res.length) throw new RuntimeException();
        return res;
    }

    private Point[] getRectangleTraversal(int sx, int sy) {
        Point[] res = new Point[sx * sy];
        int resPtr = 0;
        if (sy % 2 != 0) {
            for (int y = sy - 1; y >= 0; --y) {
                if (y % 2 == 0) {
                    for (int x = 0; x < sx; ++x)
                        res[resPtr++] = new Point(x, y, 0);
                } else {
                    for (int x = sx - 1; x >= 0; --x)
                        res[resPtr++] = new Point(x, y, 0);
                }
            }
        } else {
            for (int y = sy - 1; y >= 2; --y) {
                if (y % 2 != 0) {
                    for (int x = 0; x < sx; ++x)
                        res[resPtr++] = new Point(x, y, 0);
                } else {
                    for (int x = sx - 1; x >= 0; --x)
                        res[resPtr++] = new Point(x, y, 0);
                }
            }
            for (int x = 0; x < sx; ++x) {
                if (x % 2 == 0) {
                    res[resPtr++] = new Point(x, 1, 0);
                    res[resPtr++] = new Point(x, 0, 0);
                } else {
                    res[resPtr++] = new Point(x, 0, 0);
                    res[resPtr++] = new Point(x, 1, 0);
                }
            }
        }
        if (resPtr != res.length) throw new RuntimeException();
        return res;
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
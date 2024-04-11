import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    static int[] DX = {1, 0, -1, 0};
    static int[] DY = {0, 1, 0, -1};

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] c = new char[n][];
        for (int i = 0; i < n; i++) {
            c[i] = in.next().toCharArray();
        }
        int[][][] d = new int[4][n][m];
        int[] q = new int[5 * n * m];
        boolean[][][] was = new boolean[4][n][m];
        int head = 0;
        int tail = 0;
        q[tail++] = code(3, n - 1, m - 1, n, m);
        was[3][n - 1][m - 1] = true;
        while (head != tail) {
            int state = q[head++];
            if (head == q.length) {
                head = 0;
            }
            int dir = state / (n * m);
            int x = state / m % n;
            int y = state % m;
            {
                int newX = x + DX[dir];
                int newY = y + DY[dir];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m || was[dir][newX][newY]) {
                } else {
                    d[dir][newX][newY] = d[dir][x][y];
                    --head;
                    if (head < 0) {
                        head += q.length;
                    }
                    q[head] = code(dir, newX, newY, n, m);
                    was[dir][newX][newY] = true;
                }
            }
            if (c[x][y] != '#') {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int newDir = i + dir & 3;
                int newX = x;
                int newY = y;
                if (newX < 0 || newY < 0 || newX >= n || newY >= m || was[newDir][newX][newY]) {
                    continue;
                }
                d[newDir][newX][newY] = d[dir][x][y] + 1;
                q[tail++] = code(newDir, newX, newY, n, m);
                was[newDir][newX][newY] = true;
                if (tail == q.length) {
                    tail = 0;
                }
            }
        }
        if (!was[3][0][0]) {
            out.println(-1);
        } else {
            out.println(d[3][0][0]);
        }
    }

    static int code(int dir, int x, int y, int n, int m) {
        return y + x * m + dir * n * m;
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}
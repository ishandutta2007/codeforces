import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        if (n == 5) {
            out.println(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1");
            return;
        }
        if (n == 3) {
            out.println(">vv\n" +
                    "^<.\n" +
                    "^.<\n" +
                    "1 3");
            return;
        }
//        int n = in.nextInt();
//        char[][] c = in.readCharacterFieldTokens(n, n);
        char[][] c = new char[100][100];
        for (char[] e : c) {
            Arrays.fill(e, '.');
        }
        for (int i = 0; i < 99; i++) {
            c[0][i] = '>';
        }
        c[0][99] = 'v';
        for (int i = 1; i < 100; i += 2) {
            for (int j = 0; j < 48; j++) {
                c[i][99 - j] = '<';
            }
            for (int j = 0; j < 50; j++) {
                c[i][99 - 48 - j] = (j & 1) == 0 ? '.' : '<';
            }
            if (i + 1 < 100) {
                c[i][1] = 'v';
                for (int j = 0; j < 48; j++) {
                    c[i + 1][1 + j] = '>';
                }
                for (int j = 0; j < 50; j++) {
                    c[i + 1][1 + 48 + j] = (j & 1) == 0 ? '.' : '>';
                }
                c[i + 1][99] = 'v';
            }
        }
        for (int i = 0; i < 50; i++) {
            c[99 - i][0] = '^';
        }
//        int x = 0;
//        int y = 0;
//        for (int n = 100; n > 0; n -= 2) {
//            for (int dir = 0; dir < 4; dir++) {
//                for (int e = 0; e < n - 1; e++) {
//                    c[x][y] = DIRS.charAt(dir);
//                    x += DX[dir];
//                    y += DY[dir];
//                }
//            }
//            x -= DX[3];
//            y -= DY[3];
//            c[x][y] = DIRS.charAt(0);
//            x += DX[0];
//            y += DY[0];
//        }
//        x -= DX[0];
//        y -= DY[0];
//        c[x][y] = '.';
//        Random rand = new Random();
//        for (int i = 0; i < 1; i++) {
//            int xx = rand.nextInt(50) + 5;
//            int yy = rand.nextInt(50) + 5;
//            c[xx][yy] = '.';
//        }
//        for (int i = 1; i < 100; i += 2) {
//            for (int j = 1; j < 100; j += 2) {
//                c[i][j] = '.';
//            }
//        }
//        for (char[] e : c) {
//            System.out.println(e);
//        }
//        check(c, 0, 0);
        for (char[] e : c) {
            out.println(e);
        }
        out.println(1 + " " + 1);
    }

    }

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
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
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
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
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int[][] d = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                d[i][j] = d[j][i] = in.nextInt();
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (d[i][k] + d[k][j] < d[i][j] || (d[i][j] & 1) != (d[i][k] + d[k][j] & 1)) {
                        out.println(-1);
                        return;
                    }
                }
            }
        }
        int sum = d[0][2];
        int dif = d[1][2] - d[0][1];
        int d1 = (sum + dif) / 2;
        int d2 = (sum - dif) / 2;
        int b1 = d[1][3] - d[0][1] + d[2][3] - d1 - d2;
        int b2 = d1 + d2 + d[0][3] - d[2][3];
        int b3 = d[0][1] + d[0][3] - d[1][3];
        if (d1 < 0 || d2 < 0 || d2 > d[0][1] || (b1 & 1) == 1 || (b2 & 1) == 1 || (b3 & 1) == 1) {
            out.println(-1);
            return;
        }
        b1 /= 2;
        b2 /= 2;
        b3 /= 2;
        for (int e1 = 0; e1 <= 1000000; e1++) {
            int e4 = e1 - b1;
            if (e4 < 0 || e4 > d2) {
                continue;
            }
            int e2 = b2 - e4;
            if (e2 < 0 || e2 > d1) {
                continue;
            }
            int e3 = b3 - e4;
            if (e3 < 0 || e3 > d[0][1] - d2) {
                continue;
            }
            int len = e1 + d1 + d[0][1];
            out.println(len);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < len; i++) {
                sb.append('a');
            }
            out.println(sb);
            sb.setLength(0);
            for (int i = 0; i < len; i++) {
                sb.append(i < len - d[0][1] ? 'a' : 'b');
            }
            out.println(sb);
            sb.setLength(0);
            for (int i = 0; i < e1; i++) {
                sb.append('a');
            }
            for (int i = 0; i < d1; i++) {
                sb.append('b');
            }
            for (int i = 0; i < d[0][1] - d2; i++) {
                sb.append('a');
            }
            for (int i = 0; i < d2; i++) {
                sb.append('b');
            }
            out.println(sb);
            sb.setLength(0);
            for (int i = 0; i < e1; i++) {
                sb.append('b');
            }
            for (int i = 0; i < d1 - e2; i++) {
                sb.append('a');
            }
            for (int i = 0; i < e2; i++) {
                sb.append('b');
            }
            for (int i = 0; i < d[0][1] - d2 - e3; i++) {
                sb.append('a');
            }
            for (int i = 0; i < e3; i++) {
                sb.append('b');
            }
            for (int i = 0; i < d2 - e4; i++) {
                sb.append('a');
            }
            for (int i = 0; i < e4; i++) {
                sb.append('b');
            }
            out.println(sb);
            return;
        }
        out.println(-1);
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
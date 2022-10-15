import java.io.InputStreamReader;
import java.io.IOException;
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
        int leftHole = in.nextInt();
        int rightHole = in.nextInt();
        int n = in.nextInt();
        int[] score = new int[n];
        boolean[] isUp = new boolean[n];
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            score[i] = in.nextInt();
            isUp[i] = in.next().equals("T");
            a[i] = in.nextInt();
            b[i] = in.nextInt();
        }
        int answer = 0;
        final int height = 100;
        final int width = 100000;
        for (int goUp = 0; goUp < 2; goUp++) {
            all: for (int hits = 1; hits <= n; hits++) {
                int leftHoleVirtual = leftHole + (hits / 2) * height * 2;
                if ((hits & 1) == 1) {
                    leftHoleVirtual += 2 * (height - leftHole);
                }
                double aLine = leftHoleVirtual - rightHole;
                double bLine = width;
                double cLine = -bLine * leftHoleVirtual;
                boolean up = true;
                boolean[] was = new boolean[n];
                int curAnswer = 0;
                for (int v = 0; v < hits; v++, up = !up) {
                    double y = (v + 1) * height;
                    double x = (-cLine - bLine * y) / aLine;
                    boolean ok = false;
                    for (int i = 0; i < n; i++) {
                        if (isUp[i] != up) {
                            continue;
                        }
                        if (compare(a[i], x) <= 0 && compare(x, b[i]) <= 0) {
                            if (was[i]) {
                                continue all;
                            }
                            curAnswer += score[i];
                            was[i] = true;
                            ok = true;
                            break;
                        }
                    }
                    if (!ok) {
                        continue all;
                    }
                }
                if (answer < curAnswer) {
                    answer = curAnswer;
                    System.err.println(hits + " " + goUp);
                }
            }
            leftHole = height - leftHole;
            rightHole = height - rightHole;
            for (int i = 0; i < n; i++) {
                isUp[i] = !isUp[i];
            }
        }
        out.println(answer);
	}

    static final double EPS = 1e-9;

    static int compare(double a, double b) {
        return Math.abs(a - b) < EPS ? 0 : a < b ? -1 : 1;
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
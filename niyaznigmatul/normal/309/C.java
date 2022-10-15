import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;
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
    TaskC solver = new TaskC();
    solver.solve(1, in, out);
    out.close();
  }
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] boxes = new int[31];
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            while (x > 0) {
                boxes[Integer.numberOfTrailingZeros(x)]++;
                x &= x - 1;
            }
        }
        int[] count = new int[31];
        for (int i = 0; i < m; i++) {
            count[in.nextInt()]++;
        }
        int[] got = new int[31];
        for (int i = 30; i >= 0; i--) {
            int cur = count[i];
            if (cur == 0) continue;
            for (int j = 30; j >= i; j--) {
                if (boxes[j] == 0) continue;
                int cn = boxes[j];
                int cn2 = (1 << j) >> i;
                int boxesToGet = cur / cn2;
                if (boxesToGet > cn) {
                    boxes[j] = 0;
                    got[i] += cn * cn2;
                    cur -= cn * cn2;
                } else {
                    boxes[j] -= boxesToGet;
                    got[i] += boxesToGet * cn2;
                    cur -= boxesToGet * cn2;
                }
                if (boxes[j] > 0 && cur > 0 && cur < cn2) {
                    int left = (1 << j) - cur * (1 << i);
                    boxes[j]--;
                    got[i] += cur;
                    cur = 0;
                    while (left > 0) {
                        boxes[Integer.numberOfTrailingZeros(left)]++;
                        left &= left - 1;
                    }
                }
            }
            for (int j = 30; j > i; j--) {
                int cn = got[j];
                if (cn == 0) continue;
                int cn2 = (1 << j) >> i;
                int boxesToGet = cur / cn2;
                if (boxesToGet > cn) {
                    got[j] = 0;
                    got[i] += cn * cn2;
                    cur -= cn * cn2;
                } else {
                    got[j] -= boxesToGet;
                    got[i] += boxesToGet * cn2;
                    cur -= boxesToGet * cn2;
                }
                if (cur > 0 && cur < cn2 && got[j] > 0) {
                    int left = (1 << j) - cur * (1 << i);
                    got[j]--;
                    got[i] += cur;
                    cur = 0;
                    while (left > 0) {
                        boxes[Integer.numberOfTrailingZeros(left)]++;
                        left &= left - 1;
                    }
                }
            }
        }
        int ans = 0;
        for (int i : got) ans += i;
        out.println(ans);
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
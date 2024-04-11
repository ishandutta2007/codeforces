import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Stack;
import java.util.Vector;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        char[] c = in.next().toCharArray();
        int bestL = -1;
        int bestR = -1;
        int bestCount = 0;
        Stack<Integer> stack = new Stack<Integer>();
        int[] pair = new int[c.length];
        Arrays.fill(pair, -1);
        for (int i = 0; i < c.length; i++) {
            if (c[i] == '(' || c[i] == '[') {
                stack.add(i);
            } else {
                char ch = c[i] == ')' ? '(' : '[';
                if (!stack.isEmpty() && c[stack.peek()] == ch) {
                    pair[i] = stack.pop();
                    pair[pair[i]] = i;
                } else {
                    stack.clear();
                }
            }
        }
        for (int i = 0; i < c.length; ) {
            if (pair[i] >= i) {
                int first = i;
                int curCount = 0;
                while (i < c.length && pair[i] >= i) {
                    for (int j = i; j <= pair[i]; j++) {
                        if (c[j] == '[') {
                            ++curCount;
                        }
                    }
                    i = pair[i] + 1;
                }
                if (curCount > bestCount) {
                    bestCount = curCount;
                    bestL = first;
                    bestR = i;
                }
            } else {
                i++;
            }
        }
        if (bestCount == 0) {
            out.println(0);
        } else {
            out.println(bestCount);
            out.println(new String(c, bestL, bestR - bestL));
        }
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}
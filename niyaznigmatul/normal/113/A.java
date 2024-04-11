import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        boolean feminine = false;
        List<String> z = new ArrayList<>();
        while (true) {
            String s = in.next();
            if (s == null) {
                break;
            }
            z.add(s);
        }
        int id = -1;
        for (int i = 0; i < z.size(); i++) {
            String s = z.get(i);
            if (s.endsWith("lios") || s.endsWith("liala")) {
            } else if (s.endsWith("etr") || s.endsWith("etra")) {
                if (id >= 0) {
                    out.println("NO");
                    return;
                }
                id = i;
                feminine = s.endsWith("etra");
            } else if (s.endsWith("initis") || s.endsWith("inites")) {
            } else {
                out.println("NO");
                return;
            }
        }
        if (z.size() == 1) {
            out.println("YES");
            return;
        }
        if (id < 0) {
            out.println("NO");
            return;
        }
        for (int i = 0; i < id; i++) {
            String s = z.get(i);
            if ((s.endsWith("lios") || s.endsWith("liala")) && (s.endsWith("liala") == feminine)) {
            } else {
                out.println("NO");
                return;
            }
        }
        for (int i = id + 1; i < z.size(); i++) {
            String s = z.get(i);
            if ((s.endsWith("initis") || s.endsWith("inites")) && (s.endsWith("inites") == feminine)) {
            } else {
                out.println("NO");
                return;
            }
        }
        out.println("YES");
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
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
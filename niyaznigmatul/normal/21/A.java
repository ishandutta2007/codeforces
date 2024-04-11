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
        String s = in.next();
        int pos = s.indexOf('@');
        if (pos < 0) {
            out.println("NO");
            return;
        }
        String userName = s.substring(0, pos);
        if (!isUserName(userName)) {
            out.println("NO");
            return;
        }
        s = s.substring(pos + 1);
        pos = s.indexOf('/');
        String hostName = pos < 0 ? s : s.substring(0, pos);
        if (hostName.length() < 1 || hostName.length() > 32) {
            out.println("NO");
            return;
        }
        while (true) {
            int pos2 = hostName.indexOf('.');
            String z = pos2 < 0 ? hostName : hostName.substring(0, pos2);
            if (!isUserName(z)) {
                out.println("NO");
                return;
            }
            if (pos2 < 0) {
                break;
            }
            hostName = hostName.substring(pos2 + 1);
        }
        if (pos >= 0) {
            String resource = s.substring(pos + 1);
            if (!isUserName(resource)) {
                out.println("NO");
                return;
            }
        }
        out.println("YES");
    }

    private boolean isUserName(String userName) {
        if (userName.length() < 1 || userName.length() > 16) {
            return false;
        }
        for (int i = 0; i < userName.length(); i++) {
            char c = userName.charAt(i);
            if (!Character.isLetter(c) && !Character.isDigit(c) && c != '_') {
                return false;
            }
        }
        return true;
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
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.HashSet;
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
        int n = Integer.parseInt(in.nextLine().trim());
        HashSet<String> ans = new HashSet<String>();
        for (int i = 0; i < n; i++) {
            char[][] c = new char[2][];
            c[0] = in.nextLine().trim().toCharArray();
            c[1] = in.nextLine().trim().toCharArray();
            String s = new String(c[0]) + new String(c[1]);
            for (int rot = 0; rot < 4; rot++) {
                char t = c[0][0];
                c[0][0] = c[0][1];
                c[0][1] = c[1][1];
                c[1][1] = c[1][0];
                c[1][0] = t;
                String z = new String(c[0]) + new String(c[1]);
                if (z.compareTo(s) < 0) {
                    s = z;
                }
            }
            ans.add(s);
            in.nextLine();
        }
        out.println(ans.size());
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

    public String nextLine() {
        try {
            return readLine();
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
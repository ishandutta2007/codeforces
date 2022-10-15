import java.util.Date;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.InputMismatchException;
import java.text.DateFormat;
import java.text.ParseException;
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
		Journal solver = new Journal();
		solver.solve(1, in, out);
		out.close();
	}
}

class Journal {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = Integer.parseInt(in.nextLine().trim());
        long lastTime = Long.MAX_VALUE;
        int count = 0;
        int answer = 0;
        for (int i = 0; i < n; i++) {
            String line = in.nextLine();
            int pos = line.indexOf("]:");
            String time = line.substring(1, pos);
            time = time.replaceAll("\\.", "");
            try {
                Date z = new SimpleDateFormat("hh:mm a").parse(time);
                long curTime = z.getTime();
                if (lastTime == curTime) {
                    if (count == 10) {
                        count = 1;
                        ++answer;
                    } else {
                        ++count;
                    }
                } else {
                    count = 1;
                    if (lastTime > curTime) {
                        ++answer;
                    }
                }
                lastTime = curTime;
            } catch (ParseException e) {
                e.printStackTrace();
                continue;
            }
        }
        out.println(answer);
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
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long c = in.nextLong();
        long hr = in.nextLong();
        long hb = in.nextLong();
        long wr = in.nextLong();
        long wb = in.nextLong();
        if (wr * wr >= c) {
            long res = 0;
            for (int nr = 0; nr * wr <= c; ++nr) {
                long nb = (c - nr * wr) / wb;
                long got = nr * hr + nb * hb;
                res = Math.max(res, got);
            }
            out.println(res);
            return;
        }
        if (wb * wb >= c) {
            long res = 0;
            for (int nb = 0; nb * wb <= c; ++nb) {
                long nr = (c - nb * wb) / wr;
                long got = nr * hr + nb * hb;
                res = Math.max(res, got);
            }
            out.println(res);
            return;
        }
        if (hr * wb < hb * wr) {
            long res = 0;
            for (int nr = 0; nr < wb && nr * wr <= c; ++nr) {
                long nb = (c - nr * wr) / wb;
                long got = nr * hr + nb * hb;
                res = Math.max(res, got);
            }
            out.println(res);
        } else {
            long res = 0;
            for (int nb = 0; nb < wr && nb * wb <= c; ++nb) {
                long nr = (c - nb * wb) / wr;
                long got = nr * hr + nb * hb;
                res = Math.max(res, got);
            }
            out.println(res);
        }
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}
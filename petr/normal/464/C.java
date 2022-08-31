import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

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
    static final long MODULO = (long) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();
        int n = in.nextInt();
        String[] req = new String[n];
        for (int i = 0; i < n; ++i) req[i] = in.next();
        int[] p10 = new int[10];
        int[] h = new int[10];
        for (int i = 0; i < 10; ++i) {
            p10[i] = 10;
            h[i] = i;
        }
        for (int i = req.length - 1; i >= 0; --i) {
            String st = req[i];
            int src = st.charAt(0) - '0';
            long np10 = 1;
            long nh = 0;
            for (int j = 3; j < st.length(); ++j) {
                int cur = st.charAt(j) - '0';
                np10 = np10 * p10[cur] % MODULO;
                nh = (nh * p10[cur] + h[cur]) % MODULO;
            }
            p10[src] = (int) np10;
            h[src] = (int) nh;
        }
        long res = 0;
        for (int i = 0; i < s.length(); ++i) {
            int cur = s.charAt(i) - '0';
            res = (res * p10[cur] + h[cur]) % MODULO;
        }
        out.println(res);
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

}
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Locale;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        Locale.setDefault(Locale.US);
        String who = in.next();
        int n = in.nextInt();
        int h = in.nextInt();
        if (who.equals("Bob")) {
            out.println(n);
            return;
        }
        double res = 1.0;
        double[][] pow = new double[h + 1][n + 1];
        double pr = 0.0;
        double p2 = 1.0;
        for (int i = 0; i <= h; ++i) {
            pow[i][0] = 1;
            for (int j = 1; j <= n; ++j)
                pow[i][j] = pow[i][j - 1] * pr;
            p2 *= 0.5;
            pr += p2;
        }
        p2 /= 0.5;
        for (int start = 0; start + 1 < n; ++start) {
            for (int sh = 0; sh <= h; ++sh) {
                double toAdd = 1 << sh;
                double cpr;
                if (sh == h) {
                    double prRight = 1.0 - pow[h][n - 1 - start];
                    cpr = p2 * prRight;
                } else {
                    cpr = (1.0 - pow[sh][1]) * (pow[sh + 1][n - 1 - start] - pow[sh][n - 1 - start]) + (1.0 - pow[sh + 1][n - 1 - start]) * (pow[sh + 1][1] - pow[sh][1]) * pow[sh + 1][start];
                }
                res += toAdd * cpr;
            }
        }
        out.println(String.format("%.12f", res));
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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
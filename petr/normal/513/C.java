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
        int n = in.nextInt();
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; ++i) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
        }
        double res = 0.0;
        int min = l[0];
        int max = r[0];
        for (int i = 0; i < n; ++i) {
            min = Math.min(l[i], min);
            max = Math.max(r[i], max);
        }
        for (int price = min; price <= max; ++price) {
            double cpr = 0;
            for (int winner = 0; winner < n; ++winner) {
                for (int second = 0; second < n; ++second) if (second != winner && l[second] <= price && r[second] >= price) {
                    int winnerAtLeast = Math.max(l[winner], (winner < second ? price : price + 1));
                    if (winnerAtLeast > r[winner]) continue;
                    double cur = r[winner] - winnerAtLeast + 1;
                    for (int i = 0; i < n; ++i) if (i != winner && i != second) {
                        int atMost = Math.min((i < second ? price - 1 : price), r[i]);
                        if (atMost < l[i]) {
                            cur = 0;
                            break;
                        }
                        cur *= atMost - l[i] + 1;
                    }
                    cpr += cur;
                }
            }
            res += cpr * price;
        }
        for (int i = 0; i < n; ++i) res /= r[i] - l[i] + 1;
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
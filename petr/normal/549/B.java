import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long finish = System.currentTimeMillis() + 500;
        int n = in.nextInt();
        int[][] toggle = new int[n][n];
        for (int i = 0; i < n; ++i) {
            String s = in.next();
            for (int j = 0; j < n; ++j) {
                toggle[i][j] = s.charAt(j) - '0';
            }
        }
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        Random random = new Random(54375315151L);
        while (System.currentTimeMillis() < finish) {
            int[] got = new int[n];
            for (int i = 0; i < n; ++i) got[i] = random.nextInt(2);
            int[] sum = new int[n];
            for (int i = 0; i < n; ++i) if (got[i] > 0) {
                for (int j = 0; j < n; ++j) {
                    sum[j] += toggle[i][j];
                }
            }
            long smallFinish = System.currentTimeMillis() + 20;
            while (System.currentTimeMillis() < smallFinish) {
                int cnt = 0;
                int which = -1;
                for (int i = 0; i < n; ++i) if (sum[i] == a[i]) {
                    ++cnt;
                    if (random.nextInt(cnt) == 0) which = i;
                }
                if (which < 0) {
                    int am = 0;
                    for (int i = 0; i < n; ++i) if (got[i] > 0) ++am;
                    out.println(am);
                    for (int i = 0; i < n; ++i) if (got[i] > 0) {
                        out.print((i + 1));
                        --am;
                        if (am > 0) out.print(" ");
                    }
                    out.println();
                    return;
                }
                got[which] ^= 1;
                for (int i = 0; i < n; ++i) {
                    sum[i] += (2 * got[which] - 1) * toggle[which][i];
                }
            }
        }
        out.println(-1);
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
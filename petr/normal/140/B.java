import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[][] pref = new int[n][n];
        int[][] prefRev = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pref[i][j] = in.nextInt() - 1;
                prefRev[i][pref[i][j]] = j;
            }
        }
        int[] alex = new int[n];
        int[] alexRev = new int[n];
        for (int i = 0; i < n; ++i) {
            alex[i] = in.nextInt() - 1;
            alexRev[alex[i]] = i;
        }
        int[] willSend = new int[n];
        Arrays.fill(willSend, n);
        int[] at = new int[n];
        Arrays.fill(at, -1);
        int best = n;
        int secondBest = n;
        for (int i = 0; i < n; ++i) {
            int cur = alexRev[i];
            if (cur < best) {
                secondBest = best;
                best = cur;
            } else if (cur < secondBest) {
                secondBest = cur;
            }
            int bestWho = best == n ? n : alex[best];
            int secondBestWho = secondBest == n ? n : alex[secondBest];
            for (int j = 0; j < n; ++j) {
                if (j != bestWho) {
                    if (bestWho != n) {
                        int gets = prefRev[j][bestWho];
                        if (gets < willSend[j]) {
                            willSend[j] = gets;
                            at[j] = i;
                        }
                    }
                } else {
                    if (secondBestWho != n) {
                        int gets = prefRev[j][secondBestWho];
                        if (gets < willSend[j]) {
                            willSend[j] = gets;
                            at[j] = i;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(at[i] + 1);
        }
        out.println();
	}
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

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
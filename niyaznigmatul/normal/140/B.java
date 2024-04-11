import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][in.nextInt() - 1] = j;
            }
        }
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[in.nextInt() - 1] = i;
        }
        int[] ans = new int[n];
        int[] whenToSend = new int[n];
        Arrays.fill(ans, -1);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                int currentBest = -1;
                for (int j = 0; j <= i; j++) {
                    if (j == k) {
                        continue;
                    }
                    if (currentBest < 0 || b[currentBest] > b[j]) {
                        currentBest = j;
                    }
                }
                if (ans[k] < 0 || a[k][ans[k]] > a[k][currentBest]) {
                    ans[k] = currentBest;
                    whenToSend[k] = i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            out.print(whenToSend[i] + 1 + " ");
        }
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    IOException happened;

    public FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                String line = br.readLine();
                st = new StringTokenizer(line);
            } catch (IOException e) {
                happened = e;
                return null;
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }
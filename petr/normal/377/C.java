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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] s = new int[n];
        for (int i = 0; i < n; ++i) {
            s[i] = in.nextInt();
        }
        Arrays.sort(s);
        for (int i = 0; i < n - 1 - i; ++i) {
            int t = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = t;
        }
        int m = in.nextInt();
        String[] action = new String[m];
        int[] team = new int[m];
        for (int i = 0; i < m; ++i) {
            action[i] = in.next();
            team[i] = in.nextInt() - 1;
        }
        int[] best = new int[1 << m];
        int[] nbest = new int[1 << m];
        for (int i = m - 1; i >= 0; --i) {
            if (team[i] == 0)
                Arrays.fill(nbest, -INF);
            else
                Arrays.fill(nbest, INF);
            for (int state = 0; state < best.length; ++state) {
                if (Integer.bitCount(state) != i) continue;
                for (int who = 0; who < m; ++who)
                    if ((state & (1 << who)) == 0) {
                        int nstate = state ^ (1 << who);
                        if (action[i].equals("b")) {
                            if (team[i] == 0)
                                nbest[state] = Math.max(nbest[state], best[nstate]);
                            else
                                nbest[state] = Math.min(nbest[state], best[nstate]);
                        } else {
                            if (team[i] == 0)
                                nbest[state] = Math.max(nbest[state], best[nstate] + s[who]);
                            else
                                nbest[state] = Math.min(nbest[state], best[nstate] - s[who]);
                        }
                    }
            }
            int[] tmp = best;
            best = nbest;
            nbest = tmp;
        }
        out.println(best[0]);
    }

    static final int INF = (int) 1e9;
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
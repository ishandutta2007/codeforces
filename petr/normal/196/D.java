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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final long BASE = 31371;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int d1 = in.nextInt();
        int d2 = d1 + 1;
        String s = in.next();
        int n = s.length();
        StringBuilder res = new StringBuilder();
        res.append(s);
        long[] hash = new long[n + 1];
        long[] hashRev = new long[n + 1];
        long[] basePow = new long[n + 1];
        basePow[0] = 1;
        for (int i = 0; i < n; ++i)
            basePow[i + 1] = basePow[i] * BASE;
        boolean bigger = false;
        int i = 0;
        while (i < n) {
            char min = res.charAt(i);
            int oldi = i;
            for (char ch = min; ch <= 'z'; ++ch) {
                if (!bigger && ch > min) {
                    bigger = true;
                    for (int ii = i + 1; ii < n; ++ii)
                        res.setCharAt(ii, 'a');
                }
                res.setCharAt(i, ch);
                hash[i + 1] = hash[i] * BASE + ch;
                hashRev[i + 1] = hashRev[i] + ch * basePow[i];
                boolean ok = true;
                if (i + 1 >= d1) {
                    if ((hash[i + 1] - hash[i + 1 - d1] * basePow[d1]) * basePow[i + 1 - d1] == (hashRev[i + 1] - hashRev[i + 1 - d1])) {
                        ok = false;
                    }
                }
                if (i + 1 >= d2) {
                    if ((hash[i + 1] - hash[i + 1 - d2] * basePow[d2]) * basePow[i + 1 - d2] == (hashRev[i + 1] - hashRev[i + 1 - d2])) {
                        ok = false;
                    }
                }
                if (ok && (bigger || i + 1 < n)) {
                    ++i;
                    break;
                }
            }
            if (i == oldi) {
                if (!bigger) {
                    for (int ii = i; ii < n; ++ii) res.setCharAt(ii, 'a');
                }
                res.setCharAt(i, 'a');
                --i;
                while (i >= 0 && res.charAt(i) == 'z') {
                    res.setCharAt(i, 'a');
                    --i;
                }
                if (i < 0) {
                    out.println("Impossible");
                    return;
                }
                res.setCharAt(i, (char) (res.charAt(i) + 1));
                bigger = true;
            }
        }
        out.println(res.toString());
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
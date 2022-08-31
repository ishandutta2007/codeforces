import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();
        String t = in.next();
        int[] sa = new int[s.length()];
        int[] ta = new int[t.length()];
        for (int i = 0; i < sa.length; ++i) sa[i] = "RGB".indexOf(s.charAt(i));
        for (int i = 0; i < ta.length; ++i) ta[i] = "RGB".indexOf(t.charAt(i));
        long res = sa.length * (long) ta.length;
        int[][] cs = new int[3][3];
        int[][] ct = new int[3][3];
        for (int i = 0; i + 1 < sa.length; ++i) {
            ++cs[sa[i]][sa[i + 1]];
        }
        for (int i = 0; i + 1 < ta.length; ++i) {
            ++ct[ta[i]][ta[i + 1]];
        }
        for (int u = 0; u < 3; ++u)
            for (int v = 0; v < 3; ++v)
                if (u != v)
                    res -= cs[u][v] * (long) ct[v][u];
        int pt = 0;
        for (int ps = 0; ps < s.length(); ++ps) {
            if (ps > 0)
                --cs[sa[ps - 1]][sa[ps]];
            if (s.charAt(ps) == t.charAt(pt)) {
                res -= s.length() - ps - 1;
                if (pt > 0 && ta[pt] != ta[pt - 1]) {
                    res += cs[ta[pt]][ta[pt - 1]];
                }
                ++pt;
                if (pt >= ta.length) break;
            }
        }
        int ps = 0;
        for (pt = 0; pt < t.length(); ++pt) {
            if (pt > 0)
                --ct[ta[pt - 1]][ta[pt]];
            if (s.charAt(ps) == t.charAt(pt)) {
                res -= t.length() - pt - 1;
                if (ps > 0 && sa[ps] != sa[ps - 1]) {
                    res += ct[sa[ps]][sa[ps - 1]];
                }
                ++ps;
                if (ps >= sa.length) break;
            }
        }
        out.println(res);
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

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

    }
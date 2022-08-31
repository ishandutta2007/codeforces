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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    int[] z_function (String s) {
        int n = s.length();
        int[] z = new int[n + 1];
        for (int i=1, l=0, r=0; i<n; ++i) {
            if (i <= r)
                z[i] = Math.min(r - i + 1, z[i - l]);
            while (i+z[i] < n && s.charAt(z[i]) == s.charAt(i+z[i]))
                ++z[i];
            if (i+z[i]-1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        String s = in.next();
        int[] z = z_function(s);
        int[] delta = new int[s.length() + 1];
        for (int ablen = 1; ablen * k <= s.length(); ++ablen) {
            int zz = z[ablen];
            if (zz >= ablen * (k - 1)) {
                ++delta[ablen * k];
                int right = Math.min((ablen) * (k + 1), ablen + zz);
                if (right + 1 < delta.length)
                    --delta[right + 1];
            }
        }
        StringBuilder b = new StringBuilder();
        int ss = 0;
        for (int i = 1; i <= s.length(); ++i) {
            ss += delta[i];
            if (ss > 0) b.append('1'); else b.append('0');
        }
        out.println(b.toString());
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
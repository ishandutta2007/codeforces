import java.util.Arrays;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        String[] names = new String[n];
        for (int i = 0; i < n; ++i) {
            names[i] = in.next();
        }
        boolean[][] less = new boolean[26][26];
        for (int i = 0; i + 1 < n; ++i) {
            int j;
            for (j = 0; j < Math.min(names[i].length(), names[i + 1].length()); ++j)
                if (names[i].charAt(j) != names[i + 1].charAt(j)) break;
            if (j >= names[i].length()) continue;
            if (j >= names[i + 1].length()) {
                out.println("Impossible");
                return;
            }
            less[names[i].charAt(j) - 'a'][names[i + 1].charAt(j) - 'a'] = true;
        }
        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                    if (less[i][k] && less[k][j]) less[i][j] = true;
        for (int i = 0; i < 26; ++i) if (less[i][i]) {
            out.println("Impossible");
            return;
        }
        int[] perm = new int[26];
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) if (less[j][i]) ++perm[i];
            perm[i] = perm[i] * 26 + i;
        }
        Arrays.sort(perm);
        for (int i = 0; i < 26; ++i) {
            out.print((char) ('a' + perm[i] % 26));
        }
        out.println();
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
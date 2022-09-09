import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashSet;
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
        String all = in.next();
        int []good = new int[26];
        for (int i = 0; i < 26; i++) {
            good[i] = (all.codePointAt(i) - 48);
        }
        int k = in.nextInt();
        int []sum = new int[s.length() + 2];
        int n = s.length();
        int lp = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + (1 - good[s.codePointAt(i) - 97]);
            if (s.charAt(i) == 'a')lp++;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            HashSet<String> hashSet = new HashSet<>();
            for (int j = 0; j + i <= n && j < n; j++) {
                String l = s.substring(j,j + i);
                if (sum[j + i] - sum[j] > k || hashSet.contains(l))continue;
                    hashSet.add(l);
            }
            cnt += hashSet.size();
        }
        out.print(cnt);
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
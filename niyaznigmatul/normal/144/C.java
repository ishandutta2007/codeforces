import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        String s = in.next();
        String t = in.next();
        int[] a = new int[26];
        for (char c : t.toCharArray()) {
            a[c - 'a']++;
        }
        if (s.length() < t.length()) {
            out.println(0);
            return;
        }
        int negatives = 0;
        for (int i = 0; i < t.length(); i++) {
            char c = s.charAt(i);
            if (c == '?') {
                continue;
            }
            if (a[c - 'a'] == 0) {
                negatives++;
            }
            a[c - 'a']--;
        }
        int ans = 0;
        if (negatives == 0) {
            ans++;
        }
        for (int i = t.length(); i < s.length(); i++) {
            char add = s.charAt(i - t.length());
            if (add != '?') {
                if (a[add - 'a'] == -1) {
                    negatives--;
                }
                a[add - 'a']++;
            }
            char remove = s.charAt(i);
            if (remove != '?') {
                if (a[remove - 'a'] == 0) {
                    negatives++;
                }
                a[remove - 'a']--;
            }
            if (negatives == 0) {
                ans++;
            }
        }
        out.println(ans);
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}
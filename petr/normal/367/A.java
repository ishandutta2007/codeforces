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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();
        int[] nx = new int[s.length() + 1];
        int[] ny = new int[s.length() + 1];
        int[] nz = new int[s.length() + 1];
        for (int i = 0; i < s.length(); ++i) {
            nx[i + 1] = nx[i];
            ny[i + 1] = ny[i];
            nz[i + 1] = nz[i];
            char ch = s.charAt(i);
            if (ch == 'x')
                ++nx[i + 1];
            else if (ch == 'y')
                ++ny[i + 1];
            else if (ch == 'z')
                ++nz[i + 1];
        }
        int m = in.nextInt();
        for (int i = 0; i < m; ++i) {
            int l = in.nextInt();
            int r = in.nextInt();
            if (r - l + 1 <= 2) {
                out.println("YES");
                continue;
            } 
            int cx = nx[r] - nx[l - 1];
            int cy = ny[r] - ny[l - 1];
            int cz = nz[r] - nz[l - 1];
            if (Math.max(cx, Math.max(cy, cz)) - Math.min(cx, Math.min(cy, cz)) <= 1) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }
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
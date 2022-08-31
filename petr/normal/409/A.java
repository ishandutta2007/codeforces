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
        String s1 = in.next();
        String s2 = in.next();
        int score = 0;
        for (int i = 0; i < s1.length(); i += 2) {
            String t = s1.substring(i, i + 2);
            int p1;
            if (t.equals("[]"))
                p1 = 0;
            else if (t.equals("()"))
                p1 = 1;
            else if (t.equals("8<"))
                p1 = 2;
            else
                throw new RuntimeException();
            t = s2.substring(i, i + 2);
            int p2;
            if (t.equals("[]"))
                p2 = 0;
            else if (t.equals("()"))
                p2 = 1;
            else if (t.equals("8<"))
                p2 = 2;
            else
                throw new RuntimeException();
            if ((p1 + 1) % 3 == p2)
                ++score;
            else if ((p2 + 1) % 3 == p1)
                --score;
        }
        if (score > 0) {
            out.println("TEAM 1 WINS");
        } else if (score < 0) {
            out.println("TEAM 2 WINS");
        } else {
            out.println("TIE");
        }
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

}
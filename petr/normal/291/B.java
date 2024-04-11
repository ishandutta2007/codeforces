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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String line = in.nextLine();
        StringBuilder b = new StringBuilder();
        b.append(' ');
        boolean inside = false;
        for (int i = 0; i < line.length(); ++i) {
            char ch = line.charAt(i);
            if (ch == ' ' && inside) ch = '_';
            if (ch == '"') {
                inside = !inside;
            }
            b.append(ch);
        }
        b.append(' ');
        line = b.toString();
        for (int i = 1; i < line.length(); ++i)
            if (line.charAt(i) != ' ' && line.charAt(i - 1) == ' ') {
                out.print('<');
                for (int j = i; line.charAt(j) != ' '; ++j) {
                    char ch = line.charAt(j);
                    if (ch == '_') ch = ' ';
                    if (ch != '"')
                        out.print(ch);
                }
                out.println('>');
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

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    }
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        switch (n) {
            case 5:
                out.println(">...v\n" +
                        "v.<..\n" +
                        "..^..\n" +
                        ">....\n" +
                        "..^.<\n" +
                        "1 1");
                break;

            case 3:
                out.println(">vv\n" +
                        "^<.\n" +
                        "^.<\n" +
                        "1 3");
                break;

            case 100:
                for (int i = 0; i < 49; ++i) {
                    out.print(">");
                }
                for (int i = 0; i < 25; ++i) {
                    out.print(">.");
                }
                out.println("v");
                for (int i = 0; i < 49; ++i) {
                    out.print("^v");
                    for (int j = 0; j < 24; ++j)
                        out.print(".<");
                    for (int j = 0; j < 50; ++j)
                        out.print("<");
                    out.println();
                    out.print("^");
                    for (int j = 0; j < 50; ++j)
                        out.print(">");
                    for (int j = 0; j < 24; ++j)
                        out.print(">.");
                    out.println("v");
                }
                out.print("^");
                for (int j = 0; j < 25; ++j)
                    out.print(".<");
                for (int j = 0; j < 49; ++j)
                    out.print("<");
                out.println();
                out.println("1 1");
                break;

            default:
                throw new RuntimeException();
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
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static final int MAX_ELEMENTS = 300000;
    
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int[] stack = new int[MAX_ELEMENTS];
        stack[0] = 0;
        int sp = 1;
        int n = 1;
        String[] elements = new String[MAX_ELEMENTS];
        elements[0] = "$";
        int[] parent = new int[MAX_ELEMENTS];
        String line = in.nextLine();
        for (int i = 0; i < line.length(); ++i) {
            if (line.charAt(i) == '<') {
                if (line.charAt(i + 1) == '/') {
                    if (sp < 1) throw new RuntimeException();
                    --sp;
                } else {
                    int j = i + 1;
                    while (line.charAt(j) >= 'a' && line.charAt(j) <= 'z') ++j;
                    elements[n] = line.substring(i + 1, j);
                    parent[n] = stack[sp - 1];
                    if (line.charAt(j) != '/') {
                        stack[sp++] = n;
                    }
                    ++n;
                }
            }
        }
        if (sp != 1) throw new RuntimeException();
        int numQueries = in.nextInt();
        int[] answer = new int[MAX_ELEMENTS];
        for (int i = 0; i < numQueries; ++i) {
            String req = in.nextLine();
            String[] parts = req.split(" ", -1);
            int size = parts.length;
            answer[0] = 0;
            int res = 0;
            for (int j = 1; j < n; ++j) {
                int pans = answer[parent[j]];
                if (parts[pans].equals(elements[j])) {
                    if (pans == size - 1)
                        ++res;
                    else
                        ++pans;
                }
                answer[j] = pans;
            }
            out.println(res);
        }
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

    public String nextLine() {
        if (tokenizer != null && tokenizer.hasMoreTokens()) {
            throw new RuntimeException();
        }
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
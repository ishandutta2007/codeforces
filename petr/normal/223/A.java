import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
        int[] stack = new int[s.length() + 10];
        Arrays.fill(stack, -1);
        int sp = 0;
        boolean[] hasPair = new boolean[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '[' || s.charAt(i) == '(') {
                stack[sp++] = i;
            } else {
                if (sp > 0 && ((s.charAt(i) == ')' && s.charAt(stack[sp - 1]) == '(') || (s.charAt(i) == ']' && s.charAt(stack[sp - 1]) == '['))) {
                    hasPair[i] = true;
                    hasPair[stack[sp - 1]] = true;
                    --sp;
                } else {
                    sp = 0;
                }
            }
        }
        int maxBrackets = 0;
        int maxLeft = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (hasPair[i] && (i == 0 || !hasPair[i - 1])) {
                int j;
                int numBrackets = 0;
                for (j = i; j < s.length(); ++j) {
                    if (!hasPair[j]) break;
                    if (s.charAt(j) == '[') ++numBrackets;
                }
                if (numBrackets > maxBrackets) {
                    maxBrackets = numBrackets;
                    maxLeft = i;
                    maxLen = j - i;
                }
            }
        }
        out.println(maxBrackets);
        out.println(s.substring(maxLeft, maxLeft + maxLen));
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

    }
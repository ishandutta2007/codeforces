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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        String s = in.next();
        int len = s.length();
        boolean[] evalIfAllFalse = new boolean[len];
        boolean[] evalIfAllTrue = new boolean[len];
        boolean[] triggersOnEvery = new boolean[len];
        boolean[] constantOnEvery = new boolean[len];
        boolean[] canBeFalse = new boolean[len];
        boolean[] canBeTrue = new boolean[len];
        int[] numArgs = new int[len];
        int[] openStack = new int[len];
        int[] opStack = new int[len];
        int sp = 0;
        for (int i = 0; i < len; ++i) {
            char ch = s.charAt(i);
            if (ch == '(') {
                openStack[sp++] = i;
            } else if (ch == '|' || ch == '&' || ch == '^') {
                opStack[sp - 1] = i;
            } else if (ch == ')') {
                --sp;
                int a1 = opStack[sp] - 1;
                int a2 = i - 1;
                char op = s.charAt(opStack[sp]);
                numArgs[i] = numArgs[a1] + numArgs[a2];
                if (op == '|') {
                    evalIfAllFalse[i] = evalIfAllFalse[a1] || evalIfAllFalse[a2];
                    evalIfAllTrue[i] = evalIfAllTrue[a1] || evalIfAllTrue[a2];
                    canBeFalse[i] = canBeFalse[a1] && canBeFalse[a2];
                    canBeTrue[i] = canBeTrue[a1] || canBeTrue[a2];
                    if (!canBeFalse[i]) {
                        triggersOnEvery[i] = false;
                        constantOnEvery[i] = true;
                    } else if (!canBeTrue[a1]) {
                        triggersOnEvery[i] = triggersOnEvery[a2];
                        constantOnEvery[i] = constantOnEvery[a2];
                    } else if (!canBeTrue[a2]) {
                        triggersOnEvery[i] = triggersOnEvery[a1];
                        constantOnEvery[i] = constantOnEvery[a1];
                    } else {
                        triggersOnEvery[i] = false;
                        constantOnEvery[i] = constantOnEvery[a1] && constantOnEvery[a2];
                    }
                } else if (op == '&') {
                    evalIfAllFalse[i] = evalIfAllFalse[a1] && evalIfAllFalse[a2];
                    evalIfAllTrue[i] = evalIfAllTrue[a1] && evalIfAllTrue[a2];
                    canBeFalse[i] = canBeFalse[a1] || canBeFalse[a2];
                    canBeTrue[i] = canBeTrue[a1] && canBeTrue[a2];
                    if (!canBeTrue[i]) {
                        triggersOnEvery[i] = false;
                        constantOnEvery[i] = true;
                    } else if (!canBeFalse[a1]) {
                        triggersOnEvery[i] = triggersOnEvery[a2];
                        constantOnEvery[i] = constantOnEvery[a2];
                    } else if (!canBeFalse[a2]) {
                        triggersOnEvery[i] = triggersOnEvery[a1];
                        constantOnEvery[i] = constantOnEvery[a1];
                    } else {
                        triggersOnEvery[i] = false;
                        constantOnEvery[i] = constantOnEvery[a1] && constantOnEvery[a2];
                    }
                } else if (op == '^') {
                    evalIfAllFalse[i] = evalIfAllFalse[a1] ^ evalIfAllFalse[a2];
                    evalIfAllTrue[i] = evalIfAllTrue[a1] ^ evalIfAllTrue[a2];
                    canBeTrue[i] = (canBeFalse[a1] && canBeTrue[a2]) || (canBeTrue[a1] && canBeFalse[a2]);
                    canBeFalse[i] = (canBeFalse[a1] && canBeFalse[a2]) || (canBeTrue[a1] && canBeTrue[a2]);
                    if ((triggersOnEvery[a1] && constantOnEvery[a2]) || (triggersOnEvery[a2] && constantOnEvery[a1])) {
                        triggersOnEvery[i] = true;
                        constantOnEvery[i] = false;
                    } else if ((triggersOnEvery[a1] && triggersOnEvery[a2]) || (constantOnEvery[a1] && constantOnEvery[a2])) {
                        triggersOnEvery[i] = false;
                        constantOnEvery[i] = true;
                    } else {
                        triggersOnEvery[i] = false;
                        constantOnEvery[i] = false;
                    }
                } else throw new RuntimeException();
            } else if (ch == '0') {
                evalIfAllFalse[i] = false;
                evalIfAllTrue[i] = false;
                triggersOnEvery[i] = false;
                constantOnEvery[i] = true;
                canBeFalse[i] = true;
                canBeTrue[i] = false;
                numArgs[i] = 0;
            } else if (ch == '1') {
                evalIfAllFalse[i] = true;
                evalIfAllTrue[i] = true;
                triggersOnEvery[i] = false;
                constantOnEvery[i] = true;
                canBeFalse[i] = false;
                canBeTrue[i] = true;
                numArgs[i] = 0;
            } else if (ch == '?') {
                evalIfAllFalse[i] = false;
                evalIfAllTrue[i] = true;
                triggersOnEvery[i] = true;
                constantOnEvery[i] = false;
                canBeFalse[i] = true;
                canBeTrue[i] = true;
                numArgs[i] = 1;
            } else throw new RuntimeException();
        }
        if (sp != 0) throw new RuntimeException();
        if (!canBeFalse[len - 1] || !canBeTrue[len - 1]) {
            out.println("NO");
        } else if (evalIfAllFalse[len - 1] != evalIfAllTrue[len - 1]) {
            out.println("YES");
        } else if (constantOnEvery[len - 1]) {
            out.println("NO");
        } else {
            out.println("YES");
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

    }
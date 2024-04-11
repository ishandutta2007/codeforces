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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    public static final String EVEN_PLAYER = "Daenerys";
    public static final String ODD_PLAYER = "Stannis";

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int n0 = 0;
        int n1 = 0;
        for (int i = 0; i < n; ++i) {
            if (in.nextInt() % 2 == 0) ++n0; else ++n1;
        }
        if (n == k) {
            if (n1 % 2 == 0) {
                out.println(EVEN_PLAYER);
            } else {
                out.println(ODD_PLAYER);
            }
            return;
        }
        String last;
        String nonLast;
        if ((n - k) % 2 == 0) {
            last = EVEN_PLAYER;
            nonLast = ODD_PLAYER;
        } else {
            last = ODD_PLAYER;
            nonLast = EVEN_PLAYER;
        }
        int movesLast = (n - k + 1) / 2;
        int movesNonLast = (n - k) / 2;
        if (movesLast == movesNonLast) {
            if (lastWins(movesLast, n0, n1, last)) {
                out.println(last);
            } else {
                out.println(nonLast);
            }
        } else {
            if (n0 > 0 && lastWins(movesNonLast, n0 - 1, n1, last)) {
                out.println(last);
            } else if (n1 > 0 && lastWins(movesNonLast, n0, n1 - 1, last)) {
                out.println(last);
            } else {
                out.println(nonLast);
            }
        }
    }

    private boolean lastWins(int moves, int n0, int n1, String lastIs) {
        if (n0 > moves && n1 > moves) return true;
        if (n0 + n1 == 2 * moves) return lastIs.equals(EVEN_PLAYER);
        if (n0 <= moves) {
            int rem = (n1 + n0 - 2 * moves);
            return (rem % 2 != 0) ^ lastIs.equals(EVEN_PLAYER);
        }
        if (n1 <= moves) {
            return lastIs.equals(EVEN_PLAYER);
        }
        throw new RuntimeException();
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
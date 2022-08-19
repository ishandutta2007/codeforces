import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskE {
    int firstSmallMultiple(int mult, int modulo, int upto) {
        mult %= modulo;
        if (mult <= upto)
            return 1;
        if (upto == 0)
            return modulo;
        return (int) ((firstLargeMultiple(modulo, mult, mult - upto) * (long) modulo + mult - 1) / mult);
    }

    private int firstLargeMultiple(int mult, int modulo, int atleast) {
        mult %= modulo;
        if (atleast == 0) throw new RuntimeException();
        if (mult == 0)
            return modulo;
        if ((atleast + mult - 1) / mult * mult <= modulo)
            return (atleast + mult - 1) / mult;
        return (int) ((firstSmallMultiple(modulo, mult, modulo - atleast) * (long) modulo + atleast - modulo + mult - 1) / mult);
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int a = in.nextInt();
        int n = in.nextInt();
        int p = in.nextInt();
        int h = in.nextInt();
        a %= p;
        int left = firstSmallMultiple(a, p, h);
        int right = firstSmallMultiple(p - a, p, h);
        int atleast = Math.max(0, n - left + 1);
        int atmost = Math.min(n, right - 1);
        if (atleast < atmost) {
            out.println("NO");
            return;
        }
        if (atleast > atmost) {
            out.println("YES");
            return;
        }
        int max = p - firstSmallMultiple(BigInteger.valueOf(p - a).modInverse(BigInteger.valueOf(p)).intValue(), p, n);
        if ((atleast * (long) a) % p == max) {
            out.println("YES");
        } else {
            out.println("NO");
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
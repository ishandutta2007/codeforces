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
        int x = in.nextInt();
        if (x == 2) {
            out.println(-1);
        } else if (n == 1) {
            out.println(x - 1);
        } else {
            int tmp = n + 1;
            for (int i = 2; i * i <= tmp; ++i)
                if (tmp % i == 0) {
                    out.println(-1);
                    return;
                }
            tmp = n;
            int[] divs = new int[100];
            int ndivs = 0;
            for (int i = 2; i * i <= tmp; ++i)
                if (tmp % i == 0) {
                    divs[ndivs++] = i;
                    while (tmp % i == 0) tmp /= i;
                }
            if (tmp > 1) {
                divs[ndivs++] = tmp;
            }
            int gen = 2;
            while (true) {
                boolean ok = true;
                if (pow(gen, n, n + 1) != 1) ok = false;
                for (int i = 0; i < ndivs && ok; ++i) {
                    if (pow(gen, n / divs[i], n + 1) == 1) {
                        ok = false;
                    }
                }
                if (ok) break;
                ++gen;
            }
            long prod = 1;
            long res = -1;
            for (int pow = 0; pow < n; ++pow) {
                if (gcd(pow, n) == 1) {
                    if (prod < x) {
                        long got = prod + (x - 1 - prod) / (n + 1) * (n + 1);
                        if (got > res)
                            res = got;
                    }
                }
                prod = prod * gen % (n + 1); 
            }
            out.println(res);
        }
    }

    private int gcd(int a, int b) {
        while (b > 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    private long pow(long a, long k, long b) {
        if (k == 0) {
            return 1 % b;
        }
        if (k % 2 == 0) {
            return pow(a * a % b, k / 2, b);
        }
        return a * pow(a, k - 1, b) % b;
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
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        int[] b = new int[m];
        for (int i = 0; i < m; ++i) {
            b[i] = in.nextInt();
        }
        int[] pgcd = new int[n];
        pgcd[0] = a[0];
        for (int i = 1; i < n; ++i) {
            pgcd[i] = gcd(pgcd[i - 1], a[i]);
        }
        int upto = 32000;
        boolean[] prime = new boolean[upto];
        Arrays.fill(prime, true);
        for (int i = 2; i * i < upto; ++i) if (prime[i])
            for (int j = i * i; j < upto; j += i) prime[j] = false;
        int cnt = 0;
        for (int i = 2; i < upto; ++i) if (prime[i]) ++cnt;
        int[] smallPrimes = new int[cnt];
        cnt = 0;
        for (int i = 2; i < upto; ++i) if (prime[i]) smallPrimes[cnt++] = i;
        if (cnt != smallPrimes.length) throw new RuntimeException();
        boolean[] isBad = new boolean[cnt];
        int ptr = 0;
        for (int i = 0; i < cnt; ++i) {
            while (ptr < m && b[ptr] < smallPrimes[i]) ++ptr;
            isBad[i] = ptr < m && b[ptr] == smallPrimes[i];
        }
        int divBy = 1;
        long delta = 0;
        for (int i = n - 1; i >= 0; --i) {
            int cur = pgcd[i] / divBy;
            int s = score(cur, b, smallPrimes, isBad);
            if (s < 0) {
                delta -= s * (i + 1);
                divBy *= cur;
            }
        }
        for (int i = 0; i < n; ++i)
            delta += score(a[i], b, smallPrimes, isBad);
        out.println(delta);
    }

    private int score(int x, int[] b, int[] smallPrimes, boolean[] isBad) {
        int res = 0;
        for (int i = 0; i < smallPrimes.length; ++i) {
            int delta = isBad[i] ? -1 : 1;
            int y = smallPrimes[i];
            while (x % y == 0) {
                x /= y;
                res += delta;
            }
        }
        if (x > 1) {
            if (Arrays.binarySearch(b, x) >= 0) --res; else ++res;
        }
        return res;
    }

    int gcd(int a, int b) {
        while (b > 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
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
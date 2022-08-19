import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
    static final long MAX_COORD = (int) 1e5 + 1;
    static final int MAX_HASH = 1 << 20;

    long[] existing;
    int[] nextSameHash;
    int[] firstByHash;
    long hashZ;
    boolean check(int x, int y, int size) {
        if (size <= 0 || x < 0 || y < 0 || x + size >= MAX_COORD || y + size >= MAX_COORD) return false;
        {
            long key = (x + size) * MAX_COORD + y;
            long h = (x + size) * hashZ + y;
            int ih = (int) ((h ^ (h >> 20) ^ (h >> 40) ^ (h >> 60)) & (MAX_HASH - 1));
            int cur = firstByHash[ih];
            boolean ok = false;
            while (cur >= 0) {
                if (existing[cur] == key) {
                    ok = true;
                    break;
                }
                cur = nextSameHash[cur];
            }
            if (!ok) return false;
        }
        {
            long key = (x + size) * MAX_COORD + (y + size);
            long h = (x + size) * hashZ + (y + size);
            int ih = (int) ((h ^ (h >> 20) ^ (h >> 40) ^ (h >> 60)) & (MAX_HASH - 1));
            int cur = firstByHash[ih];
            boolean ok = false;
            while (cur >= 0) {
                if (existing[cur] == key) {
                    ok = true;
                    break;
                }
                cur = nextSameHash[cur];
            }
            if (!ok) return false;
        }
        {
            long key = x * MAX_COORD + (y + size);
            long h = x * hashZ + (y + size);
            int ih = (int) ((h ^ (h >> 20) ^ (h >> 40) ^ (h >> 60)) & (MAX_HASH - 1));
            int cur = firstByHash[ih];
            boolean ok = false;
            while (cur >= 0) {
                if (existing[cur] == key) {
                    ok = true;
                    break;
                }
                cur = nextSameHash[cur];
            }
            if (!ok) return false;
        }
        return true;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        Random random = new Random(543715431L + System.currentTimeMillis());
        int n = in.nextInt();
        hashZ = random.nextLong() * 2 + 1;
        int[] x = new int[n];
        int[] y = new int[n];
        existing = new long[n];
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
            existing[i] = x[i] * (long) MAX_COORD + y[i];
        }
        for (int i = 0; i < n; ++i) {
            int j = random.nextInt(n - i) + i;
            long t = existing[i];
            existing[i] = existing[j];
            existing[j] = t;
        }
        Arrays.sort(existing);
        for (int i = 0; i < n; ++i) {
            x[i] = (int) (existing[i] / MAX_COORD);
            y[i] = (int) (existing[i] % MAX_COORD);
        }
        nextSameHash = new int[n];
        firstByHash = new int[MAX_HASH];
        Arrays.fill(firstByHash, -1);
        for (int i = 0; i < n; ++i) {
            long h = x[i] * hashZ + y[i];
            int ih = (int) ((h ^ (h >> 20) ^ (h >> 40) ^ (h >> 60)) & (MAX_HASH - 1));
            nextSameHash[i] = firstByHash[ih];
            firstByHash[ih] = i;
        }
        int[] countX = new int[(int) MAX_COORD];
        int[] countY = new int[(int) MAX_COORD];
        int[] countXminusY = new int[(int) (2 * MAX_COORD)];
        int[] firstX = new int[(int) MAX_COORD];
        int[] firstY = new int[(int) MAX_COORD];
        int[] firstXminusY = new int[(int) (2 * MAX_COORD)];
        Arrays.fill(firstX, -1);
        Arrays.fill(firstY, -1);
        Arrays.fill(firstXminusY, -1);
        int[] nextX = new int[n];
        int[] nextY = new int[n];
        int[] nextXminusY = new int[n];
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            int cx = countX[x[i]];
            int cy = countY[y[i]];
            int cxmy = countXminusY[((int) (x[i] - y[i] + MAX_COORD))];
            if (cx <= cy && cx <= cxmy) {
                int cur = firstX[x[i]];
                while (cur >= 0) {
                    if (check(x[i], y[i], y[cur] - y[i])) ++res;
                    cur = nextX[cur];
                }
            } else if (cy <= cxmy) {
                int cur = firstY[y[i]];
                while (cur >= 0) {
                    if (check(x[i], y[i], x[cur] - x[i])) ++res;
                    cur = nextY[cur];
                }
            } else {
                int cur = firstXminusY[((int) (x[i] - y[i] + MAX_COORD))];
                while (cur >= 0) {
                    if (check(x[i], y[i], x[cur] - x[i])) ++res;
                    cur = nextXminusY[cur];
                }
            }
            ++countX[x[i]];
            ++countY[y[i]];
            ++countXminusY[((int) (x[i] - y[i] + MAX_COORD))];
            nextX[i] = firstX[x[i]];
            firstX[x[i]] = i;
            nextY[i] = firstY[y[i]];
            firstY[y[i]] = i;
            nextXminusY[i] = firstXminusY[((int) (x[i] - y[i] + MAX_COORD))];
            firstXminusY[((int) (x[i] - y[i] + MAX_COORD))] = i;
        }
        out.println(res);
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
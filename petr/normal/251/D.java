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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long[] a = new long[n];
        long overall = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextLong();
            overall ^= a[i];
        }
        long rhs = 0;
        int[] which = new int[63];
        for (int stage = 0; stage < 2; ++stage) {
        for (int bit = 62; bit >= 0; --bit) {
            if (((overall >> bit) & 1) != stage) continue;
            long need = 1L << bit;
            long rhs1 = rhs ^ need;
            int bi = -1;
            for (int i = 0; i < n; ++i) if ((a[i] & need) != 0) {
                bi = i;
                break;
            }
            if (bi < 0) {
                if ((rhs1 & need) == 0)
                    rhs = rhs1;
            } else {
                which[bit] = bi;
                rhs = rhs1;
                for (int obit = 0; obit < 63; ++obit) {
                    long oneed = 1L << obit;
                    if (obit != bit) {
                        if ((a[bi] & oneed) != 0) {
                            for (int i = 0; i < n; ++i)
                                if ((a[i] & need) != 0)
                                    a[i] ^= oneed;
                            if ((rhs & need) != 0)
                                rhs ^= oneed;
                        }
                    }
                }
            }
        }
        }
        int[] res = new int[n];
        Arrays.fill(res, 1);
        for (int i = 0; i < 63; ++i) {
            if ((rhs & (1L << i)) != 0)
                ++res[which[i]];
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[i]);
        }
        out.println();
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

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

    public long nextLong() {
        return Long.parseLong(next());
    }
}
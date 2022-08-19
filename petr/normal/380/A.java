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

    public static final int MAXONE = 100000;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int m = in.nextInt();
        int[] seq = new int[2 * MAXONE];
        int nseq = 0;
        int[] seq2l = new int[200000];
        int[] seq2c = new int[200000];
        int[] seq2x = new int[200000];
        Arrays.fill(seq2x, -1);
        int nseq2 = 0;
        int i;
        for (i = 0; i < m && nseq < MAXONE; ++i) {
            int kind = in.nextInt();
            if (kind == 1) {
                seq[nseq++] = in.nextInt();
            } else {
                int len = in.nextInt();
                int times = in.nextInt();
                while (times > 0 && nseq < MAXONE) {
                    System.arraycopy(seq, 0, seq, nseq, len);
                    nseq += len;
                    --times;
                }
                if (times > 0) {
                    seq2l[nseq2] = len;
                    seq2c[nseq2] = times;
                    ++nseq2;
                }
            }
        }
        for (; i < m; ++i) {
            int kind = in.nextInt();
            if (kind == 1) {
                seq2x[nseq2++] = in.nextInt();
            } else {
                seq2l[nseq2] = in.nextInt();
                seq2c[nseq2++] = in.nextInt();
            }
        }
        int n = in.nextInt();
        long[] know = new long[n];
        for (i = 0; i < n; ++i) {
            know[i] = in.nextLong() - 1;
        }
        i = 0;
        while (i < n && know[i] < nseq) {
            if (i > 0) out.print(" ");
            out.print(seq[((int) know[i])]);
            ++i;
        }
        long offset = nseq;
        for (int j = 0; j < nseq2; ++j) {
            if (seq2x[j] >= 0) {
                while (i < n && know[i] == offset) {
                    if (i > 0) out.print(" ");
                    out.print(seq2x[j]);
                    ++i;
                }
                ++offset;
            } else {
                long nextoffset = offset + seq2l[j] * (long) seq2c[j];
                while (i < n && know[i] < nextoffset) {
                    if (i > 0) out.print(" ");
                    out.print(seq[((int) ((know[i] - offset) % seq2l[j]))]);
                    ++i;
                }
                offset = nextoffset;
            }
        }
        if (i != n) throw new RuntimeException();
        out.println();
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }
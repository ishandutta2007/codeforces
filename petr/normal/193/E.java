import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
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
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static final long MODULO = (long) 1e13;

    private long[][] mul(long[][] a, long[][] b, long modulo) {
        long[][] c = new long[2][2];
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j) {
                BigInteger sum = BigInteger.ZERO;
                for (int k = 0; k < 2; ++k)
                    sum = sum.add(BigInteger.valueOf(a[i][k]).multiply(BigInteger.valueOf(b[k][j])));
                c[i][j] = sum.mod(BigInteger.valueOf(modulo)).longValue();
            }
        return c;
    }
    
    static class Candidate {
        long offset;
        long[][] trans;

        Candidate(long offset, long[][] trans) {
            this.offset = offset;
            this.trans = trans;
        }
    }
    
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long f = in.nextLong();
        long mod = 1;
        long period = 1;
        long[][] mPeriod = new long[][]{new long[]{0, 1}, new long[]{1, 1}};
        List<Candidate> offsets = new ArrayList<Candidate>();
        offsets.add(new Candidate(0, new long[][]{new long[]{1, 0}, new long[]{0, 1}}));
        for (int i = 0; i < 26; ++i) {
            if (i < 13)
                mod *= 2;
            else
                mod *= 5;
            long nperiod = period;
            long[][] nmPeriod = mPeriod;
            while (nmPeriod[0][1] % mod != 0 || nmPeriod[1][1] % mod != 1) {
                nmPeriod = mul(nmPeriod, mPeriod, MODULO);
                nperiod += period;
            }
            List<Candidate> newOffsets = new ArrayList<Candidate>();
            for (Candidate old : offsets) {
                long[][] trans = old.trans;
                for (long noffset = old.offset; noffset < nperiod; noffset += period) {
                    if ((trans[0][1] % mod == f % mod)) {
                        newOffsets.add(new Candidate(noffset, trans));
                    }
                    trans = mul(trans, mPeriod, MODULO);
                }
            }
            offsets = newOffsets;
            period = nperiod;
            mPeriod = nmPeriod;
        }
        long min = Long.MAX_VALUE;
        for (Candidate c : offsets)
            min = Math.min(min, c.offset);
        if (min == Long.MAX_VALUE) out.println(-1); else out.println(min);
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }
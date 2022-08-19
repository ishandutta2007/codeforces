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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextInt();
        }
        int[] y = new int[n];
        for (int i = 0; i < n; ++i) {
            y[i] = in.nextInt();
        }
        int reslen = 0;
        int[] resi = new int[(int) 1e6 + 10];
        int[] resj = new int[(int) 1e6 + 10];
        int[] importantBit = new int[n];
        int[] importantByBit = new int[30];
        Arrays.fill(importantBit, -1);
        Arrays.fill(importantByBit, -1);
        for (int i = 0; i < n; ++i) {
            if (x[i] != 0) {
                importantBit[i] = Integer.numberOfTrailingZeros(x[i]);
                importantByBit[importantBit[i]] = i;
                for (int j = 0; j < n; ++j) {
                    if (i != j && (x[j] & (1 << importantBit[i])) != 0) {
                        resi[reslen] = j;
                        resj[reslen] = i;
                        x[resi[reslen]] ^= x[resj[reslen]];
                        ++reslen;
                    }
                }
            }
        }
        int[] submatr = new int[30];
        for (int i = 0; i < n; ++i) {
            int w = 0;
            for (int j = 0; j < 30; ++j) if (importantByBit[j] >= 0) {
                if ((y[i] & (1 << j)) != 0) {
                    w ^= x[importantByBit[j]];
                    if (importantBit[i] < 0) {
                        resi[reslen] = i;
                        resj[reslen] = importantByBit[j];
                        x[resi[reslen]] ^= x[resj[reslen]];
                        ++reslen;
                    } else {
                        submatr[importantBit[i]] += 1 << j;
                    }
                }
            }
            if (w != y[i]) {
                out.println(-1);
                return;
            }
        }

        int revlen = 0;
        int[] revi = new int[(int) 1e6 + 10];
        int[] revj = new int[(int) 1e6 + 10];
        int[] subImportantBit = new int[30];
        int[] subImportantByBit = new int[30];
        Arrays.fill(subImportantBit, -1);
        Arrays.fill(subImportantByBit, -1);
        for (int i = 0; i < 30; ++i) if (submatr[i] != 0) {
            subImportantBit[i] = Integer.numberOfTrailingZeros(submatr[i]);
            subImportantByBit[subImportantBit[i]] = i;
            for (int j = 0; j < 30; ++j) {
                if (i != j && (submatr[j] & (1 << subImportantBit[i])) != 0) {
                    submatr[j] ^= submatr[i];
                    revi[revlen] = j;
                    revj[revlen] = i;
                    ++revlen;
                }
            }
        }

        int[] perm = new int[30];
        int[] rperm = new int[30];
        Arrays.fill(perm, -1);
        Arrays.fill(rperm, -1);
        for (int i = 0; i < 30; ++i) if (subImportantByBit[i] >= 0) {
            perm[i] = subImportantByBit[i];
            rperm[perm[i]] = i;
        }
        for (int i = 0; i < 30; ++i) if (importantByBit[i] >= 0 && perm[i] < 0) {
            for (int j = 0; j < 30; ++j) if (importantByBit[j] >= 0 && rperm[j] < 0) {
                perm[i] = j;
                rperm[j] = i;
                break;
            }
        }

        boolean[] mark = new boolean[30];
        for (int i = 0; i < 30; ++i) if (!mark[i] && importantByBit[i] >= 0) {
            int we = i;
            mark[i] = true;
            while (perm[we] != i) {
                int dest = perm[we];
                mark[dest] = true;
                resi[reslen] = importantByBit[i];
                resj[reslen] = importantByBit[dest];
                x[resi[reslen]] ^= x[resj[reslen]];
                ++reslen;
                resj[reslen] = importantByBit[i];
                resi[reslen] = importantByBit[dest];
                x[resi[reslen]] ^= x[resj[reslen]];
                ++reslen;
                resi[reslen] = importantByBit[i];
                resj[reslen] = importantByBit[dest];
                x[resi[reslen]] ^= x[resj[reslen]];
                ++reslen;
                we = dest;
            }
        }

        for (int i = 0; i < 30; ++i) if (subImportantBit[i] >= 0) {
            for (int j = 0; j < 30; ++j) if (importantByBit[j] >= 0 && subImportantByBit[j] < 0) {
                if ((submatr[i] & (1 << j)) != 0) {
                    resi[reslen] = importantByBit[i];
                    resj[reslen] = importantByBit[perm[j]];
                    x[resi[reslen]] ^= x[resj[reslen]];
                    ++reslen;
                }
            }
        }

        for (int j = 0; j < 30; ++j) if (importantByBit[j] >= 0 && subImportantByBit[j] < 0) {
            resi[reslen] = importantByBit[perm[j]];
            resj[reslen] = importantByBit[perm[j]];
            x[resi[reslen]] ^= x[resj[reslen]];
            ++reslen;
        }

        for (int i = revlen - 1; i >= 0; --i) {
            resi[reslen] = importantByBit[revi[i]];
            resj[reslen] = importantByBit[revj[i]];
            x[resi[reslen]] ^= x[resj[reslen]];
            ++reslen;
        }

        for (int i = 0; i < n; ++i) if (x[i] != y[i]) throw new RuntimeException();
        out.println(reslen);
        for (int i = 0; i < reslen; ++i) {
            out.println((resi[i] + 1) + " " + (resj[i] + 1));
        }
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}
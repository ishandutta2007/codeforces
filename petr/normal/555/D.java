import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] xUnsorted = new int[n];
        for (int i = 0; i < n; ++i) {
            xUnsorted[i] = in.nextInt();
        }
        int[] x = xUnsorted.clone();
        Random random = new Random(543715473531L + System.currentTimeMillis());
        for (int i = 0; i < n; ++i) {
            int j = i + random.nextInt(n - i);
            int tmp = x[i];
            x[i] = x[j];
            x[j] = tmp;
        }
        Arrays.sort(x);
        int[] ansForX = new int[x.length];
        for (int i = 0; i < n; ++i) {
            ansForX[Arrays.binarySearch(x, xUnsorted[i])] = i + 1;
        }

        for (int i = 0; i < m; ++i) {
            int sx = xUnsorted[in.nextInt() - 1];
            sx += in.nextInt();
            boolean bottom = true;

            int pAround = -1;
            int ppAround = -1;
            int psx = -1;
            int ppsx = -1;

            while (true) {
                int left = -1;
                int right = x.length;
                while (right - left > 1) {
                    int mid = (left + right) >> 1;
                    if (bottom) {
                        if (x[mid] <= sx) {
                            left = mid;
                        } else {
                            right = mid;
                        }
                    } else {
                        if (x[mid] < sx) {
                            left = mid;
                        } else {
                            right = mid;
                        }
                    }
                }
                int around;
                if (bottom) {
                    around = left;
                } else {
                    around = right;
                }

                if (around == ppAround) {
                    if (sx == ppsx) {
                        out.println(ansForX[around]);
                        break;
                    }
                    int period = Math.abs(sx - ppsx);
                    int freedom = Math.abs(x[around] - sx);
                    int whole = freedom / period;
                    if (sx > ppsx) {
                        sx += whole * period;
                    } else {
                        sx -= whole * period;
                    }
                }

                ppAround = pAround;
                ppsx = psx;
                pAround = around;
                psx = sx;

                sx = x[around] + (x[around] - sx);
                bottom = !bottom;
            }
        }
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
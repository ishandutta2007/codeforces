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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int q = in.nextInt();
        int[] a = new int[3 * n];
        long s = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            s += a[i];
        }
        for (int i = n; i < 3 * n; ++i) {
            a[i] = a[i - n];
        }
        int[] stop = new int[n];
        int[] oldstop = new int[n];
        long[] sum = new long[n];

        outer: for (int qi = 0; qi < q; ++qi) {
            long b = in.nextLong();
            if (s <= b) {
                out.println(1);
                continue;
            }
            int cnt = 0;
            long cs = 0;
            for (int i = 0;; ++i) {
                long ns = cs + a[i];
                if (ns > b) {
                    stop[cnt] = i;
                    sum[cnt++] = cs;
                    if (i >= n) break;
                    ns = a[i];
                }
                cs = ns;
            }
            if (stop[cnt - 1] >= stop[0] + n) {
                out.println(cnt - 1);
                continue outer;
            }
            System.arraycopy(stop, 0, oldstop, 0, cnt);
            int atmost = stop[0];
            int over = stop[cnt - 1];
            for (int start = 1; start < atmost; ++start) {
                if (start > 0) {
                    sum[0] -= a[start - 1];
                }
                for (int i = 0; i < cnt; ++i) {
                    boolean any = false;
                    while (sum[i] + a[stop[i]] <= b) {
                        any = true;
                        sum[i] += a[stop[i]];
                        if (i + 1 < cnt)
                            sum[i + 1] -= a[stop[i]];
                        ++stop[i];
                    }
                    if (!any) break;
                    if (i + 1 < cnt && stop[i] == oldstop[i + 1]) {
                        if (over >= start + n) {
                            out.println(cnt - 1);
                            continue outer;
                        }
                        out.println(cnt);
                        continue outer;
                    }
                }
                if (stop[cnt - 1] >= stop[0] + n) {
                    out.println(cnt - 1);
                    continue outer;
                }
            }
            out.println(cnt);
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

    public long nextLong() {
        return Long.parseLong(next());
    }

}
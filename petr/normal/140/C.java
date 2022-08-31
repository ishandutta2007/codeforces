import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] r = new int[n];
        for (int i = 0; i < n; ++i) {
            r[i] = in.nextInt();
        }
        Arrays.sort(r);
        int[] what = new int[n];
        int[] count = new int[n];
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || r[i] != r[i - 1]) {
                what[cnt] = r[i];
                count[cnt] = 1;
                ++cnt;
            } else ++count[cnt - 1];
        }
        int[] next = new int[n + n + 1];
        int[] prev = new int[n + n + 1];
        for (int i = 0; i <= n; ++i) {
            next[i + n] = i + n;
            prev[i + n] = i + n;
        }
        for (int i = 0; i < cnt; ++i) {
            prev[i] = count[i] + n;
            next[i] = next[count[i] + n];
            prev[next[i]] = i;
            next[prev[i]] = i;
        }
        int[] nextNonEmpty = new int[n + 2];
        int[] prevNonEmpty = new int[n + 2];
        nextNonEmpty[n + 1] = n + 1;
        prevNonEmpty[n + 1] = n + 1;
        for (int i = 0; i <= n; ++i)
            if (next[i + n] != i + n) {
                prevNonEmpty[i] = n + 1;
                nextNonEmpty[i] = nextNonEmpty[n + 1];
                prevNonEmpty[nextNonEmpty[i]] = i;
                nextNonEmpty[prevNonEmpty[i]] = i;
            }
        List<String> res = new ArrayList<String>();
        int[] cur = new int[3];
        while (true) {
            int tmp = nextNonEmpty[n + 1];
            boolean ok = true;
            int tmpPos = tmp + n;
            for (int i = 0; i < 3; ++i) {
                if (tmp == 0 || tmp == n + 1) {
                    ok = false;
                    break;
                }
                tmpPos = next[tmpPos];
                if (tmpPos == tmp + n) {
                    tmp = nextNonEmpty[tmp];
                    if (tmp == 0 || tmp == n + 1) {
                        ok = false;
                        break;
                    }
                    tmpPos = next[tmp + n];
                    if (tmpPos == tmp + n) throw new RuntimeException();
                }
                cur[i] = tmpPos;
            }
            if (!ok) break;
            Arrays.sort(cur);
            res.add((what[cur[2]]) + " " + (what[cur[1]]) + " " + (what[cur[0]]));
            for (int i = 0; i < 3; ++i) {
                int x = cur[i];
                int y = count[x];
                next[prev[x]] = next[x];
                prev[next[x]] = prev[x];
                next[x] = next[y - 1 + n];
                prev[x] = y - 1 + n;
                next[prev[x]] = x;
                prev[next[x]] = x;
                if (next[x] == prev[x]) {
                    nextNonEmpty[y - 1] = nextNonEmpty[y];
                    prevNonEmpty[y - 1] = y;
                    nextNonEmpty[prevNonEmpty[y - 1]] = y - 1;
                    prevNonEmpty[nextNonEmpty[y - 1]] = y - 1;
                }
                if (next[y + n] == y + n) {
                    nextNonEmpty[prevNonEmpty[y]] = nextNonEmpty[y];
                    prevNonEmpty[nextNonEmpty[y]] = prevNonEmpty[y];
                }
                count[x] = y - 1;
            }
        }
        out.println(res.size());
        for (String x : res) {
            out.println(x);
        }
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }
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
    static Random random = new Random(54715431L);
    static final int INF = (int) 2e9;
    
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = in.nextInt();
            }
        }
        int[][] sa = new int[n][];
        int[][] saind = new int[n][m];
        int[] pa = new int[n];
        int[] cnt = new int[n];
        int[] va = new int[n];
        for (int i = 0; i < n; ++i) {
            sa[i] = a[i].clone();
            shuffle(sa[i]);
            Arrays.sort(sa[i]);
            Arrays.fill(saind[i], -1);
            for (int j = 0; j < m; ++j) {
                int what = a[i][j];
                int left = -1;
                int right = m;
                while (right - left > 1) {
                    int middle = (left + right) / 2;
                    if (sa[i][middle] > what || (sa[i][middle] == what && saind[i][middle] < 0))
                        right = middle;
                    else
                        left = middle;
                }
                saind[i][right] = j;
            }
            pa[i] = 0;
            while (pa[i] < m && sa[i][pa[i]] < 0) ++pa[i];
            if (pa[i] < m) {
                va[i] = sa[i][pa[i]];
                while (pa[i] < m && sa[i][pa[i]] == va[i]) {
                    ++pa[i];
                    ++cnt[i];
                }
            } else {
                va[i] = INF;
            }
        }
        int[] numbad = new int[m];
        int[] goodstack = new int[m];
        int gsp = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] > va[i]) ++numbad[j];
        for (int j = 0; j < m; ++j)
            if (numbad[j] == 0) goodstack[gsp++] = j;
        int[] res = new int[m];
        for (int step = 0; step < m; ++step) {
            if (gsp == 0) {
                out.println(-1);
                return;
            }
            int cur = goodstack[--gsp];
            res[step] = cur;
            for (int i = 0; i < n; ++i)
                if (a[i][cur] >= 0) {
                    --cnt[i];
                    if (cnt[i] == 0) {
                        if (pa[i] < m) {
                            va[i] = sa[i][pa[i]];
                            while (pa[i] < m && sa[i][pa[i]] == va[i]) {
                                --numbad[saind[i][pa[i]]];
                                if (numbad[saind[i][pa[i]]] == 0) {
                                    goodstack[gsp++] = saind[i][pa[i]]; 
                                } else if (numbad[saind[i][pa[i]]] < 0) {
                                    throw new RuntimeException();
                                }
                                ++pa[i];
                                ++cnt[i];
                            }
                        } else {
                            va[i] = INF;
                        }
                    }
                }
        }
        for (int i = 0; i < m; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[i] + 1);
        }
        out.println();
    }

    private void shuffle(int[] x) {
        for (int i = 0; i < x.length; ++i) {
            int j = i + random.nextInt(x.length - i);
            int tmp = x[i];
            x[i] = x[j];
            x[j] = tmp;
        }
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
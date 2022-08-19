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
    int[] nextEdge;
    int[] destEdge;
    int[] firstEdge;
    int[] color;
    
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        nextEdge = new int[2 * m];
        destEdge = new int[2 * m];
        firstEdge = new int[n];
        Arrays.fill(firstEdge, -1);
        for (int i = 0; i < m; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            destEdge[i * 2] = b;
            nextEdge[i * 2] = firstEdge[a];
            firstEdge[a] = i * 2;
            destEdge[i * 2 + 1] = a;
            nextEdge[i * 2 + 1] = firstEdge[b];
            firstEdge[b] = i * 2 + 1;
        }
        color = new int[n];
        Arrays.fill(color, -1);
        for (int i = 0; i < n; ++i)
            if (color[i] < 0)
                colorIt(i, 0);
        int[] cnt = new int[2];
        for (int i = 0; i < n; ++i) ++cnt[color[i]];
        int[] res = new int[n];
        int who = 1;
        if (cnt[0] % 3 == 0) {
        } else {
            if (cnt[0] % 3 == 2) {
                for (int i = 0; i < n; ++i) color[i] = 1 - color[i];
                int tmp = cnt[0];
                cnt[0] = cnt[1];
                cnt[1] = tmp;
            }
            int[] deg = new int[n];
            for (int i = 0; i < n; ++i) {
                int e = firstEdge[i];
                while (e >= 0) {
                    ++deg[i];
                    e = nextEdge[e];
                }
            }
            boolean ok = false;
            for (int i = 0; i < n; ++i)
                if (color[i] == 0 && deg[i] <= cnt[1] - 2) {
                    ok = true;
                    boolean[] mark = new boolean[n];
                    int e = firstEdge[i];
                    while (e >= 0) {
                        mark[destEdge[e]] = true;
                        e = nextEdge[e];
                    }
                    color[i] = 2;
                    res[i] = 1;
                    int left = 2;
                    for (int j = 0; j < n; ++j)
                        if (color[j] == 1 && !mark[j]) {
                            color[j] = 2;
                            res[j] = 1;
                            --left;
                            if (left == 0) break;
                        }
                    ++who;
                    break;
                }
            if (!ok) {
                for (int i = 0; i < n; ++i)
                    if (color[i] == 1 && deg[i] <= cnt[0] - 2) {
                        for (int k = i + 1; k < n; ++k)
                            if (color[k] == 1 && deg[k] <= cnt[0] - 2) {
                                ok = true;
                                {
                                    boolean[] mark = new boolean[n];
                                    int e = firstEdge[i];
                                    while (e >= 0) {
                                        mark[destEdge[e]] = true;
                                        e = nextEdge[e];
                                    }
                                    color[i] = 2;
                                    res[i] = who;
                                    int left = 2;
                                    for (int j = 0; j < n; ++j)
                                        if (color[j] == 0 && !mark[j]) {
                                            color[j] = 2;
                                            res[j] = who;
                                            --left;
                                            if (left == 0) break;
                                        }
                                    ++who;                                    
                                }
                                {
                                    boolean[] mark = new boolean[n];
                                    int e = firstEdge[k];
                                    while (e >= 0) {
                                        mark[destEdge[e]] = true;
                                        e = nextEdge[e];
                                    }
                                    color[k] = 2;
                                    res[k] = who;
                                    int left = 2;
                                    for (int j = 0; j < n; ++j)
                                        if (color[j] == 0 && !mark[j]) {
                                            color[j] = 2;
                                            res[j] = who;
                                            --left;
                                            if (left == 0) break;
                                        }
                                    ++who;
                                }                                
                                break;
                            }
                        break;
                    }
                if (!ok) {
                    out.println("NO");
                    return;
                }
            }
        }
        {
            int left = 3;
            for (int i = 0; i < n; ++i) if (color[i] == 0) {
                res[i] = who;
                --left;
                if (left == 0) {
                    ++who;
                    left = 3;
                }
            }
            for (int i = 0; i < n; ++i) if (color[i] == 1) {
                res[i] = who;
                --left;
                if (left == 0) {
                    ++who;
                    left = 3;
                }
            }
        }
        out.println("YES");
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[i]);
        } 
        out.println();
	}

    private void colorIt(int at, int col) {
        if (color[at] >= 0) {
            if (color[at] != col) throw new RuntimeException();
            return;
        }
        color[at] = col;
        int e = firstEdge[at];
        while (e >= 0) {
            colorIt(destEdge[e], 1 - col);
            e = nextEdge[e];
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
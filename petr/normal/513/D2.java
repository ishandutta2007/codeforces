import java.util.Arrays;
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
		TaskD1 solver = new TaskD1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD1 {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int c = in.nextInt();
        int[] next = new int[c];
        int[] dest = new int[c];
        boolean[] isLeft = new boolean[c];
        int[] first = new int[n];
        Arrays.fill(first, -1);
        for (int i = 0; i < c; ++i) {
            int a = in.nextInt();
            int b = in.nextInt();
            String w = in.next();
            if (a >= b) {
                out.println("IMPOSSIBLE");
                return;
            }
            --a;
            --b;
            dest[i] = b;
            next[i] = first[a];
            first[a] = i;
            isLeft[i] = w.equals("LEFT");
        }

        int[] comp = new int[n];
        int[] cmin = new int[n];
        int[] cmax = new int[n];
        int[] rightStart = new int[n];
        for (int i = 0; i < n; ++i) {
            comp[i] = cmin[i] = cmax[i] = i;
        }

        for (int i = n - 1; i >= 0; --i) {
            int cur = first[i];
            int leftcomp = -1;
            int rightcomp = -1;
            while (cur >= 0) {
                if (isLeft[cur]) {
                    if (leftcomp < 0) leftcomp = get(comp, dest[cur]); else {
                        int other = get(comp, dest[cur]);
                        if (leftcomp != other) {
                            leftcomp = merge(comp, leftcomp, other, cmin, cmax);
                            if (rightcomp >= 0) rightcomp = get(comp, rightcomp);
                        }
                    }
                } else {
                    if (rightcomp < 0) rightcomp = get(comp, dest[cur]); else {
                        int other = get(comp, dest[cur]);
                        if (rightcomp != other) {
                            rightcomp = merge(comp, rightcomp, other, cmin, cmax);
                            if (leftcomp >= 0) leftcomp = get(comp, leftcomp);
                        }
                    }
                }
                cur = next[cur];
            }
            if (leftcomp >= 0 && rightcomp >= 0 && cmax[leftcomp] >= cmin[rightcomp]) {
                out.println("IMPOSSIBLE");
                return;
            }
            if (leftcomp >= 0 && cmin[leftcomp] <= i) {
                out.println("IMPOSSIBLE");
                return;
            }
            if (rightcomp >= 0 && cmin[rightcomp] <= i) {
                out.println("IMPOSSIBLE");
                return;
            }
            if (leftcomp >= 0)
                rightStart[i] = cmax[leftcomp] + 1;
            else
                rightStart[i] = i + 1;
            if (leftcomp >= 0 && rightcomp >= 0) {
                int u = merge(comp, leftcomp, rightcomp, cmin, cmax);
                int r = get(comp, i);
                merge(comp, u, r, cmin, cmax);
            } else if (leftcomp >= 0) {
                int r = get(comp, i);
                merge(comp, leftcomp, r, cmin, cmax);
            } else if (rightcomp >= 0) {
                int r = get(comp, i);
                merge(comp, rightcomp, r, cmin, cmax);
            }
        }

        res = new int[n];
        resPtr = 0;
        writeOut(0, n - 1, rightStart);
        if (resPtr != n) throw new RuntimeException();
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[i] + 1);
        }
        out.println();
    }

    int[] res;
    int resPtr;

    private void writeOut(int root, int max, int[] rightStart) {
        int[] stack = new int[max + 1];
        int[] stackmax = new int[max + 1];
        int sp = 0;
        int[] status = new int[max + 1];
        stack[sp] = root;
        stackmax[sp] = max;
        status[sp] = 0;
        ++sp;
        while (sp > 0) {
            root = stack[sp - 1];
            switch (status[sp - 1]) {
                case 0:
                    ++status[sp - 1];
                    if (rightStart[root] > root + 1) {
                        stack[sp] = root + 1;
                        stackmax[sp] = rightStart[root] - 1;
                        status[sp++] = 0;
                    }
                    break;
                case 1:
                    ++status[sp - 1];
                    res[resPtr++] = root;
                    break;
                case 2:
                    --sp;
                    if (rightStart[root] <= stackmax[sp]) {
                        stack[sp] = rightStart[root];
                        status[sp++] = 0;
                    }
                    break;
            }
        }
    }

    private int merge(int[] comp, int a, int b, int[] cmin, int[] cmax) {
        if (a == b) return a;
        int leftUntouched = Math.min(cmax[a], cmax[b]) + 1;
        int rightUntouched = Math.max(cmin[a], cmin[b]) - 1;
        cmin[a] = Math.min(cmin[a], cmin[b]);
        cmax[a] = Math.max(cmax[a], cmax[b]);
        comp[b] = a;
        while (leftUntouched <= rightUntouched) {
            int cc = comp[leftUntouched];
            comp[cc] = a;
            leftUntouched = cmax[leftUntouched] + 1;
        }
        return a;
    }

    private int get(int[] comp, int i) {
        int res = i;
        while (comp[res] != res) res = comp[res];
        int tmp = i;
        while (comp[tmp] != res) {
            int nxt = comp[tmp];
            comp[tmp] = res;
            tmp = nxt;
        }
        return res;
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
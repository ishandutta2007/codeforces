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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static final int MAXX = (int) 1.1e6;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] cnt = new int[n + 1];
        int[] left = new int[]{0};
        int[] right = new int[]{0};
        cnt[1] = 1;
        for (int level = 1; level < n; level = level + 1){
            left = Arrays.copyOf(left, cnt[level] + 1);
            right = Arrays.copyOf(right, cnt[level] + 1);
            cnt[level + 1] = cnt[level];
            if (level == 1) cnt[level + 1] = 0;
            for (int position = cnt[level - 1] + 1; position <= cnt[level]; position = position + 1){
                if ((position & (position - 1)) == 0) {
                    left[position] = cnt[level + 1] + 1;
                    right[position] = cnt[level + 1] + 2;
                    cnt[level + 1] = cnt[level + 1] + 2;
                }else{
                    left[position] = right[position] = cnt[level + 1] + 1;
                    cnt[level + 1] = cnt[level + 1] + 1;
                }
            }
        }
        int generation = 0;
        int[] lastgen = new int[MAXX];
        int[] t = new int[m];
        int[] l = new int[m];
        int[] r = new int[m];
        int[] x = new int[m];
        int[] firstbyt = new int[n + 1];
        Arrays.fill(firstbyt, -1);
        int[] nextsamet = new int[m];
        int type1 = 0;
        for (int i = 0; i < m; ++i) {
            int ct = in.nextInt();
            if (ct == 1) {
                t[type1] = in.nextInt();
                l[type1] = in.nextInt();
                r[type1] = in.nextInt();
                x[type1] = in.nextInt();
                nextsamet[type1] = firstbyt[t[type1]];
                firstbyt[t[type1]] = type1;
                ++type1;
            } else {
                int qt = in.nextInt();
                int ql = in.nextInt();
                int qr = ql;
                ++generation;
                int res = 0;
                while (qt <= n) {
                    int cur = firstbyt[qt];
                    while (cur >= 0) {
                        if (r[cur] < ql || l[cur] > qr) {
                        } else {
                            if (lastgen[x[cur]] < generation) {
                                lastgen[x[cur]] = generation;
                                ++res;
                            }
                        }
                        cur = nextsamet[cur];
                    }
                    if (qt < n) {
                        ql = left[ql];
                        qr = right[qr];
                    }
                    ++qt;
                }
                out.println(res);
            }
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
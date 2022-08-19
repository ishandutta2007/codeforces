import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static class Res {
        int s;
        int t;

        public Res(int s, int t) {
            this.s = s;
            this.t = t;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt() - 1;
        int[][] where = new int[2][n + 1];
        int[] cnt = new int[2];
        for (int i = 0; i < n; ++i) {
            where[a[i]][cnt[a[i]]++] = i;
        }
        List<Res> answers = new ArrayList<>();
        outer: for (int t = 1; t <= Math.max(cnt[0], cnt[1]); ++t) {
            int s0 = 0;
            int s1 = 0;
            int offset = 0;
            int sofar0 = 0;
            int sofar1 = 0;
            int last = -1;
            while (offset < n) {
                int win0 = (sofar0 + t <= cnt[0]) ? where[0][sofar0 + t - 1] : n;
                int win1 = (sofar1 + t <= cnt[1]) ? where[1][sofar1 + t - 1] : n;
                int at = Math.min(win1, win0);
                if (at == n) {
                    continue outer;
                }
                if (at == win0) {
                    sofar0 += t;
                    sofar1 += (win0 + 1 - offset - t);
                    offset = win0 + 1;
                    last = 0;
                    ++s0;
                } else {
                    sofar1 += t;
                    sofar0 += (win1 + 1 - offset - t);
                    offset = win1 + 1;
                    last = 1;
                    ++s1;
                }
            }
            if (s0 > s1 && last == 0) {
                answers.add(new Res(s0, t));
            }
            if (s1 > s0 && last == 1) {
                answers.add(new Res(s1, t));
            }
        }
        Collections.sort(answers, new Comparator<Res>() {
            public int compare(Res o1, Res o2) {
                int z = o1.s - o2.s;
                if (z == 0) z = o1.t - o2.t;
                return z;
            }
        });
        out.println(answers.size());
        for (Res res : answers) {
            out.println(res.s + " " + res.t);
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
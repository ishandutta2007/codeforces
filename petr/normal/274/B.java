import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static class Vertex {
        long v;
        List<Vertex> adj = new ArrayList<Vertex>(0);

        public Result solve(Vertex parent) {
            Result res = new Result();
            for (Vertex child : adj) {
                if (child != parent) {
                    Result r1 = child.solve(this);
                    res.plus = Math.max(res.plus, r1.plus);
                    res.minus = Math.max(res.minus, r1.minus);
                }
            }
            long delta = v - res.minus + res.plus;
            if (delta > 0) res.minus += delta; else res.plus += -delta;
            return res;
        }
    }

    static class Result {
        long plus;
        long minus;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; ++i) v[i] = new Vertex();
        for (int i = 0; i < n - 1; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            v[a].adj.add(v[b]);
            v[b].adj.add(v[a]);
        }
        for (int i = 0; i < n; ++i) v[i].v = in.nextLong();
        Result res = v[0].solve(null);
        out.println(res.plus + res.minus);
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }
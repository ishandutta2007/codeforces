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
    static class Edge {
        Vertex dest;
        long flow;
        int id;
        int value;
    }

    static class Vertex {
        boolean finish = false;
        boolean processed = false;
        List<Edge> adj = new ArrayList<Edge>(0);
        long remaining;
        long balance;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; ++i) {
            v[i] = new Vertex();
        }
        v[n - 1].finish = true;
        for (int i = 0; i < m; ++i) {
            Vertex a = v[in.nextInt() - 1];
            Vertex b = v[in.nextInt() - 1];
            long c = in.nextLong();
            Edge ab = new Edge();
            ab.dest = b;
            ab.flow = c;
            ab.id = i;
            ab.value = 0;
            a.adj.add(ab);
            Edge ba = new Edge();
            ba.dest = a;
            ba.flow = c;
            ba.id = i;
            ba.value = 1;
            b.adj.add(ba);
            a.remaining += c;
            b.remaining += c;
        }
        Vertex[] goods = new Vertex[n];
        int gnum = 1;
        goods[0] = v[0];
        int[] res = new int[m];
        Arrays.fill(res, -1);
        while (gnum > 0) {
            Vertex at = goods[--gnum];
            at.processed = true;
            for (Edge e : at.adj) if (!e.dest.processed) {
                res[e.id] = e.value;
                e.dest.remaining -= e.flow;
                e.dest.balance += e.flow;
                if (!e.dest.finish && e.dest.remaining == e.dest.balance) {
                    goods[gnum++] = e.dest;
                }
            }
        }
        for (int x : res) out.println(x);
    }

}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

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
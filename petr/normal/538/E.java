import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
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
    static class Vertex {
        int totalLeaves;
        int maximizerIndex;
        int minimizerIndex;
        List<Vertex> children = new ArrayList<>(1);

        public void solve(boolean maximizerMoves) {
            if (children.isEmpty()) {
                totalLeaves = 1;
                maximizerIndex = 1;
                minimizerIndex = 1;
                return;
            }
            for (Vertex child : children) {
                child.solve(!maximizerMoves);
                totalLeaves += child.totalLeaves;
            }
            maximizerIndex = 1;
            minimizerIndex = totalLeaves;
            if (maximizerMoves) {
                for (Vertex child : children) {
                    maximizerIndex = Math.max(maximizerIndex, totalLeaves - (child.totalLeaves - child.maximizerIndex));
                    minimizerIndex -= child.totalLeaves - child.minimizerIndex;
                }
            } else {
                for (Vertex child : children) {
                    maximizerIndex += child.maximizerIndex - 1;
                    minimizerIndex = Math.min(minimizerIndex, child.minimizerIndex);
                }
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Vertex[] vs = new Vertex[n];
        for (int i = 0; i < n; ++i) {
            vs[i] = new Vertex();
        }
        for (int i = 0; i < n - 1; ++i) {
            Vertex u = vs[in.nextInt() - 1];
            Vertex v = vs[in.nextInt() - 1];
            u.children.add(v);
        }
        vs[0].solve(true);
        out.println(vs[0].maximizerIndex + " " + vs[0].minimizerIndex);
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
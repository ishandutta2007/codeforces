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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    class Vertex {
        List<Vertex> adj = new ArrayList<Vertex>(1);
        boolean visited = false;
        int odd = 0;
        int index = -1;

        public int countOdd() {
            if (visited) return 0;
            visited = true;
            int res = odd;
            for (Vertex v : adj) {
                res += v.countOdd();
            }
            return res;
        }

        public void solveTree(boolean isRoot) {
            visited = true;
            for (int i = 0; i < adj.size(); ++i) {
                Vertex v = adj.get(i);
                if (v.visited) continue;
                answer[answerCnt++] = index;
                odd = 1 - odd;
                v.solveTree(false);
                if (v.odd == 1) {
                    answer[answerCnt++] = index;
                    answer[answerCnt++] = v.index;
                    odd = 1 - odd;
                    v.odd = 1 - v.odd;
                }
            }
            if (!isRoot || odd == 1) {
                answer[answerCnt++] = index;
                odd = 1 - odd;
            }
        }
    }

    int[] answer;
    int answerCnt;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Vertex[] vs = new Vertex[n];
        for (int i = 0; i < n; ++i) {
            vs[i] = new Vertex();
            vs[i].index = i + 1;
        }
        for (int i = 0; i < m; ++i) {
            Vertex a = vs[in.nextInt() - 1];
            Vertex b = vs[in.nextInt() - 1];
            a.adj.add(b);
            b.adj.add(a);
        }
        int totalOdd = 0;
        for (int i = 0; i < n; ++i) {
            vs[i].odd = in.nextInt();
            totalOdd += vs[i].odd;
        }
        if (totalOdd == 0) {
            out.println(0);
            out.println();
            return;
        }
        for (int i = 0; i < n; ++i) if (!vs[i].visited) {
            if (vs[i].countOdd() == totalOdd) {
                for (Vertex v : vs) v.visited = false;
                answer = new int[4 * n + 1];
                answerCnt = 0;
                vs[i].solveTree(true);
                out.println(answerCnt);
                for (int j = 0; j < answerCnt; ++j) {
                    if (j > 0) out.print(" ");
                    out.print(answer[j]);
                }
                out.println();
                return;
            }
        }
        out.println(-1);
        return;
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
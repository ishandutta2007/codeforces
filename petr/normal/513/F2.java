import java.util.Arrays;
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
		TaskF2 solver = new TaskF2();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF2 {
    static class Edge {
        Node src;
        Node dest;
        long cap;
        long flow;
        Edge rev;
    };

    static class Node {
        Edge via;
        List<Edge> outgo = new ArrayList<>(1);
    }
    List<Node> all;
    Node s;
    Node t;

    static class Candidate {
        Node src;
        Node dst;
        long when;

        public Candidate(Node src, Node dst, long when) {
            this.src = src;
            this.dst = dst;
            this.when = when;
        }
    }

    Edge addEdge(Node a, Node b, int cap, boolean reallyAdd) {
        Edge ab = new Edge();
        Edge ba = new Edge();
        ab.src = a;
        ab.dest = b;
        ab.cap = cap;
        ab.flow = 0;
        ba.src = b;
        ba.dest = a;
        ba.cap = cap;
        ba.flow = 0;
        ab.rev = ba;
        ba.rev = ab;
        if (reallyAdd) {
            a.outgo.add(ab);
            b.outgo.add(ba);
        }
        return ab;
    }

    boolean simpleDfs(Node src) {
        if (src == t) return true;
        for (Edge e : src.outgo)
            if (e.flow < e.cap && e.dest.via == null) {
                e.dest.via = e;
                if (simpleDfs(e.dest)) return true;
            }
        return false;
    }
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int rows = in.nextInt();
        int cols = in.nextInt();
        int males = in.nextInt();
        int females = in.nextInt();
        if (males != females + 1 && males != females - 1) {
            out.println(-1);
            return;
        }
        String[] field = new String[rows];
        for (int row = 0; row < rows; ++row) field[row] = in.next();
        int people = 1 + males + females;
        int[] sr = new int[people];
        int[] sc = new int[people];
        int[] speed = new int[people];
        boolean[] male = new boolean[people];
        for (int i = 0; i < people; ++i) {
            if (i == 0) {
                male[i] = (males < females);
            } else {
                male[i] = i < 1 + males;
            }
            sr[i] = in.nextInt() - 1;
            sc[i] = in.nextInt() - 1;
            speed[i] = in.nextInt();
        }
        int[][] dist = new int[people][rows * cols];
        int[] qr = new int[rows * cols];
        int[] qc = new int[rows * cols];
        for (int who = 0; who < people; ++who) {
            int[] cdist = dist[who];
            Arrays.fill(cdist, -1);
            cdist[sr[who] * cols + sc[who]] = 0;
            int qt = 0;
            int qh = 1;
            qr[0] = sr[who];
            qc[0] = sc[who];
            while (qt < qh) {
                int cr = qr[qt];
                int cc = qc[qt++];
                for (int dr = -1; dr <= 1; ++dr)
                    for (int dc = -1; dc <= 1; ++dc)
                        if (Math.abs(dr) + Math.abs(dc) == 1) {
                            int nr = cr + dr;
                            int nc = cc + dc;
                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && field[nr].charAt(nc) == '.' && cdist[nr * cols + nc] < 0) {
                                cdist[nr * cols + nc] = cdist[cr * cols + cc] + 1;
                                qr[qh] = nr;
                                qc[qh] = nc;
                                ++qh;
                            }
                        }
            }
        }
        all = new ArrayList<>();
        s = new Node();
        t = new Node();
        all.add(s);
        all.add(t);
        Node[] src = new Node[rows * cols];
        Node[] dst = new Node[rows * cols];
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (field[row].charAt(col) == '.') {
                    src[row * cols + col] = new Node();
                    dst[row * cols + col] = new Node();
                    all.add(src[row * cols + col]);
                    all.add(dst[row * cols + col]);
                    addEdge(src[row * cols + col], dst[row * cols + col], 1, true);
                }
            }
        }
        Node[] whoNode = new Node[people];
        List<Candidate> candidates = new ArrayList<>();
        for (int i = 0; i < people; ++i) {
            whoNode[i] = new Node();
            all.add(whoNode[i]);
            if (male[i]) {
                addEdge(s, whoNode[i], 1, true);
            } else {
                addEdge(whoNode[i], t, 1, true);
            }
            for (int cell = 0; cell < rows * cols; ++cell)
                if (dist[i][cell] >= 0) {
                    if (male[i]) {
                        candidates.add(new Candidate(whoNode[i], src[cell], dist[i][cell] * (long) speed[i]));
                    } else {
                        candidates.add(new Candidate(dst[cell], whoNode[i], dist[i][cell] * (long) speed[i]));
                    }
                }
        }
        Collections.sort(candidates, new Comparator<Candidate>() {
            public int compare(Candidate o1, Candidate o2) {
                return Long.compare(o1.when, o2.when);
            }
        });

        if (simpleDfs(s)) throw new RuntimeException();
        int got = 0;
        for (Candidate c : candidates) {
            Edge e = addEdge(c.src, c.dst, 0, true);
            e.cap = 1;
            if (e.src.via != null && e.dest.via == null) {
                e.dest.via = e;
                if (simpleDfs(e.dest)) {
                    Node at = t;
                    while (at != s) {
                        ++at.via.flow;
                        --at.via.rev.flow;
                        at = at.via.src;
                    }
                    ++got;
                    if (got == people / 2) {
                        out.println(c.when);
                        return;
                    }
                    for (Node node : all) node.via = null;
                    if (simpleDfs(s)) throw new RuntimeException();
                }
            }
        }
        out.println(-1);
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
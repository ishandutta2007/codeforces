import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Locale;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static class Query {
        int kind;
        Vertex v;
        Vertex u;
        int t;
    }

    static class Vertex {
        long s;
        long subtreeSize;
        boolean hasInterestingInSubtree = false;
        long subtreeAnswer;
        long childSquareSum;
        Vertex parent;
        Vertex firstChild;
        Vertex nextSibling;
        Vertex interestingParent;
        Vertex firstInterestingChild;
        Vertex nextInterestingSibling;
        long multiplierForIntermediates;
        long constantForIntermediates;
        long intermediatesSize;
        long boringChildrenSize;
        long boringChildrenSquareSum;
        long boringChildrenAnswer;
        boolean interesting;

        void propagateInteresting() {
            Vertex v = firstChild;
            int numIntChild = 0;
            while (v != null) {
                v.propagateInteresting();
                if (v.hasInterestingInSubtree) ++numIntChild;
                v = v.nextSibling;
            }
            if (numIntChild >= 2) interesting = true;
            if (interesting || numIntChild >= 1) hasInterestingInSubtree = true;
        }

        void init() {
            subtreeSize = 1;
            subtreeAnswer = 0;
            childSquareSum = 0;
            boringChildrenSize = 0;
            boringChildrenAnswer = 0;
            boringChildrenSquareSum = 0;
            Vertex v = firstChild;
            while (v != null) {
                v.init();
                subtreeSize += v.subtreeSize;
                subtreeAnswer += v.subtreeAnswer;
                childSquareSum += v.subtreeSize * (long) v.subtreeSize;
                if (interesting && !v.hasInterestingInSubtree) {
                    boringChildrenSize += v.subtreeSize;
                    boringChildrenAnswer += v.subtreeAnswer;
                    boringChildrenSquareSum += v.subtreeSize * (long) v.subtreeSize;
                }
                v = v.nextSibling;
            }
            subtreeAnswer += (subtreeSize * (long) subtreeSize - childSquareSum) * s;
        }

        public void interestingInit() {
            subtreeSize = 1 + boringChildrenSize;
            subtreeAnswer = boringChildrenAnswer;
            childSquareSum = boringChildrenSquareSum;
            Vertex v = firstInterestingChild;
            while (v != null) {
                v.interestingInit();
                long childSize = v.subtreeSize + v.intermediatesSize;
                subtreeSize += childSize;
                subtreeAnswer += v.subtreeAnswer;
                subtreeAnswer += v.multiplierForIntermediates * v.subtreeSize + v.constantForIntermediates;
                childSquareSum += childSize * (long) childSize;
                v = v.nextInterestingSibling;
            }
            subtreeAnswer += (subtreeSize * (long) subtreeSize - childSquareSum) * s;
        }

        public void initIntermediates() {
            Vertex tmp = this;
            intermediatesSize = 0;
            multiplierForIntermediates = 0;
            constantForIntermediates = 0;
            while (!tmp.parent.interesting) {
                long curExtra = tmp.parent.subtreeSize - tmp.subtreeSize;
                intermediatesSize += curExtra;
                multiplierForIntermediates += 2 * curExtra * (long) tmp.parent.s;
                constantForIntermediates += tmp.parent.subtreeAnswer - tmp.subtreeAnswer - 2 * subtreeSize * (long) (tmp.parent.subtreeSize - tmp.subtreeSize) * tmp.parent.s;
                tmp = tmp.parent;
            }
            interestingParent = tmp.parent;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        /*char[] buf = new char[100000];
        int size;
        try {
            size = in.reader.read(buf);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        if (size == buf.length) throw new RuntimeException();
        String input = new String(buf, 0, size);
        StringWriter sw1 = new StringWriter();
        PrintWriter pw1 = new PrintWriter(sw1);
        doit(new InputReader(new StringInputStream(input)), pw1, 1);
        pw1.close();
        StringWriter sw2 = new StringWriter();
        PrintWriter pw2 = new PrintWriter(sw2);
        doit(new InputReader(new StringInputStream(input)), pw2, 500);
        pw2.close();
        String s1 = sw1.toString();
        String s2 = sw2.toString();
        if (!s1.equals(s2)) throw new RuntimeException();
        out.print(s1);*/
        doit(in, out, 500);
    }

    private void doit(InputReader in, PrintWriter out, int BUBEN) {
        Locale.setDefault(Locale.US);
        int n = in.nextInt();
        Vertex[] vs = new Vertex[n];
        for (int i = 0; i < n; ++i) vs[i] = new Vertex();
        for (int i = 1; i < n; ++i) {
            vs[i].parent = vs[in.nextInt() - 1];
        }
        for (int i = 0; i < n; ++i) {
            vs[i].s = in.nextInt();
        }
        Vertex root = vs[0];
        int numQueries = in.nextInt();
        Query[] queries = new Query[numQueries];
        for (int i = 0; i < numQueries; ++i) {
            Query query = new Query();
            String ss = in.next();
            if (ss.equals("P")) query.kind = 1; else if (ss.equals("V")) query.kind = 2; else throw new RuntimeException();
            if (query.kind == 1) {
                query.v = vs[in.nextInt() - 1];
                query.u = vs[in.nextInt() - 1];
            } else {
                query.v = vs[in.nextInt() - 1];
                query.t = in.nextInt();
            }
            queries[i] = query;
        }
        double mult = 1.0 / n / n;
        Vertex[] inters = new Vertex[n];
        for (int blockFirst = 0; blockFirst < numQueries; blockFirst += BUBEN) {
            int blockLast = Math.min(numQueries, blockFirst + BUBEN);
            for (Vertex vv : vs) {
                vv.interesting = false;
                vv.hasInterestingInSubtree = false;
            }
            root.interesting = true;
            for (int qid = blockFirst; qid < blockLast; ++qid) {
                Query query = queries[qid];
                if (query.kind == 1) {
                    query.v.interesting = true;
                    if (query.v.parent != null) query.v.parent.interesting = true;
                    query.u.interesting = true;
                    if (query.u.parent != null) query.u.parent.interesting = true;
                } else {
                    query.v.interesting = true;
                }
            }
            for (Vertex vv : vs) {
                vv.firstChild = null;
                vv.nextSibling = null;
            }
            for (Vertex vv : vs) {
                if (vv.parent != null) {
                    vv.nextSibling = vv.parent.firstChild;
                    vv.parent.firstChild = vv;
                }
            }
            root.propagateInteresting();
            int ninters = 0;
            for (Vertex vv : vs) if (vv.interesting) {
                inters[ninters++] = vv;
            }
            root.init();
            for (int i = 0; i < ninters; ++i) {
                Vertex vv = inters[i];
                if (vv.parent != null) vv.initIntermediates();
            }
            if (blockFirst == 0) {
                out.println(String.format("%.12f", root.subtreeAnswer * mult));
            }
            for (int qid = blockFirst; qid < blockLast; ++qid) {
                Query query = queries[qid];
                if (query.kind == 1) {
                    Vertex tmp = query.u;
                    while (tmp != null && tmp != query.v) tmp = tmp.interestingParent;
                    if (tmp == null) {
                        query.v.parent = query.u;
                        query.v.interestingParent = query.u;
                    } else {
                        query.u.parent = query.v;
                        query.u.interestingParent = query.v;
                    }
                } else {
                    query.v.s = query.t;
                }
                for (int i = 0; i < ninters; ++i) {
                    Vertex vv = inters[i];
                    vv.firstInterestingChild = null;
                    vv.nextInterestingSibling = null;
                }
                for (int i = 0; i < ninters; ++i) {
                    Vertex vv = inters[i];
                    if (vv.interestingParent != null) {
                        vv.nextInterestingSibling = vv.interestingParent.firstInterestingChild;
                        vv.interestingParent.firstInterestingChild = vv;
                    }
                }
                root.interestingInit();
                out.println(String.format("%.12f", root.subtreeAnswer * mult));
            }
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
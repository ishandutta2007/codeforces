import java.util.NavigableSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static class Panel {
        int h;
        int left;
        int right;
        int id;
        Panel ln;
        Panel rn;

        Panel(int h, int left, int right, int id) {
            this.h = h;
            this.left = left;
            this.right = right;
            this.id = id;
            ln = NONE;
            rn = NONE;
        }

        void setLeft(Panel p) {
            if (ln == null) {
                return;
            }
            if (ln == NONE) {
                ln = p;
            } else if (ln != p) {
                ln = null;
            }
        }

        void setRight(Panel p) {
            if (rn == null) {
                return;
            }
            if (rn == NONE) {
                rn = p;
            } else if (rn != p) {
                rn = null;
            }
        }

        int intersect(Panel e) {
            return Math.min(right, e.right) - Math.max(left, e.left);
        }
    }

    static Panel NONE = new Panel(0, 0, 0, -1);

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int t = in.nextInt();
        Panel[] a = new Panel[n + 2];
        for (int i = 0; i < n; i++) {
            a[i] = new Panel(in.nextInt(), in.nextInt(), in.nextInt(), i);
        }
        final int INF = 1000000000;
        a[n] = new Panel(t, -INF, INF, n);
        a[n + 1] = new Panel(0, -INF, INF, n + 1);
        n += 2;
        Panel[] enter = a.clone();
        Panel[] exit = a.clone();
        Arrays.sort(enter, new Comparator<Panel>() {
            @Override
            public int compare(Panel o1, Panel o2) {
                return o1.left - o2.left;
            }
        });
        Arrays.sort(exit, new Comparator<Panel>() {
            @Override
            public int compare(Panel o1, Panel o2) {
                return o1.right - o2.right;
            }
        });
        DijkstraGraph g = new DijkstraGraph(n);
        NavigableSet<Panel> set = new TreeSet<Panel>(new Comparator<Panel>() {
            @Override
            public int compare(Panel o1, Panel o2) {
                return o1.h - o2.h;
            }
        });
        int remove = 0;
        for (Panel e : enter) {
            while (remove < n && exit[remove].right <= e.left) {
                Panel f = exit[remove];
                set.remove(f);
                Panel left = set.higher(f);
                Panel right = set.lower(f);
                if (f.ln == null && left != null && left.rn == f) {
                    g.addEdge(left.id, f.id, left.intersect(f));
                    left.rn = NONE;
                } else if (f.ln != NONE && f.ln != null) {
                    g.addEdge(f.ln.id, f.id, f.ln.intersect(f));
                }
                if (f.rn == null && right != null && right.ln == f) {
                    g.addEdge(f.id, right.id, right.intersect(f));
                    right.ln = NONE;
                } else if (f.rn != NONE && f.rn != null) {
                    g.addEdge(f.id, f.rn.id, f.rn.intersect(f));
                }
//                if (left != null) {
//                    f.setLeft(left);
//                    left.setRight(f);
//
//                    System.out.println("neigh " + f.id + " " + left.id);
//                }
//                if (right != null) {
//                    f.setRight(right);
//                    right.setLeft(f);
//                    System.out.println("neigh " + f.id + " " + right.id);
//                }
//                if (left != null && right != null) {
//                    left.setRight(right);
//                    right.setLeft(left);
//                }
                remove++;
//                System.out.println("remove " + f.id);
            }
            Panel left = set.higher(e);
            Panel right = set.lower(e);
            if (left != null) {
//                System.out.println("neigh " + e.id + " " + left.id);
                e.setLeft(left);
                left.setRight(e);
            }
            if (right != null) {
//                System.out.println("neigh " + e.id + " " + right.id);
                e.setRight(right);
                right.setLeft(e);
            }
            set.add(e);
//            System.out.println("add " + e.id);
        }
//        for (int i = 0; i < n; i++) {
//            Panel e = a[i];
//            if (e.ln != NONE && e.ln != null) {
//                int v = e.intersect(e.ln);
//                g.addEdge(e.ln.id, i, v);
////                System.out.println(e.ln.id + " " + i + " " + v);
//            }
//            if (e.rn != NONE && e.rn != null) {
//                int v = e.intersect(e.rn);
//                g.addEdge(i, e.rn.id, v);
////                System.out.println(i + " " + e.rn.id + " " + v);
//            }
//        }
        while (remove < n) {
            Panel f = exit[remove];
            set.remove(f);
            Panel left = set.higher(f);
            Panel right = set.lower(f);
            if (f.ln == null && left != null && left.rn == f) {
                g.addEdge(left.id, f.id, left.intersect(f));
                left.rn = NONE;
            } else if (f.ln != NONE && f.ln != null) {
                g.addEdge(f.ln.id, f.id, f.ln.intersect(f));
            }
            if (f.rn == null && right != null && right.ln == f) {
                g.addEdge(f.id, right.id, right.intersect(f));
                right.ln = NONE;
            } else if (f.rn != NONE && f.rn != null) {
                g.addEdge(f.id, f.rn.id, f.rn.intersect(f));
            }
//                if (left != null) {
//                    f.setLeft(left);
//                    left.setRight(f);
//
//                    System.out.println("neigh " + f.id + " " + left.id);
//                }
//                if (right != null) {
//                    f.setRight(right);
//                    right.setLeft(f);
//                    System.out.println("neigh " + f.id + " " + right.id);
//                }
//                if (left != null && right != null) {
//                    left.setRight(right);
//                    right.setLeft(left);
//                }
            remove++;
//                System.out.println("remove " + f.id);
        }
        long[] z = g.dijkstraMaxMin(n - 2);
        out.println(z[n - 1]);
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

class DijkstraGraph {

    public long[] dijkstraMaxMin(int source) {
        long[] d = new long[n];
        Arrays.fill(d, Long.MIN_VALUE);
        Element[] q = new Element[n];
        for (int i = 0; i < q.length; i++) {
            q[i] = new Element(i, Long.MIN_VALUE);
        }
        q[source].d = d[source] = Long.MAX_VALUE;
        TreeSet<Element> queue = new TreeSet<Element>(new Comparator<Element>() {
            @Override
            public int compare(Element o1, Element o2) {
                if (o1.d != o2.d) {
                    return o1.d < o2.d ? 1 : -1;
                }
                return o1.v - o2.v;
            }
        });
        queue.add(q[source]);
        while (!queue.isEmpty()) {
            Element el = queue.pollFirst();
            for (int i = 0; i < edges[el.v].size(); i++) {
                Edge e = edges[el.v].get(i);
                long w = Math.min(d[e.from], e.w);
                if (d[e.to] < w) {
                    queue.remove(q[e.to]);
                    d[e.to] = q[e.to].d = w;
                    queue.add(q[e.to]);
                }
            }
        }
        return d;
    }
    public static class Edge {
        public int from;
        public int to;
        public int w;

        public Edge(int from, int to, int w) {
            this.from = from;
            this.to = to;
            this.w = w;
        }

    }

    static class Element implements Comparable<Element> {
        int v;
        long d;

        public Element(int v, long d) {
            this.v = v;
            this.d = d;
        }

        public int compareTo(Element o) {
            if (d != o.d) {
                return d < o.d ? -1 : 1;
            }
            return v - o.v;
        }
    }

    ArrayList<Edge>[] edges;
    int n;


    public DijkstraGraph(int n) {
        this.n = n;
        @SuppressWarnings("unchecked")
        ArrayList<Edge>[] edges = new ArrayList[n];
        this.edges = edges;
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<Edge>();
        }
    }

    public Edge addEdge(int from, int to, int w) {
        Edge ret = new Edge(from, to, w);
        edges[from].add(ret);
        return ret;
    }

    }
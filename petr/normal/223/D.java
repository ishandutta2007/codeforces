import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.HashMap;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.util.Collections;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static class Point {
        int x;
        int y;
        int index;

        Point(int x, int y, int index) {
            this.x = x;
            this.y = y;
            this.index = index;
        }
    }

    static class GraphNode implements Comparable<GraphNode> {
        int sideId;
        int x;
        double y;
        double distance = 1e100;
        boolean mark = false;

        List<GraphNode> outgo = new ArrayList<GraphNode>();

        GraphNode(int sideId, int x) {
            this.sideId = sideId;
            this.x = x;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            GraphNode graphNode = (GraphNode) o;

            if (sideId != graphNode.sideId) return false;
            if (x != graphNode.x) return false;

            return true;
        }

        public int hashCode() {
            int result = sideId;
            result = 31 * result + x;
            return result;
        }

        public int compareTo(GraphNode graphNode) {
            int z = sideId - graphNode.sideId;
            if (z != 0) return z;
            return x - graphNode.x;
        }
    }

    List<GraphNode> nodes = new ArrayList<GraphNode>();
    Map<GraphNode, GraphNode> canonical = new HashMap<GraphNode, GraphNode>();

    static class Edge implements Comparable<Edge> {
        Point v1;
        Point v2;
        int isUpper;

        Edge(Point v1, Point v2) {
            if (v1.x > v2.x) {
                Point tmp = v1;
                v1 = v2;
                v2 = tmp;
            }
            this.v1 = v1;
            this.v2 = v2;
        }

        public int compareTo(Edge edge) {
            int minx = Math.max(v1.x, edge.v1.x);
            int maxx = Math.min(v2.x, edge.v2.x);
            if (minx >= maxx) {
                throw new RuntimeException();
            }
            //if (this.v1 == edge.v1 && this.v2 == edge.v2) return 0;
            int mid = (minx + maxx) / 2;
            long diff = ((mid - v1.x) * (long) (v2.y - v1.y) + v1.y * (long) (v2.x - v1.x)) * (edge.v2.x - edge.v1.x)
                    - ((mid - edge.v1.x) * (long) (edge.v2.y - edge.v1.y) + edge.v1.y * (long) (edge.v2.x - edge.v1.x)) * (v2.x - v1.x);
            return Long.signum(diff);
        }
    }

    int n;

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        Random random = new Random(5943715431L);
        n = in.nextInt();
        Point[] poly = new Point[n];
        for (int i = 0; i < n; ++i) {
            int x = in.nextInt();
            int y = in.nextInt();
            poly[i] = new Point(x * 2, y * 2, i);
        }
        for (int i = 0; i < poly.length; ++i) {
            Edge e1 = new Edge(poly[i], poly[(i + 1) % poly.length]);
            Edge e2 = new Edge(poly[i], poly[(i + poly.length - 1) % poly.length]);
            addTransition(e1, e2, poly[i].x);
            addTransition(e2, e1, poly[i].x);
        }
        int s = in.nextInt() - 1;
        int t = in.nextInt() - 1;
        TreeSet<Edge> picture = new TreeSet<Edge>();
        Point[] polyByX = poly.clone();
        for (int i = 0; i < polyByX.length; ++i) {
            int j = i + random.nextInt(polyByX.length - i);
            Point tmp = polyByX[i];
            polyByX[i] = polyByX[j];
            polyByX[j] = tmp;
        }
        Arrays.sort(polyByX, new Comparator<Point>() {
            public int compare(Point a, Point b) {
                int z = Integer.signum(a.x - b.x);
                if (z != 0) return z;
                return Integer.signum(a.y - b.y);
            }
        });
        for (int pi = 0; pi < polyByX.length;) {
            int pj;
            Point prevP = null;
            for (pj = pi; pj < polyByX.length && polyByX[pj].x == polyByX[pi].x; ++pj) {
                Point p = polyByX[pj];
                Point a = poly[(p.index + 1) % poly.length];
                Point b = poly[(p.index + poly.length - 1) % poly.length];
                if (a.x > b.x || (a.x == b.x && a.y > b.y)) {
                    Point tmp = a;
                    a = b;
                    b = tmp;
                }
                if (a.x < p.x && b.x < p.x) {
                    if ((a.x - p.x) * (long) (b.y - p.y) - (a.y - p.y) * (long) (b.x - p.x) < 0) {
                        Point tmp = a;
                        a = b;
                        b = tmp;
                    }
                    Edge bEdge = picture.floor(new Edge(b, p));
                    if (bEdge.isUpper == 2) {
                        Edge dest = picture.lower(bEdge);
                        double destY = addTransition(bEdge, dest, p.x);
                        if (prevP != null) {
                            if (prevP.y > destY) {
                                getNodeFor(poly, p.index).outgo.add(getNodeFor(poly, prevP.index));
                            }
                        }
                    }
                    Edge aEdge = picture.floor(new Edge(a, p));
                    if (aEdge.isUpper == 1) {
                        Edge dest = picture.higher(aEdge);
                        addTransition(dest, aEdge, p.x);
                    }
                } else if (a.x < p.x && b.x > p.x) {
                    Edge aEdge = picture.floor(new Edge(a, p));
                    if (aEdge.isUpper == 1) {
                        Edge dest = picture.higher(aEdge);
                        addTransition(dest, aEdge, p.x);
                    } else {
                        Edge dest = picture.lower(aEdge);
                        double destY = addTransition(aEdge, dest, p.x);
                        if (prevP != null) {
                            if (prevP.y > destY) {
                                getNodeFor(poly, p.index).outgo.add(getNodeFor(poly, prevP.index));
                            }
                        }
                    }
                } else if (a.x < p.x && b.x == p.x) {
                    Edge aEdge = picture.floor(new Edge(a, p));
                    if (aEdge.isUpper == 1 && b.y < p.y) {
                        Edge dest = picture.higher(aEdge);
                        addTransition(dest, aEdge, p.x);
                    } else if (aEdge.isUpper == 2 && b.y > p.y) {
                        Edge dest = picture.lower(aEdge);
                        double destY = addTransition(aEdge, dest, p.x);
                        if (prevP != null) {
                            if (prevP.y > destY) {
                                getNodeFor(poly, p.index).outgo.add(getNodeFor(poly, prevP.index));
                            }
                        }
                    }
                }
                prevP = p;
            }
            for (pj = pi; pj < polyByX.length && polyByX[pj].x == polyByX[pi].x; ++pj) {
                Point p = polyByX[pj];
                Point a = poly[(p.index + 1) % poly.length];
                Point b = poly[(p.index + poly.length - 1) % poly.length];
                if (a.x < p.x) {
                    Edge toRemove = new Edge(a, p);
                    if (!picture.remove(toRemove)) throw new RuntimeException();
                }
                if (b.x < p.x) {
                    Edge toRemove = new Edge(b, p);
                    if (!picture.remove(toRemove)) {
                        throw new RuntimeException();
                    }
                }
            }
            for (pj = pi; pj < polyByX.length && polyByX[pj].x == polyByX[pi].x; ++pj) {
                Point p = polyByX[pj];
                Point a = poly[(p.index + 1) % poly.length];
                Point b = poly[(p.index + poly.length - 1) % poly.length];
                if ((a.x - p.x) * (long) (b.y - p.y) - (a.y - p.y) * (long) (b.x - p.x) < 0) {
                    Point tmp = a;
                    a = b;
                    b = tmp;
                }
                if (a.x > p.x) {
                    Edge toAdd = new Edge(a, p);
                    Edge prev = picture.lower(toAdd);
                    if (prev == null)
                        toAdd.isUpper = 1;
                    else
                        toAdd.isUpper = 3 - prev.isUpper;
                    if (!picture.add(toAdd)) throw new RuntimeException();
                }
                if (b.x > p.x) {
                    Edge toAdd = new Edge(b, p);
                    Edge prev = picture.lower(toAdd);
                    if (prev == null)
                        toAdd.isUpper = 1;
                    else
                        toAdd.isUpper = 3 - prev.isUpper;
                    if (!picture.add(toAdd)) throw new RuntimeException();
                }
            }
            prevP = null;
            for (pj = pi; pj < polyByX.length && polyByX[pj].x == polyByX[pi].x; ++pj) {
                Point p = polyByX[pj];
                Point a = poly[(p.index + 1) % poly.length];
                Point b = poly[(p.index + poly.length - 1) % poly.length];
                if (a.x > b.x || (a.x == b.x && a.y > b.y)) {
                    Point tmp = a;
                    a = b;
                    b = tmp;
                }
                if (a.x > p.x && b.x > p.x) {
                    if ((a.x - p.x) * (long) (b.y - p.y) - (a.y - p.y) * (long) (b.x - p.x) > 0) {
                        Point tmp = a;
                        a = b;
                        b = tmp;
                    }
                    Edge bEdge = picture.floor(new Edge(b, p));
                    if (bEdge.isUpper == 2) {
                        Edge dest = picture.lower(bEdge);
                        double destY = addTransition(bEdge, dest, p.x);
                        if (prevP != null) {
                            if (prevP.y > destY) {
                                getNodeFor(poly, p.index).outgo.add(getNodeFor(poly, prevP.index));
                            }
                        }
                    }
                    Edge aEdge = picture.floor(new Edge(a, p));
                    if (aEdge.isUpper == 1) {
                        Edge dest = picture.higher(aEdge);
                        addTransition(dest, aEdge, p.x);
                    }
                } else if (a.x == p.x && b.x > p.x) {
                    Edge bEdge = picture.floor(new Edge(b, p));
                    if (bEdge.isUpper == 1 && a.y < p.y) {
                        Edge dest = picture.higher(bEdge);
                        addTransition(dest, bEdge, p.x);
                    } else if (bEdge.isUpper == 2 && a.y > p.y) {
                        Edge dest = picture.lower(bEdge);
                        double destY = addTransition(bEdge, dest, p.x);
                        if (prevP != null) {
                            if (prevP.y > destY) {
                                getNodeFor(poly, p.index).outgo.add(getNodeFor(poly, prevP.index));
                            }
                        }
                    }
                }
                prevP = p;
            }
            pi = pj;
        }
        GraphNode start = getNodeFor(poly, s);
        GraphNode finish = getNodeFor(poly, t);
        Collections.sort(nodes);
        for (int i = 0; i + 1 < nodes.size(); ++i) {
            GraphNode n1 = nodes.get(i);
            GraphNode n2 = nodes.get(i + 1);
            if (n1.sideId == n2.sideId) {
                n1.outgo.add(n2);
                n2.outgo.add(n1);
            }
        }
        TreeSet<Reach> reaches = new TreeSet<Reach>();
        start.distance = 0;
        reaches.add(new Reach(start, 0));
        while (true) {
            Reach first = reaches.pollFirst();
            if (first.dest.mark) continue;
            first.dest.mark = true;
            if (first.dest == finish) {
                out.println(first.dest.distance / 2.0);
                return;
            }
            for (GraphNode other : first.dest.outgo) {
                double dx = first.dest.x - other.x;
                double dy = first.dest.y - other.y;
                double dd = Math.sqrt(dx * dx + dy * dy);
                double nd = first.dest.distance + dd;
                if (nd < other.distance - 1e-10) {
                    other.distance = nd;
                    reaches.add(new Reach(other, other.distance));
                }
            }
        }
	}

    private GraphNode getNodeFor(Point[] poly, int s) {
        GraphNode start;
        {
            Point sp = poly[s];
            Point spa = poly[(s + 1) % poly.length];
            Point spb = poly[(s + poly.length - 1) % poly.length];
            if (spa.x != sp.x || spa.y > sp.y) {
                start = createNode(new Edge(sp, spa), sp.x);
            } else {
                start = createNode(new Edge(sp, spb), sp.x);
            }
        }
        return start;
    }

    static class Reach implements Comparable<Reach> {
        GraphNode dest;
        double d;

        Reach(GraphNode dest, double d) {
            this.dest = dest;
            this.d = d;
        }

        public int compareTo(Reach reach) {
            if (d != reach.d) return Double.compare(d, reach.d);
            return dest.compareTo(reach.dest);
        }
    }

    private double addTransition(Edge top, Edge bottom, int x) {
        GraphNode src = createNode(top, x);
        GraphNode dst = createNode(bottom, x);
        src.outgo.add(dst);
        return dst.y;
    }

    private GraphNode createNode(Edge top, int x) {
        GraphNode src;
        {
            int i1 = top.v1.index;
            int i2 = top.v2.index;
            int i;
            if (i1 + 1 == i2 || i1 + 1 == i2 + n) {
                i = i1;
            } else if (i2 + 1 == i1 || i2 + 1 == i1 + n) {
                i = i2;
            } else {
                throw new RuntimeException();
            }
            src = new GraphNode(i, x);
            GraphNode canonicalSrc = canonical.get(src);
            if (canonicalSrc == null) {
                canonical.put(src, src);
                nodes.add(src);
                if (top.v1.x == top.v2.x)
                    src.y = Math.min(top.v1.y, top.v2.y);
                else
                    src.y = (x - top.v1.x) / (double) (top.v2.x - top.v1.x) * (top.v2.y - top.v1.y) + top.v1.y;
            } else {
                src = canonicalSrc;
            }
        }
        return src;
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

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
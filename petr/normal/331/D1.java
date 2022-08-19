import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
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
		Grid solver = new Grid();
		solver.solve(1, in, out);
		out.close();
	}
}

class Grid {
    static class Arrow {
        int x0;
        int y0;
        int x1;
        int y1;
        int dx;
        int dy;
        Position afterEnd;
    }

    static class Position {
        int x;
        int y;
        int dx;
        int dy;
        long togo;
        Arrow dest;
        int mx;
        int my;
        Position[] after = new Position[60];
        long[] stepsUntil = new long[60];
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int b = in.nextInt() + 1;
        Arrow[] arrow = new Arrow[n];
        for (int i = 0; i < n; ++i) {
            arrow[i] = new Arrow();
            arrow[i].x0 = in.nextInt();
            arrow[i].y0 = in.nextInt();
            arrow[i].x1 = in.nextInt();
            arrow[i].y1 = in.nextInt();
            arrow[i].dx = sgn(arrow[i].x1 - arrow[i].x0);
            arrow[i].dy = sgn(arrow[i].y1 - arrow[i].y0);
        }
        int q = in.nextInt();
        Position[] queries = new Position[q];
        for (int i = 0; i < q; ++i) {
            queries[i] = new Position();
            queries[i].x = in.nextInt();
            queries[i].y = in.nextInt();
            queries[i].dx = 0;
            queries[i].dy = 0;
            switch (in.next().charAt(0)) {
                case 'U':
                    queries[i].dy = 1;
                    break;
                case 'D':
                    queries[i].dy = -1;
                    break;
                case 'L':
                    queries[i].dx = -1;
                    break;
                case 'R':
                    queries[i].dx = 1;
                    break;
                default:
                    throw new RuntimeException();
            }
            queries[i].togo = in.nextLong();
        }
        Position[] interesting = new Position[q + n];
        System.arraycopy(queries, 0, interesting, 0, q);
        for (int i = 0; i < n; ++i) {
            interesting[i + q] = new Position();
            arrow[i].afterEnd = interesting[i + q];
            interesting[i + q].x = arrow[i].x1 + arrow[i].dx;
            interesting[i + q].y = arrow[i].y1 + arrow[i].dy;
            interesting[i + q].dx = arrow[i].dx;
            interesting[i + q].dy = arrow[i].dy;
        }
        for (Arrow arr : arrow) {
            if (arr.dx < 0) {
                int tmp = arr.x0;
                arr.x0 = arr.x1;
                arr.x1 = tmp;
            }
            if (arr.dy < 0) {
                int tmp = arr.y0;
                arr.y0 = arr.y1;
                arr.y1 = tmp;
            }
        }
        findDestinations(interesting, arrow, b);
        findJumps(interesting);
        for (Position qq : queries) {
            Position at = qq;
            long togo = qq.togo;
            for (int size = 59; size >= 0; --size) {
                while (at.after[0] != at && at.stepsUntil[size] <= togo) {
                    togo -= at.stepsUntil[size];
                    at = at.after[size];
                }
            }
            long rx;
            long ry;
            if (at.after[0] != at && togo >= Math.abs(at.x - at.mx) + Math.abs(at.y - at.my)) {
                togo -= Math.abs(at.x - at.mx) + Math.abs(at.y - at.my);
                rx = at.mx + at.dest.dx * togo;
                ry = at.my + at.dest.dy * togo;
            } else {
                rx = at.x + at.dx * togo;
                ry = at.y + at.dy * togo;
            }
            if (rx >= b) rx = b - 1;
            if (rx < 0) rx = 0;
            if (ry >= b) ry = b - 1;
            if (ry < 0) ry = 0;
            out.println(rx + " " + ry);
        }
    }

    private void findJumps(Position[] interesting) {
        for (Position p : interesting) {
            if (p.dest == null) {
                p.after[0] = p;
                p.stepsUntil[0] = 0;
            } else {
                p.after[0] = p.dest.afterEnd;
                int mx;
                int my;
                mx = p.dest.x0;
                my = p.dest.y0;
                if (Math.abs(p.dest.x1 - p.x) + Math.abs(p.dest.y1 - p.y) < Math.abs(mx - p.x) + Math.abs(my - p.y)) {
                    mx = p.dest.x1;
                    my = p.dest.y1;
                }
                if (p.dest.x0 == p.dest.x1) {
                    if (p.y >= p.dest.y0 && p.y <= p.dest.y1 && Math.abs(p.dest.x0 - p.x) < Math.abs(mx - p.x) + Math.abs(my - p.y)) {
                        mx = p.dest.x0;
                        my = p.y;
                    }
                }
                if (p.dest.y0 == p.dest.y1) {
                    if (p.x >= p.dest.x0 && p.x <= p.dest.x1 && Math.abs(p.dest.y0 - p.y) < Math.abs(mx - p.x) + Math.abs(my - p.y)) {
                        mx = p.x;
                        my = p.dest.y0;
                    }
                }
                p.mx = mx;
                p.my = my;
                p.stepsUntil[0] = Math.abs(mx - p.x) + Math.abs(my - p.y) + Math.abs(p.after[0].x - mx) + Math.abs(p.after[0].y - my);
            }
        }
        for (int i = 1; i < 60; ++i) {
            for (Position p : interesting) {
                p.after[i] = p.after[i - 1].after[i - 1];
                p.stepsUntil[i] = p.stepsUntil[i - 1] + p.after[i - 1].stepsUntil[i - 1];
                if (p.stepsUntil[i] > INF) p.stepsUntil[i] = INF;
            }
        }
    }

    static final long INF = (long) 1e18;

    static class SegmentTree {
        Arrow[] tree;
        int n;

        public SegmentTree(int n) {
            this.n = n;
            tree = new Arrow[4 * n + 10];
        }

        public void update(int left, int right, Arrow val) {
            internalUpdate(0, 0, n - 1, left, right, val);
        }

        private void internalUpdate(int root, int rl, int rr, int left, int right, Arrow val) {
            if (left > right) return;
            if (left == rl && right == rr) {
                tree[root] = val;
                return;
            }
            if (tree[root] != null) {
                tree[root * 2 + 1] = tree[root];
                tree[root * 2 + 2] = tree[root];
                tree[root] = null;
            }
            int rm = (rl + rr) / 2;
            internalUpdate(root * 2 + 1, rl, rm, left, Math.min(right, rm), val);
            internalUpdate(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right, val);
        }

        public Arrow get(int at) {
            return internalGet(0, 0, n - 1, at);
        }

        private Arrow internalGet(int root, int rl, int rr, int at) {
            if (tree[root] != null) return tree[root];
            if (rl == rr) return null;
            int rm = (rl + rr) / 2;
            if (at <= rm)
                return internalGet(root * 2 + 1, rl, rm, at);
            else
                return internalGet(root * 2 + 2, rm + 1, rr, at);
        }
    }

    private void findDestinations(Position[] interesting, Arrow[] arrow, int b) {
        Position[] subset = new Position[interesting.length];
        for (int dx = -1; dx <= 1; ++dx)
            for (int dy = -1; dy <= 1; ++dy)
                if (Math.abs(dx) + Math.abs(dy) == 1) {
                    SegmentTree see = new SegmentTree(b);
                    int start = 0;
                    int end = b - 1;
                    if (dx < 0 || dy < 0) {
                        start = b - 1;
                        end = 0;
                    }
                    int n = 0;
                    for (Position p : interesting)
                        if (p.dx == dx && p.dy == dy) {
                            subset[n++] = p;
                        }
                    final int fdx = dx;
                    final int fdy = dy;
                    Arrays.sort(subset, 0, n, new Comparator<Position>() {
                        @Override
                        public int compare(Position o1, Position o2) {
                            int v1 = o1.x * fdx + o1.y * fdy;
                            int v2 = o2.x * fdx + o2.y * fdy;
                            return v2 - v1;
                        }
                    });
                    Arrays.sort(arrow, new Comparator<Arrow>() {
                        @Override
                        public int compare(Arrow o1, Arrow o2) {
                            int v1 = Math.max(o1.x1 * fdx + o1.y1 * fdy, o1.x0 * fdx + o1.y0 * fdy);
                            int v2 = Math.max(o2.x1 * fdx + o2.y1 * fdy, o2.x0 * fdx + o2.y0 * fdy);
                            return v2 - v1;
                        }
                    });
                    int spos = 0;
                    int apos = 0;
                    for (int coord = end + dx + dy; coord != start - dx - dy; coord -= dx + dy) {
                        while (apos < arrow.length) {
                            Arrow o1 = arrow[apos];
                            int v1 = Math.max(o1.x1 * fdx + o1.y1 * fdy, o1.x0 * fdx + o1.y0 * fdy);
                            if (Math.abs(v1) == coord) {
                                int ml;
                                int mr;
                                if (dx != 0) {
                                    ml = o1.y0;
                                    mr = o1.y1;
                                } else {
                                    ml = o1.x0;
                                    mr = o1.x1;
                                }
                                see.update(ml, mr, o1);
                                ++apos;
                            } else {
                                break;
                            }
                        }
                        while (spos < n) {
                            Position cur = subset[spos];
                            if ((dx != 0 && cur.x == coord) || (dy != 0 && cur.y == coord)) {
                                if (dx != 0)
                                    cur.dest = see.get(cur.y);
                                else
                                    cur.dest = see.get(cur.x);
                                ++spos;
                            } else break;
                        }
                    }
                }
    }

    private int sgn(int i) {
        if (i < 0) return -1; else if (i > 0) return 1; else return 0;
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
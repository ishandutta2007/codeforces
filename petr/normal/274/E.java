import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static class Obstacle {
        int x;
        int y;
    }

    static class SumThenDiffComparator implements Comparator<Obstacle> {
        static final SumThenDiffComparator INSTANCE = new SumThenDiffComparator();

        public int compare(Obstacle o1, Obstacle o2) {
            int s1 = o1.x + o1.y;
            int s2 = o2.x + o2.y;
            if (s1 != s2)
                return s1 - s2;
            s1 = o1.x - o1.y;
            s2 = o2.x - o2.y;
            return s1 - s2;
        }
    }

    static class DiffThenSumComparator implements Comparator<Obstacle> {
        static final DiffThenSumComparator INSTANCE = new DiffThenSumComparator();

        public int compare(Obstacle o1, Obstacle o2) {
            int s1 = o1.x - o1.y;
            int s2 = o2.x - o2.y;
            if (s1 != s2)
                return s1 - s2;
            s1 = o1.x + o1.y;
            s2 = o2.x + o2.y;
            return s1 - s2;
        }
    }

    static class Obstacles {
        Obstacle[] bySum;
        Obstacle[] byDiff;
        int maxx;
        int maxy;

        public Obstacles(Obstacle[] ob, int maxx, int maxy) {
            this.maxx = maxx;
            this.maxy = maxy;
            bySum = ob.clone();
            Arrays.sort(bySum, SumThenDiffComparator.INSTANCE);
            byDiff = ob.clone();
            Arrays.sort(byDiff, DiffThenSumComparator.INSTANCE);
        }

        public boolean haveObstacle(int x, int y) {
            if (x <= 0 || x > maxx || y <= 0 || y > maxy) return true;
            Obstacle cur = new Obstacle();
            cur.x = x;
            cur.y = y;
            return Arrays.binarySearch(bySum, cur, SumThenDiffComparator.INSTANCE) >= 0;
        }

        public Obstacle getNext(int x, int y, int dx, int dy) {
            Obstacle cur = new Obstacle();
            cur.x = x;
            cur.y = y;
            if (dx == dy) {
                int pos = Arrays.binarySearch(byDiff, cur, DiffThenSumComparator.INSTANCE);
                if (pos >= 0) throw new RuntimeException();
                pos = -(pos + 1);
                if (dx > 0) {
                    if (pos < byDiff.length && x - y == byDiff[pos].x - byDiff[pos].y)
                        return byDiff[pos];
                    else
                        return getBoundary(x, y, dx, dy);
                } else {
                    --pos;
                    if (pos >= 0 && x - y == byDiff[pos].x - byDiff[pos].y)
                        return byDiff[pos];
                    else
                        return getBoundary(x, y, dx, dy);
                }
            } else {
                int pos = Arrays.binarySearch(bySum, cur, SumThenDiffComparator.INSTANCE);
                if (pos >= 0) {
                    throw new RuntimeException();
                }
                pos = -(pos + 1);
                if (dx > 0) {
                    if (pos < bySum.length && x + y == bySum[pos].x + bySum[pos].y)
                        return bySum[pos];
                    else
                        return getBoundary(x, y, dx, dy);
                } else {
                    --pos;
                    if (pos >= 0 && x + y == bySum[pos].x + bySum[pos].y)
                        return bySum[pos];
                    else
                        return getBoundary(x, y, dx, dy);
                }
            }
        }

        private Obstacle getBoundary(int x, int y, int dx, int dy) {
            int times = Integer.MAX_VALUE;
            if (dx > 0) times = Math.min(times, maxx + 1 - x); else times = Math.min(times, x);
            if (dy > 0) times = Math.min(times, maxy + 1 - y); else times = Math.min(times, y);
            Obstacle res = new Obstacle();
            res.x = x + times * dx;
            res.y = y + times * dy;
            return res;
        }
    }

    Obstacles obstacles;
    int xs;
    int ys;
    int dx;
    int dy;
    List<Segment> segments = new ArrayList<Segment>();

    static class Segment implements Comparable<Segment> {
        int x1;
        int y1;
        int x2;
        int y2;

        Segment(int x1, int y1, int x2, int y2) {
            if (x1 < x2) {
                this.x1 = x1;
                this.y1 = y1;
                this.x2 = x2;
                this.y2 = y2;
            } else {
                this.x1 = x2;
                this.y1 = y2;
                this.x2 = x1;
                this.y2 = y1;
            }
        }

        public int compareTo(Segment o) {
            if (x1 != o.x1) return x1 - o.x1;
            if (y1 != o.y1) return y1 - o.y1;
            if (x2 != o.x2) return x2 - o.x2;
            return y2 - o.y2;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int maxx = in.nextInt();
        int maxy = in.nextInt();
        int k = in.nextInt();
        Obstacle[] ob = new Obstacle[k];
        for (int i = 0; i < k; ++i) {
            ob[i] = new Obstacle();
            ob[i].x = in.nextInt();
            ob[i].y = in.nextInt();
        }
        xs = in.nextInt();
        ys = in.nextInt();
        String dir = in.next();
        if (dir.equals("NE")) {
            dx = -1;
            dy = 1;
        } else if (dir.equals("NW")) {
            dx = -1;
            dy = -1;
        } else if (dir.equals("SE")) {
            dx = 1;
            dy = 1;
        } else if (dir.equals("SW")) {
            dx = 1;
            dy = -1;
        } else throw new RuntimeException();
        long res = doit(maxx, maxy, ob);
        out.println(res);
    }

    private long doit(int maxx, int maxy, Obstacle[] ob) {
        shuffle(ob);
        obstacles = new Obstacles(ob, maxx, maxy);
        oneStep();
        int exs = xs;
        int eys = ys;
        int edx = dx;
        int edy = dy;
        segments.clear();
        do {
            oneStep();
        } while (xs != exs || ys != eys || dx != edx || dy != edy);
        List<Segment> plus = new ArrayList<Segment>();
        List<Segment> minus = new ArrayList<Segment>();
        for (Segment s : segments) {
            if (s.x1 + s.y1 == s.x2 + s.y2) {
                plus.add(s);
            } else {
                minus.add(s);
            }
        }
        Collections.sort(plus);
        Collections.sort(minus);
        int cnt = 0;
        for (int i = 0; i < plus.size(); ++i) {
            if (i == 0 || plus.get(i).compareTo(plus.get(i - 1)) > 0)
                plus.set(cnt++, plus.get(i));
        }
        while (plus.size() > cnt) plus.remove(plus.size() - 1);
        cnt = 0;
        for (int i = 0; i < minus.size(); ++i) {
            if (i == 0 || minus.get(i).compareTo(minus.get(i - 1)) > 0)
                minus.set(cnt++, minus.get(i));
        }
        while (minus.size() > cnt) minus.remove(minus.size() - 1);
        long res = 0;
        for (Segment x : plus) {
            res += Math.abs(x.x1 - x.x2) + 1;
        }
        for (Segment x : minus) {
            res += Math.abs(x.x1 - x.x2) + 1;
        }
        return res;
    }

    private void oneStep() {
        Obstacle meet = obstacles.getNext(xs, ys, dx, dy);
        int px = meet.x - dx;
        int py = meet.y - dy;
        segments.add(new Segment(xs, ys, px, py));
        boolean haveX = obstacles.haveObstacle(px, meet.y);
        boolean haveY = obstacles.haveObstacle(meet.x, py);
        if (haveX && !haveY) {
            xs = meet.x;
            ys = py;
            dy = -dy;
        } else if (haveY && !haveX) {
            xs = px;
            ys = meet.y;
            dx = -dx;
        } else {
            xs = px;
            ys = py;
            dx = -dx;
            dy = -dy;
        }
    }

    Random random = new Random(System.currentTimeMillis() + 438467315);

    private void shuffle(Obstacle[] x) {
        for (int i = 0; i < x.length; ++i) {
            int j = i + random.nextInt(x.length - i);
            Obstacle tmp = x[i];
            x[i] = x[j];
            x[j] = tmp;
        }
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

    }
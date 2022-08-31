import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Towers implements Runnable {
    static final long MODULO = 1000000007;

    static class Point {
        int x;
        int y;
        int id;

        Point(int id) {
            this.id = id;
        }
    }

    static class PointWithData implements Comparable<PointWithData> {
        int data;
        Point point;

        PointWithData(int data, Point point) {
            this.data = data;
            this.point = point;
        }

        public int compareTo(PointWithData point) {
            return data - point.data;
        }
    }

    static class Result {
        final boolean any;
        final long amount;

        Result(boolean any, long amount) {
            this.any = any;
            this.amount = amount;
        }
    }

    static Result add(Result a, Result b) {
        if (!a.any) return b;
        if (!b.any) return a;
        return new Result(true, (a.amount + b.amount) % MODULO);
    }

    private void solve() throws IOException {
        int n = nextInt();
        Point[] p = new Point[n];
        for (int i = 0; i < n; ++i) {
            p[i] = new Point(i);
            p[i].x = nextInt();
            p[i].y = nextInt();
        }
        PointWithData[] plus = new PointWithData[n];
        for (int i = 0; i < n; ++i)
            plus[i] = new PointWithData(p[i].x + p[i].y, p[i]);
        Arrays.sort(plus);
        PointWithData[] minus = new PointWithData[n];
        for (int i = 0; i < n; ++i)
            minus[i] = new PointWithData(p[i].x - p[i].y, p[i]);
        Arrays.sort(minus);
        int left = -1;
        int right = 10001;
        while (right - left > 1) {
            int middle = (left + right) / 2;
            Result cur = numWays(p, plus, minus, middle);
            if (cur.any)
                right = middle;
            else
                left = middle;
        }
        writer.println(right);
        writer.println(numWays(p, plus, minus, right).amount);
    }

    private Result numWays(Point[] points, PointWithData[] plus, PointWithData[] minus, int maxDist) {
        if (plus[plus.length - 1].data - plus[0].data <= maxDist) {
            return handleMinus(points, minus, maxDist, new boolean[points.length], new boolean[points.length]);
        } else {
            Result res = new Result(false, 0);
            {
                boolean[] kill1 = new boolean[points.length];
                boolean[] kill2 = new boolean[points.length];
                for (PointWithData pp : plus) {
                    if (pp.data - plus[0].data > maxDist)
                        kill1[pp.point.id] = true;
                    if (plus[plus.length - 1].data - pp.data > maxDist)
                        kill2[pp.point.id] = true;
                }
                res = add(res, handleMinus(points, minus, maxDist, kill1, kill2));
            }
            {
                boolean[] kill1 = new boolean[points.length];
                boolean[] kill2 = new boolean[points.length];
                for (PointWithData pp : plus) {
                    if (pp.data - plus[0].data > maxDist)
                        kill2[pp.point.id] = true;
                    if (plus[plus.length - 1].data - pp.data > maxDist)
                        kill1[pp.point.id] = true;
                }
                res = add(res, handleMinus(points, minus, maxDist, kill1, kill2));
            }
            return res;
        }
    }

    private Result handleMinus(Point[] points, PointWithData[] minus, int maxDist, boolean[] skill1, boolean[] skill2) {
        if (minus[minus.length - 1].data - minus[0].data <= maxDist) {
            return handleResult(points, skill1, skill2);
        } else {
            Result res = new Result(false, 0);
            {
                boolean[] kill1 = skill1.clone();
                boolean[] kill2 = skill2.clone();
                for (PointWithData pp : minus) {
                    if (pp.data - minus[0].data > maxDist)
                        kill1[pp.point.id] = true;
                    if (minus[minus.length - 1].data - pp.data > maxDist)
                        kill2[pp.point.id] = true;
                }
                res = add(res, handleResult(points, kill1, kill2));
            }
            {
                boolean[] kill1 = skill1.clone();
                boolean[] kill2 = skill2.clone();
                for (PointWithData pp : minus) {
                    if (pp.data - minus[0].data > maxDist)
                        kill2[pp.point.id] = true;
                    if (minus[minus.length - 1].data - pp.data > maxDist)
                        kill1[pp.point.id] = true;
                }
                res = add(res, handleResult(points, kill1, kill2));
            }
            return res;
        }
    }

    private Result handleResult(Point[] points, boolean[] kill1, boolean[] kill2) {
        int p2 = 0;
        for (int i = 0; i < points.length; ++i) {
            if (kill1[i] && kill2[i]) return new Result(false, 0);
            if (!kill1[i] && !kill2[i]) ++p2;
        }
        long cnt = 1;
        for (int i = 0; i < p2; ++i) {
            cnt = (cnt * 2) % MODULO;
        }
        return new Result(true, cnt);
    }

    public static void main(String[] args) {
        new Towers().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
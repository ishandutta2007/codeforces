import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Set;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Lab implements Runnable {
    static class Point implements Comparable<Point> {
        int x;
        int y;
        double alpha;

        Point(int x, int y, double alpha) {
            this.x = x;
            this.y = y;
            this.alpha = alpha;
        }

        public int compareTo(Point point) {
            return Double.compare(alpha, point.alpha);
        }
    }

    private void solve() throws IOException {
        int numQueries = nextInt();
        int[] queryType = new int[numQueries];
        int[] queryX = new int[numQueries];
        int[] queryY = new int[numQueries];
        for (int i = 0; i < numQueries; ++i) {
            queryType[i] = nextInt();
            queryX[i] = nextInt();
            queryY[i] = nextInt();
        }
        double[] koef = new double[]{0.49214632134, 0.2348329743213, 0.9854827427182};
        double sum = 0;
        double mx = 0;
        double my = 0;
        for (int i = 0; i < 3; ++i) {
            sum += koef[i];
            mx += koef[i] * queryX[i];
            my += koef[i] * queryY[i];
        }
        mx /= sum;
        my /= sum;
        double[] alpha = new double[numQueries];
        for (int i = 0; i < numQueries; ++i) {
            alpha[i] = Math.atan2(queryY[i] - my, queryX[i] - mx);
        }
        TreeSet<Point> cur = new TreeSet<Point>();
        for (int i = 0; i < 3; ++i) {
            cur.add(new Point(queryX[i], queryY[i], alpha[i]));
        }
        for (int i = 3; i < numQueries; ++i) {
            Point p = new Point(queryX[i], queryY[i], alpha[i]);
            SortedSet<Point> before = cur.headSet(p);
            SortedSet<Point> after = cur.tailSet(p);
            if (queryType[i] == 2) {
                Point a;
                if (before.isEmpty())
                    a = cur.last();
                else
                    a = before.last();
                Point b;
                if (after.isEmpty())
                    b = cur.first();
                else
                    b = after.first();
                if (turnSign(a, p, b) <= 0) writer.println("YES"); else writer.println("NO");
            } else {
                {
                    Point a;
                    if (before.isEmpty())
                        a = cur.last();
                    else
                        a = before.last();
                    Point b;
                    if (after.isEmpty())
                        b = cur.first();
                    else
                        b = after.first();
                    if (turnSign(a, p, b) <= 0) continue;
                }
                while (true) {
                    Point a;
                    if (after.isEmpty())
                        a = cur.first();
                    else
                        a = after.first();
                    cur.remove(a);
                    Point b;
                    if (after.isEmpty())
                        b = cur.first();
                    else
                        b = after.first();
                    if (turnSign(p, a, b) > 0) {
                        cur.add(a);
                        break;
                    }
                }
                while (true) {
                    Point a;
                    if (before.isEmpty())
                        a = cur.last();
                    else
                        a = before.last();
                    cur.remove(a);
                    Point b;
                    if (before.isEmpty())
                        b = cur.last();
                    else
                        b = before.last();
                    if (turnSign(p, a, b) < 0) {
                        cur.add(a);
                        break;
                    }
                }
                cur.add(p);
            }
        }
    }

    private int turnSign(Point a, Point b, Point c) {
        long res = (long) (b.x - a.x) * (c.y - b.y) - (long) (b.y - a.y) * (c.x - b.x);
        if (res > 0)
            return 1;
        else if (res < 0)
            return -1;
        else
            return 0;
    }

    public static void main(String[] args) {
        new Lab().run();
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
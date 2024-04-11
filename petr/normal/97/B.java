import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Superset implements Runnable {
    static class Point implements Comparable<Point> {
        final int x;
        final int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Point point = (Point) o;

            if (x != point.x) return false;
            if (y != point.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }

        public int compareTo(Point point) {
            return x - point.x;
        }
    }

    Set<Point> res = new HashSet<Point>();

    private void solve() throws IOException {
        int n = nextInt();
        Point[] p = new Point[n];
        for (int i = 0; i < n; ++i) {
            int x = nextInt();
            int y = nextInt();
            p[i] = new Point(x, y);
        }
        Arrays.sort(p);
        for (Point pp : p) res.add(pp);
        doit(p, 0, p.length);
        writer.println(res.size());
        for (Point pp : res) {
            writer.println(pp.x + " " + pp.y);
        }
    }

    private void doit(Point[] p, int left, int right) {
        if (left + 1 >= right) return;
        int middle = (left + right) / 2;
        int mx = p[middle].x;
        for (int i = left; i < right; ++i) res.add(new Point(mx, p[i].y));
        doit(p, left, middle);
        doit(p, middle, right);
    }

    public static void main(String[] args) {
        new Superset().run();
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
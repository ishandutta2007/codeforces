import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        Point[] a = new Point[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Point(in.nextInt(), in.nextInt(), in.nextInt(), i + 1);
        }
        Arrays.sort(a);
        recX(a);
    }

    void recX(Point[] a) {
        List<Point> next = new ArrayList<>();
        for (int i = 0; i < a.length; ) {
            int j = i;
            while (j != a.length && a[i].x == a[j].x) {
                j++;
            }
            Point t = recY(a, i, j);
            if (t != null) {
                next.add(t);
            }
            i = j;
        }
        makePairs(next);
    }


    Point recY(Point[] a, int from, int to) {
        List<Point> next = new ArrayList<>();
        for (int i = from; i < to; ) {
            int j = i;
            while (j != to && a[i].y == a[j].y) {
                j++;
            }
            Point t = recZ(a, i, j);
            if (t != null) {
                next.add(t);
            }
            i = j;
        }
        return makePairs(next);
    }

    Point recZ(Point[] a, int from, int to) {
        List<Point> next = new ArrayList<>();
        for (int i = from; i < to; i++) {
            next.add(a[i]);
        }
        return makePairs(next);
    }

    Point makePairs(List<Point> a) {
        for (int i = 0; i + 1 < a.size(); i += 2) {
            out.println(a.get(i).id + " " + a.get(i + 1).id);
        }
        if (a.size() % 2 == 1) {
            return a.get(a.size() - 1);
        }
        return null;
    }

    class Point implements Comparable<Point> {
        int x, y, z;

        int id;

        public Point(int x, int y, int z, int id) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.id = id;
        }

        @Override
        public int compareTo(Point o) {
            if (x != o.x) {
                return Integer.compare(x, o.x);
            }
            if (y != o.y) {
                return Integer.compare(y, o.y);
            }
            return Integer.compare(z, o.z);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new A().runIO();
    }
}
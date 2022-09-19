import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        Point[] p = new Point[n];
        for (int i = 0; i < n; i++) {
            int x1 = nextInt();
            int y1 = nextInt();
            int x2 = nextInt();
            int y2 = nextInt();
            p[i] = new Point(x1 + x2, y1 + y2);
        }
        Point[] p2 = p.clone();
        Arrays.sort(p, new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                return Integer.compare(o1.x, o2.x);
            }
        });
        Arrays.sort(p2, new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                return Integer.compare(o1.y, o2.y);
            }
        });

        long res = Long.MAX_VALUE;
        for (int l = 0; l <= k; l++) {
            for (int r = 0; r <= k; r++) {
                if (l + r > k) break;
                Set<Point> points = new HashSet<>();
                for (int i = 0; i < l; i++) {
                    points.add(p[i]);
                }
                for (int i = 0; i < r; i++) {
                    points.add(p[n - 1 - i]);
                }
                for (int t = 0; t <= k; t++) {
                    for (int b = 0; b <= k; b++) {
                        if (t + b > k) break;
                        int s = l + r;
                        for (int i = 0; i < t; i++) {
                            if (!points.contains(p2[i])) s++;
                        }
                        for (int i = 0; i < b; i++) {
                            if (!points.contains(p2[n - 1 - i])) s++;
                        }
                        if (s <= k) {
                            long w = p[n - 1 - r].x - p[l].x;
                            long h = p2[n - 1 - b].y - p2[t].y;
                            w = (w + 1) / 2;
                            h = (h + 1) / 2;
                            if (w == 0) w = 1;
                            if (h == 0) h = 1;
                            res = Math.min(res, w * h);
//                            if (res < 0) {
//                                System.out.println("!");
//                            }
                        }
                    }
                }
            }
        }
        out.println(res);

    }

    class Point {
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }


    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}
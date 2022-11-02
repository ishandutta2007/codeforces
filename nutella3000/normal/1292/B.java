import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static point first, a, b;
    static point start;
    static long time;

    static point next(point v) {
        return new point(v.x * a.x + b.x,v.y * a.y + b.y);
    }

    static point prev(point v) {
        return new point((v.x - b.x) / a.x, (v.y - b.y) / a.y);
    }


    static long dist(point a, point b) {
        return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        first = new point(sc.nextLong(), sc.nextLong());
        a = new point(sc.nextLong(), sc.nextLong());
        b = new point(sc.nextLong(), sc.nextLong());
        start = new point(sc.nextLong(), sc.nextLong());
        time = sc.nextLong();

        int ans = 0;
        point st = new point(first.x, first.y);
        int num = 0;
        while(true) {
            long t = time - dist(st, start);
            if (t < 0 && (st.x >= 3e16 || st.y >= 3e16)) break;
            if (t >= 0) {
            int last_num = num;
            point last = new point(st.x, st.y);

            while (last_num != -1 && dist(last, st) <= t) {
                last_num--;
                last = prev(last);
            }

            last_num++;

            if (last_num > 0) {
                ans = Math.max(ans, num - last_num + 1);
            }else {

                t -= dist(st, first);

                last_num = 0;
                last = new point(first.x, first.y);

                while (dist(last, first) <= t) {
                    last_num++;
                    last = next(last);
                }
                last_num--;

                ans = Math.max(ans, Math.max(num, last_num) + 1);

            }
        }

            st = next(st);
            num++;
        }

        pw.println(ans);

        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}

class point {
    long x, y;
    point(long x, long y) {
        this.x = x;
        this.y = y;
    }
}
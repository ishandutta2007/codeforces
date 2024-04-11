import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static double eps = 1e-9;

    static int comp(double a, double b) {
        if (a - b > eps) return 1;
        if (b - a > eps) return -1;
        return 0;
    }

    static line make_line(point one, point two) {
        line ans = new line();
        if (one.x == two.x) {
            ans.b = 0;
            ans.a = 1;
            ans.c = -one.x;
        }else{
            ans.b = 1;
            ans.a = (two.y - one.y) / (one.x - two.x);
            ans.c = -ans.a * one.x - one.y;
        }
        return ans;
    }


    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        point a[] = new point[n];
        for(int i = 0;i < n;i++) a[i] = new point(nextInt(), nextInt());

        TreeSet<line> one = new TreeSet<>(new line());
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) one.add(make_line(a[i], a[j]));
        }

        long ans = (long) one.size() * (one.size() - 1) / 2;

        TreeMap<line, Integer> two = new TreeMap<>(new Comparator<line>() {
            @Override
            public int compare(line o1, line o2) {
                return comp(o1.a, o2.a) * 2 + comp(o1.b, o2.b);
            }
        });

        for(line i : one) {
            if (!two.containsKey(i)) two.put(i, 0);
            ans -= two.get(i);
            two.put(i, two.get(i) + 1);
        }

        pw.println(ans);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

class line implements Comparator<line>{
    double a, b, c;
    static double eps = 1e-9;
    line(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    line() {}

    public int comp(double one, double two) {
        if (two - one > eps) return -1;
        if (one - two > eps) return 1;
        return 0;
    }

    @Override
    public int compare(line o1, line o2) {
        return comp(o1.a, o2.a) * 4 + comp(o1.b, o2.b) * 2 + comp(o1.c, o2.c);
    }
}

class point {
    double x, y;
    point(double x, double y) {
        this.x = x;
        this.y = y;
    }
}
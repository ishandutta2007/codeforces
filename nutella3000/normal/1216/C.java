import java.io.*;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    static square prec(square o1, square o2) {
        square ans = new square(Math.max(o1.x1, o2.x1), Math.max(o1.y1, o2.y1), Math.min(o1.x2, o2.x2), Math.min(o1.y2, o2.y2));
        ans.x2 = Math.max(ans.x2, ans.x1);
        ans.y2 = Math.max(ans.y1, ans.y2);
        return ans;
    }

    static long sq(square a) {
        return (long) (a.x2 - a.x1) * (a.y2 - a.y1);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        square o1 = new square(nextInt(), nextInt(), nextInt(), nextInt());
        square o2 = new square(nextInt(), nextInt(), nextInt(), nextInt());
        square o3 = new square(nextInt(), nextInt(), nextInt(), nextInt());
        square o4 = prec(o1, o2);
        square o5 = prec(o1, o3);
        square o6 = prec(o4, o5);

        if (sq(o4) + sq(o5) - sq(o6) == sq(o1)) pw.println("NO");
        else pw.println("YES");
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
}

class square {
    int x1, y1, x2, y2;

    square(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    square() {}
}
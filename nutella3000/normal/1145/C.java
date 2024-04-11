import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int)1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int a = nextInt();
        if (a == 3) pw.print(13);
        else if (a == 0) pw.print(15);
        else if (a == 1) pw.print(14);
        else if (a == 2) pw.print(12);
        else if (a == 4) pw.print(8);
        else if (a == 5) pw.print(9);
        else if (a == 6) pw.print(10);
        else if (a == 7) pw.print(11);
        else if (a == 8) pw.print(0);
        else if (a == 9) pw.print(1);
        else if (a == 10) pw.print(2);
        else if (a == 11) pw.print(3);
        else if (a == 12) pw.print(4);
        else if (a == 13) pw.print(5);
        else if (a == 14) pw.print(6);
        else if (a == 15) pw.print(7);
        pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}
class pair implements Comparator<pair> {
    int a,  b, id;

    pair(int x, int y, int id) {
        a = x;
        b = y;
        this.id = id;
    }

    pair() {
    }

    @Override
    public int compare(pair o1, pair o2) {
        return - Integer.compare(o1.a, o2.a) * 2 + Integer.compare(o1.id, o2.id);
    }
}
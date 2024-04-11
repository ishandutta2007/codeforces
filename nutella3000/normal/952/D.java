import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int)1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        pw.print("Black");
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
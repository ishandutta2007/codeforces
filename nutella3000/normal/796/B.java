import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        boolean hole[] = new boolean[n + 1];
        while(m-- > 0) hole[nextInt()] = true;
        int v = 1;
        while(k-- > 0) {
            int v1 = nextInt();
            int v2 = nextInt();
            if (hole[v]) continue;
            if (v1 == v) v = v2;
            else if (v2 == v) v = v1;
        }
        pw.println(v);
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
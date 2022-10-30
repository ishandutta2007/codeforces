import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        boolean bad = true;
        for(int i = 0;i < m;i++) {
            int k = nextInt();
            int a[] = new int [k];
            HashSet<Integer> b = new HashSet<>();
            boolean q = true;
            for(int j = 0;j < k;j++) {
                int v = nextInt();
                if (b.contains(-v)) q = false;
                else b.add(v);
            }

            if (q) bad = false;
        }

        if (bad) pw.println("NO");
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
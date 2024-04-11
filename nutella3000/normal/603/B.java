import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int p = nextInt();
        int k = nextInt();
        long ans = 1;
        boolean used[] = new boolean[p];
        for(int i = 1;i < p;i++) {
            int v = i;
            if (!used[i]) {
                while (!used[v]) {
                    used[v] = true;
                    v = (int)(((long)v * k) % p);
                }
                ans = (ans * p) % inf;
            }
        }

        if (k == 1) ans = (ans * p) % inf;
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
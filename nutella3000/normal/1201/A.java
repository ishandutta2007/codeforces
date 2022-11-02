import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int a[] = new int [m];
        char h[][] = new char[n][];
        for(int i = 0;i < n;i++) h[i] = next().toCharArray();
        for(int i = 0;i < m;i++) a[i] = nextInt();
        int ans = 0;
        for(int i = 0;i < m;i++) {
            int c[] = new int [5];
            for(int j = 0;j < n;j++) c[h[j][i] - 'A']++;
            int max = 0;
            for(int j = 0;j < 5;j++) max = Math.max(max, c[j]);
            ans += max * a[i];
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
}
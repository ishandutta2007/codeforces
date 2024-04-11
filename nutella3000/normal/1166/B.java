import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int k = nextInt();
        boolean bad = true;
        char h[] = new char[5];
        h[0] = 'a';
        h[1] = 'e';
        h[2] = 'i';
        h[3] = 'o';
        h[4] = 'u';
        for(int n = 2;n <= Math.sqrt(k);n++) {
            if (k % n != 0) continue;
            int m = k / n;
            if (n < 5 || m < 5) continue;
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < m;j++) {
                    pw.print(h[(i + j) % 5]);
                }
            }
            bad = false;
            break;
        }
        if (bad) pw.println(-1);
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
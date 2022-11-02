import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        if (n == 2) {
            System.out.println(1);
            System.out.println(1 + " " + 1);
            return;
        }

        if (n == 1) {
            System.out.println(1);
            System.out.println(1);
            return;
        }

        boolean prime[] = new boolean[n + 2];
        for(int i = 2;i <= n + 1;i++) prime[i] = true;
        for(int i = 2;i <= n + 1;i++) {
            if (!prime[i] || i > 1e4) continue;
            for(int j = i * i;j <= n + 1;j += i) prime[j] = false;
        }
        pw.println(2);
        for(int i = 0;i < n;i++) {
            if (prime[i + 2]) pw.print(1 + " ");
            else pw.print(2 + " ");
        }

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
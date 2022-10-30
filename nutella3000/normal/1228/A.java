import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int l = nextInt();
        int r = nextInt();
        for(int i = l;i <= r;i++) {
            char u[] = String.valueOf(i).toCharArray();
            boolean used[] = new boolean[10];
            boolean bad = false;
            for(int j = 0;j < u.length;j++) {
                if (used[u[j] - '0']) bad = true;
                used[u[j] - '0'] = true;
            }

            if (!bad) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
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
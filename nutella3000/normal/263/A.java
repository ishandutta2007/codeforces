import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int a[][] = new int [5][5];
        int x = -1, y = -1;
        for(int i = 0;i < 5;i++) {
            for(int j = 0;j < 5;j++) {
                int t = nextInt();
                if (t == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        pw.println(Math.abs(2 - x) + Math.abs(2 - y));
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

    /*static long nextLong() throws IOException {
        return Long.parseLong(next());
    }*/

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        boolean cool = false;
        for(int i = 0;i < n;i++) {
            int a = nextInt();
            if (a == 1) cool = true;
        }

        if (cool) pw.println("HARD");
        else pw.println("Easy");
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
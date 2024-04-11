import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int cnt = 0;
        char h[] = next().toCharArray();
        for(int i = 0;i < n;i++) {
            if (h[i] == 'A') cnt++;
            else cnt--;
        }
        if (cnt > 0) pw.println("Anton");
        else if (cnt < 0) pw.println("Danik");
        else pw.println("Friendship");
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
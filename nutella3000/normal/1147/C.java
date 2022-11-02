import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        boolean win = true;
        for(int i = 0;i <= 50;i++) {
            int cnt = 0;
            for(int j = 0;j < n;j++) if(a[j] == i) cnt++;
            if (cnt > n / 2) {
                win = false;
                break;
            }
            if (cnt > 0) {
                win = true;
                break;
            }
        }
        if (win) pw.println("Alice");
        else pw.println("Bob");
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

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
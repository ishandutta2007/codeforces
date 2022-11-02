import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = nextInt();
        for(int i = 0;i < t;i++) {
            int n = nextInt();
            char h[] = next().toCharArray();
            int cnt = n + 1;
            for(int j = 0;j < h.length;j++) {
                if (h[j] == '8') {
                    cnt = j;
                    break;
                }
            }
            if (n - cnt >= 11) pw.println("YES");
            else pw.println("NO");
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
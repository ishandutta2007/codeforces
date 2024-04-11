import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = nextInt();
        while(t-- > 0) {
            int b = nextInt();
            int p = nextInt();
            int f = nextInt();
            int h = nextInt();
            int c = nextInt();
            int ans = 0;
            if (h > c) {
                ans += Math.min(b / 2, p) * h;
                b -= 2 * Math.min(b / 2, p);
                ans += Math.min(b / 2, f) * c;
            } else{
                ans += Math.min(b / 2, f) * c;
                b -= 2 * Math.min(b / 2, f);
                ans += Math.min(b / 2, p) * h;
            }
            pw.println(ans);
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
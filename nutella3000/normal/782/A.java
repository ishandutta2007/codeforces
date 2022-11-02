import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        //Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);

        int n = nextInt();
        int a[] = new int [2 * n];
        boolean b[] = new boolean[n + 1];
        int ans = 0;
        int cnt = 0;
        for(int i = 0;i < 2 * n;i++) {
            int v = nextInt();
            if (!b[v]) cnt++;
            else cnt--;
            b[v] = !b[v];
            ans = Math.max(ans, cnt);
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
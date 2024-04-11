import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, a[], k;
    static int f() {
        int first = n + 1;
        int last = -1;
        for(int i = 0;i < n;i++) if (a[i] == 0) last = i;
        for(int i = n - 1;i >= 0;i--) if (a[i] == 0) first = i;
        if (last - first + 1 <= k) return 1;
        if (last - first + 1 != k + 1 || first >= k || (n - last - 1) >= k) return 3;
        return 2;
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        n = nextInt();
        k = nextInt();
        a = new int [n];
        char t[] = next().toCharArray();
        for(int i = 0;i < n;i++) a[i] = t[i] - '0';
        int ans1 = f();
        for(int i = 0;i < n;i++) a[i] = 1 - a[i];
        int ans2 = f();

        if (ans1 == 1 || ans2 == 1) pw.println("tokitsukaze");
        else if (ans1 == 3 || ans2 == 3) pw.println("once again");
        else pw.println("quailty");
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
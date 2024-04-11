import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        char h[] = next().toCharArray();
        int a[] = new int [n];
        int b[] = new int [n];
        for(int i = 0;i < n;i++) {
            b[i] = nextInt();
            a[i] = nextInt();
        }
        int ans = 0;
        for(int i = 0;i <= 100000;i++) {
            int new_ans = 0;
            for(int j = 0;j < n;j++) {
                if (i < a[j]) new_ans += h[j] - '0';
                else{
                    int v = (i - a[j]) / b[j];
                    if (v % 2 == 1) new_ans += h[j] - '0';
                    else new_ans += (1 - (h[j] - '0'));
                }
            }
            ans = Math.max(new_ans, ans);
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
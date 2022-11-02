import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static int inf = (int) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = nextInt();
        for(int req = 0;req < t;req++) {
            char a[] = next().toCharArray();
            char b[] = next().toCharArray();
            int id = 0;
            boolean ans = true;
            for(int i = 0;i < b.length;i++) {
                if (id != a.length && a[id] == b[i]) id++;
                else{
                    if (i == 0 || b[i - 1] != b[i]) ans = false;
                }
            }
            if (id != a.length) ans = false;
            if (ans) pw.println("YES");
            else pw.println("NO");
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}
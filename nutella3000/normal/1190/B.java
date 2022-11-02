import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        Arrays.sort(a);
        int cnt_bad = 0;
        int id = 0;
        for(int i = 1;i < n;i++) {
            if (a[i] == a[i - 1]) {
                cnt_bad++;
                id= i - 1;
            }
        }
        if (cnt_bad >= 2 || (n == 1 && a[0] == 0) || (n != 1 && a[1] == 0) || (cnt_bad == 1 && id - 1 >= 0 && a[id - 1] == a[id] - 1)) {
            pw.println("cslnb");
        }else{
            long cnt = (long) (n - 1) * n / 2;
            long sum = 0;
            for(int i = 0;i < n;i++) sum += a[i];
            if (sum % 2 == cnt % 2) pw.println("cslnb");
            else pw.println("sjfnb");
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
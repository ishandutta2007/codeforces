import javax.smartcardio.ATR;
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = Math.abs(nextInt());
        long ans = 0;
        Arrays.sort(a);
        for(int i = 0;i < n;i++) {
            int l = i;
            int r = n;
            while(l != r - 1) {
                int m = (l + r) / 2;
                if (a[m] <= a[i] * 2) l = m;
                else r = m;
            }
            ans += l - i;
        }
        pw.print(ans);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

    public static long nextLong() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer((br.readLine()));
        }
        return Long.parseLong(st.nextToken());
    }

    public static double nextDouble() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}
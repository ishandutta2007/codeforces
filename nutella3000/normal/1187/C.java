import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;
    static int type[], l[], r[], ans[];
    static boolean check() {
        for(int i = 0;i < type.length;i++) {
            boolean sorted = true;
            for(int j = l[i] + 1;j <= r[i];j++) {
                if (ans[j] < ans[j - 1]) sorted = false;
            }
            if ((type[i] == 1 && !sorted)) while(true);
            if ((type[i] == 0 && sorted)) return false;
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        type = new int [m];
        l = new int [m];
        r = new int [m];
        ans = new int [n];
        int sorted[] = new int[n];
        for(int i = 0;i < m;i++) {
            type[i] = nextInt();
            l[i] = nextInt() - 1;
            r[i] = nextInt() - 1;
            if (type[i] == 1) {
                int last_one = -1;
                for(int j = 0;j < l[i];j++) {
                    if (sorted[j] == 1) last_one = j;
                    if (sorted[j] == 2) last_one = -1;
                }
                if (sorted[l[i]] == 1) last_one = 1;
                if (last_one == -1) {
                    sorted[l[i]] = 1;
                }else {
                    if (sorted[l[i]] == 2) {
                        last_one = -1;
                        sorted[l[i]] = 0;
                    }
                }
                for(int j = l[i] + 1;j <= r[i];j++) {
                    if (sorted[j] == 1) last_one = 1;
                    if (sorted[j] == 2) last_one = -1;
                    sorted[j] = 0;
                }
                if (last_one == -1) sorted[r[i]] = 2;
            }
        }
        boolean in = false;
        int num = 1;
        for(int i = n - 1;i >= 0;i--) {
            ans[i] = num;
            if (i == 0) continue;
            if (sorted[i] == 1) in = false;
            if (sorted[i] == 2) in = true;
            if (!in) num++;
        }
        if (check()) {
            pw.println("YES");
            for(int i : ans) pw.print(i + " ");
        }else pw.print("NO");
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
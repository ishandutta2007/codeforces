import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static int inf = (int) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        int a[] = new int [k + 1];
        for(int i = 0;i < n;i++) a[nextInt()]++;
        int cnt = 0;
        int p = (n + 1) / 2;
        while(p != 0) {
            int id = -1;
            int id2 = -1;
            for(int i = 0;i <= k;i++) {
                if (a[i] >= 2) id = i;
                if (a[i] > 0) id2 = i;
            }
            if (id == -1) {
                if (id2 == -1) break;
                p--;
                cnt++;
                a[id2] = 0;
            }else{
                p--;
                cnt += 2;
                a[id] -= 2;
            }
        }
        pw.println(cnt);
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
    static Double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
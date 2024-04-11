import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int q = nextInt();
        while(q-- > 0) {
            int n = nextInt();
            int a[] = new int [n];
            for(int i = 0;i < n;i++) a[i] = nextInt();
            int ans = inf;
            int first = n + 1;

            int last_en[] = new int [n + 1];
            int first_en[] = new int [n + 1];
            for(int i = 0;i <= n;i++) {
                first_en[i] = inf;
                last_en[i] = -1;
            }

            for(int i = 0;i < n;i++) last_en[a[i]] = i;
            for(int i = n - 1;i >= 0;i--) first_en[a[i]] = i;

            int good_cnt = 0;
            for(int i = 0;i <= n;i++) if (first_en[i] != inf) good_cnt++;

            int id = n;
            while(id != -1 && last_en[id] < first) {
                if (first_en[id] != inf) {
                    first = first_en[id];
                    good_cnt--;
                }
                id--;
            }

            ans = good_cnt;

            for(int i = n;i >= 0;i--) {

                if (first_en[i] == first) {
                    first = n + 1;
                    
                    while(id != -1 && last_en[id] < first) {
                        if (first_en[id] != inf) {
                            first = first_en[id];
                            good_cnt--;
                        }
                        id--;
                    }
                }

                if (first_en[i] != inf) good_cnt++;

                ans = Math.min(ans, good_cnt);
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
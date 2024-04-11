import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = nextInt();

        while(t-- > 0) {
            int n = nextInt();
            char temp[] = next().toCharArray();
            int a[] = new int [n];
            for(int i = 0;i < n;i++) a[i] = temp[i] - '0';

            int ans[] = new int [n];
            int r[] = new int [10];
            for(int i = 0;i < 10;i++) r[i] = -1;

            for(int i = 0;i < n;i++) r[a[i]] = i;

            int min_two = 10;

            for(int i = 0;i < n;i++) {
                boolean one = true;
                for(int j = 0;j < a[i];j++) {
                    if (r[j] > i) one = false;
                }
                if (min_two < a[i]) one = false;
                if (one) ans[i] = 1;
                else {
                    ans[i] = 2;
                    min_two = Math.min(min_two, a[i]);
                }
            }

            int last = -1;
            boolean have = true;

            for(int i = 0;i < n;i++) {
                if (ans[i] == 1) {
                    if (last > a[i]) {
                        have = false;
                    }
                    last = a[i];
                }
            }
            boolean last_one = true;
            for(int i = 0;i < n;i++) {
                if (ans[i] == 2) {
                    if (last > a[i]) {
                        have = false;
                    }
                    last_one = false;
                    last = a[i];
                }
            }


            if (have) {
                for(int i = 0;i < n;i++) pw.print(ans[i]);
            }
            else {
                //if (n != 3) while(true);
                pw.print("-");
            }
            pw.println();
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
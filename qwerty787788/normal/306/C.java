import java.io.*;
import java.util.*;

public class CFstupid {
    FastScanner in;
    PrintWriter out;

    long mod = (long) 1e9 + 9;
    
    void solve() {
       int n = in.nextInt();
       int w = in.nextInt();
       int b = in.nextInt();
       long ans = 0;
       int MAX = 8005;
       int[][] c = new int[MAX][MAX / 2];
       c[0][0] = 1;
       for (int i = 1; i < MAX; i++) {
           c[i][0] = 1;
           for (int j = 1; j < MAX / 2; j++) {
               long tmp = (c[i - 1][j - 1] + c[i - 1][j]);
               if (tmp >= mod)
                   tmp -= mod;
               c[i][j] = (int) tmp;
           }
           
       }
       for (int fr = 1; fr < n; fr++) {
           for (int to = fr; to < n - 1; to++) {
               if (to - fr + 1 <= b) {
                   int ost = n - (to - fr + 1);
                   if (ost <= w) {
                       long add = 1;
                       add = (add * c[w - 1][ost - 1]) % mod;
                       add = (add * c[b - 1][to - fr]) % mod;
                       ans += add;
                       ans %= mod;
                   }
               }
           }
       }
       for (int i = 1; i <= w; i++)
           ans = (ans * i) % mod;
       for (int i = 1; i <= b; i++)
           ans = (ans * i) % mod;
       out.println(ans);
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CFstupid().runIO();
    }
}
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            pair a[] = new pair[n];
            for(int i = 0;i < n;i++) a[i] = new pair(sc.nextInt(), sc.nextInt(), sc.nextInt());
            Arrays.sort(a, new pair());

            int l = m;
            int r = m;
            int last = 0;
            boolean bad = false;
            for(int i = 0;i < n;i++) {
                int time = a[i].t - last;
                int new_r = r + time;
                int new_l = l - time;
                new_l = Math.max(new_l, a[i].l);
                new_r = Math.min(new_r, a[i].r);

                l = new_l;
                r = new_r;
                if (r < l) bad = true;

                last = a[i].t;
            }

            if (bad) pw.println("NO");
            else pw.println("YES");
        }
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

}

class pair implements Comparator<pair>{
    int t, l, r;
    pair(int t, int l, int r) {
        this.t = t;
        this.l = l;
        this.r = r;
    }
    pair() {}
    @Override
    public int compare(pair pair, pair t1) {
        return Integer.compare(pair.t, t1.t);
    }
}
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;

    static int[] ord(int a[]) {
        int ans[] = new int [n];
        int temp[] = new int [n];
        for(int i = 0;i < n;i++) temp[i] = 1;
        fenwick b = new fenwick(temp);

        for(int i = 0;i < n;i++) {
            b.add(a[i], -1);
            ans[i] = b.get_pref(a[i]);
        }

        return ans;
    }

    static int[] rev_ord(int a[]) {
        int temp[] = new int [n];
        for(int i = 0;i < n;i++) temp[i] = 1;
        fenwick b = new fenwick(temp);

        int ans[] = new int [n];
        for(int i = 0;i < n;i++) {
           int l = -1;
           int r = n;
           while(r - l > 1) {
               int mid = ((l + r) >> 1);
               if (b.get_pref(mid) < a[i] + 1) l = mid;
               else r = mid;
           }
           b.add(r, -1);
           ans[i] = r;
        }
        return ans;
    }

    static void solve() throws IOException {
        n = sc.nextInt();
        int a[] = new int [n];
        int b[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        for(int i = 0;i < n;i++) b[i] = sc.nextInt();
        int a1[] = ord(a);
        int b1[] = ord(b);
        int c1[] = new int [n];
        for(int i = 0;i < n;i++) c1[i] = a1[i] + b1[i];
        for(int i = n - 1;i >= 0;i--) {
            if (c1[i] >= (n - i)) {
                c1[i] -= (n - i);
                if (i != 0) c1[i - 1]++;
            }
        }

        int c[] = rev_ord(c1);

        for(int i = 0;i < n;i++) pw.print(c[i] + " ");

    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();
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

class fenwick {
    int sum[];

    int f(int x) {
        return x & (x + 1);
    }
    int h(int x) {
        return x | (x + 1);
    }

    fenwick(int a[]) {
        sum = new int [a.length];
        for(int i = 0;i < a.length;i++) add(i, a[i]);
    }

    void add(int id, int x) {
        while(id < sum.length) {
            sum[id] += x;
            id = h(id);
        }
    }

    int get_pref(int r) {
        int ans = 0;
        while(r >= 0) {
            ans += sum[r];
            r = f(r) - 1;
        }
        return ans;
    }

    int get(int l, int r) {
        return get_pref(r) - get_pref(l - 1);
    }

    void set(int id) {
        if (id + 1 >= sum.length) return;
        add(id, get_pref(id + 1) - get_pref(id));
    }

}
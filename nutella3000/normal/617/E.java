import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, m, a[], k, size = 1000;
    static pair req[];
    static long ans[];

    static void scan() throws IOException {
        n = sc.nextInt() + 1;
        m = sc.nextInt();
        k = sc.nextInt();
        a = new int [n];
        req = new pair[m];
        for(int i = 1;i < n;i++) {
            a[i] = sc.nextInt();
            a[i] = (a[i] ^ a[i - 1]);
        }

        for(int i = 0;i < m;i++) {
            int l = sc.nextInt() - 1;
            int r = sc.nextInt();
            req[i] = new pair(l, r, i);
        }

        Arrays.sort(req, new Comparator<pair>() {
            @Override
            public int compare(pair o1, pair o2) {
                return Integer.compare(o1.l / size, o2.l / size) * 2 + Integer.compare(o1.r, o2.r);
            }
        });

        ans = new long [m];
    }

    static int add(int[] cnt, int v) {
        int ans = cnt[v ^ k];
        cnt[v]++;
        return ans;
    }

    static int remove(int[] cnt, int v) {
        cnt[v]--;
        return cnt[v ^ k];
    }


    static void solve() throws IOException {
        scan();

        int v_l = req[0].l;
        int v_r = v_l - 1;
        int[] cnt = new int[(int) 2e6];
        long sum = 0;

        for(int q = 0;q < m;q++) {
            if (v_l / size != req[q].l / size) {
                v_l = req[q].l;
                v_r = v_l - 1;
                for(int i = 0;i < n;i++) {
                    cnt[a[i]] = 0;
                }

                sum = 0;
            }

            while(v_r != req[q].r) {
                v_r++;
                sum += add(cnt, a[v_r]);
            }

            while(v_l < req[q].l) {
                sum -= remove(cnt, a[v_l++]);
            }

            while(v_l > req[q].l) {
                sum += add(cnt, a[--v_l]);
            }

            ans[req[q].id] = sum;
        }

        for(int i = 0;i < m;i++) pw.println(ans[i]);
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

class pair {
    int l, r, id;
    pair(int l, int r, int id) {
        this.l = l;
        this.r = r;
        this.id = id;
    }
    pair() {}
}
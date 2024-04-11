import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int n;
    static char h[][];
    static int sqrt = 500;

    static int[] z_func(char a[]) {
        int n = a.length;
        int res[] = new int[n];
        int l = 0, r = 0;
        int iter = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r)
                res[i] = Math.min(r - i, res[i - l]);

            while (i + res[i] < n && a[i + res[i]] == a[res[i]]) {
                res[i]++;
                iter++;
            }

            if (i + res[i] > r) {
                l = i;
                r = i + res[i];
            }
        }
        if (iter > 3 * n) n /= 0;
        return res;
    }

    static int[] z_func(char a[], char b[]) {
        char q[] = new char[a.length + b.length + 1];
        for (int i = 0; i < b.length; i++) q[i] = b[i];
        for (int i = 0; i < a.length; i++) q[i + b.length + 1] = a[i];
        int fuck[] = z_func(q);
        int res[] = new int[a.length];
        for (int i = 0; i < a.length; i++) res[i] = fuck[i + b.length + 1];
        return res;
    }


    static int[] f(char a[]) {
        int res[] = new int [a.length];

        int trie[][] = new int [200000][26];
        int cnt[] = new int [200000];
        int size = 1;
        for(int i = 0;i < 200000;i++) {
            for(int j = 0;j < 26;j++) trie[i][j] = -1;
        }


        for (int i = 0; i < n; i++) {
            if (h[i].length >= sqrt) {
                int z[] = z_func(a, h[i]);
                for(int j = 0;j < a.length;j++) {
                    if (z[j] == h[i].length) res[j + h[i].length - 1]++;
                }
            }else{
                int v = 0;
                for(char j : h[i]) {
                    if (trie[v][j - 'a'] == -1) trie[v][j - 'a'] = size++;
                    v = trie[v][j - 'a'];
                }
                cnt[v]++;
            }
        }

        for(int start = 0;start < a.length;start++) {
            int v = 0;
            for(int j = start;j < Math.min(start + sqrt, a.length);j++) {
                if (trie[v][a[j] - 'a'] == -1) break;
                v = trie[v][a[j] - 'a'];
                res[j] += cnt[v];
            }
        }

        return res;
    }

    static char[] reverse(char h[]) {
        char[] res = new char[h.length];
        for(int i = 0;i < h.length;i++) res[h.length - i - 1] = h[i];
        return res;
    }

    static void solve() throws IOException {
        char a[] = sc.next().toCharArray();
        n = sc.nextInt();
        h = new char[n][];
        for(int i = 0;i < n;i++) h[i] = sc.next().toCharArray();

        int suf[] = f(a);
        for(int i = 0;i < n;i++) h[i] = reverse(h[i]);
        a = reverse(a);

        int pref[] = f(a);

        long ans = 0;

        for(int i = 0;i < a.length - 1;i++) {
            ans += ((long)suf[i] * (pref[a.length - i - 2]));
        }

        pw.println(ans);
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
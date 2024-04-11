
import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, a[];

    static int min() {
        int ans = inf;
        for(int i = 0;i < n;i++) ans = Math.min(ans, a[i]);
        return ans;
    }

    static int cnt(int l, int r, int num) {
        int ans = 0;
        for(int i = l;i <= r;i++) if (a[i] == num) ans++;
        return ans;
    }

    static pair check(pair a) {
        if (a.l < 0 || a.r >= n) return new pair(0, 0, 0);
        return a;
    }

    static pair max(pair a, pair b) {
        a = check(a);
        b = check(b);
        if (a.ans > b.ans) return a;
        return b;
    }

    static void scan() throws IOException {
        n = sc.nextInt();
        char h[] = sc.next().toCharArray();
        a = new int [n];
        for(int i = 0;i < n;i++) {
            a[i] = (h[i] == '(' ? 1 : -1);
            if (i != 0) a[i] += a[i - 1];
        }
    }

    static pair zero() {
        return new pair(0, 0, cnt(0, n - 1, min()));
    }

    static pair plus() {
        int min = min();
        int l = inf;
        int r = -1;
        for(int i = 0;i < n;i++) {
            if (l == inf && a[i] == min) l = i;
            if (a[i] == min) r = i;
        }

        return max(plus1(l, r, min), plus2(l, r, min));
    }

    static pair plus1(int l, int r, int min) {
        int ans = cnt(0, l - 1, min + 1) + cnt(r + 1, n - 1, min + 1);
        return new pair(l, r + 1, ans);
    }

    static pair plus2(int l, int r, int min) {
        int l1 = l;
        int r1 = r;
        for(int i = 0;i < n;i++) {
            if (a[i] == min + 1 && l1 > i) l1 = i;
            if (a[i] == min + 1 && r1 < i) r1 = i;
        }


        int ans = cnt(0, n - 1, min);
        for(int i = 0;i < n;i++) {
            if ((i < l1 || i > r1) && a[i] == min + 2) ans++;
        }

        return new pair(l1, r1 + 1, ans);
    }

    static pair minus() {
        int min = min();
        int cnt = cnt(0, n - 1, min);
        int l = 0;
        pair ans = new pair(0, 0, 0);
        for(int i = 0;i <= n;i++) {
            if (i == n || a[i] == min) {
                ans = max(ans, minus(l, i - 1, min, cnt));
                l = i + 1;
            }
        }
        return ans;
    }

    static pair minus(int l, int r, int min, int cnt) {
        int cnt1 = 0;
        int cnt2 = 0;
        pair ans = new pair(0, 0, 0);
        int l1 = l;
        for(int i = l;i <= r;i++) {
            if (a[i] == min + 1) {
                cnt1++;
                ans = max(ans, minus2(l1, i - 1, min, cnt));
                l1 = i + 1;
            }

            if (a[i] == min + 2) cnt2++;

        }

        ans = max(ans, minus2(l1, r, min, cnt));

        if (cnt1 > 0) return max(new pair(l, r + 1, cnt1), ans);
        return new pair(l, r + 1, cnt + cnt2);
    }

    static pair minus2(int l, int r, int min, int cnt) {
        return new pair(l, r + 1, cnt(l, r, min + 2) + cnt);
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        scan();
        if (a[n - 1] != 0) {
            System.out.println(0);
            System.out.println(1 + " " + 1);
            return;
        }
        pair ans = max(zero(), max(plus(), minus()));
        pw.println(ans.ans);
        pw.println(ans.l + 1 + " " + (ans.r + 1));

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
    int l, r, ans;

    pair(int l, int r, int ans) {
        this.l = l;
        this.r = r;
        this.ans = ans;
    }

    pair() {}
}
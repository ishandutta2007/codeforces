import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class E {

    private int[] a;
    private long[] l;
    private int n;
    private long s;
    private long[] f;

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        s = nextLong();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        f = new long[19];
        f[0] = 1;
        for (int i = 1; i < 19; i++) {
            f[i] = f[i - 1] * i;
        }

        int n1 = n / 2;
        int n2 = n - n1;
        int[] a1 = new int[n1];
        int[] a2 = new int[n2];
        System.arraycopy(a, 0, a1, 0, n1);
        System.arraycopy(a, n1, a2, 0, n2);

        long[] l1 = new long[2000000];
        long[] l2 = new long[2000000];

        long res = 0;
        for (int k1 = 0; k1 <= k; k1++) {
            if (k1 > n1) continue;
            this.a = a1;
            this.l = l1;
            this.n = 0;
            gen(0, k1, 0);
            int m1 = this.n;
            Arrays.sort(l1, 0, m1);
            for (int k2 = 0; k1 + k2 <= k; k2++) {
                if (k2 > n2) continue;
                this.a = a2;
                this.l = l2;
                this.n = 0;
                gen(0, k2, 0);
                int m2 = this.n;
                Arrays.sort(l2, 0, m2);
                int i = 0;
                int j = m2 - 1;
                while (i < m1 && j >= 0) {
                    long s = l1[i] + l2[j];
                    if (s > this.s) {
                        j--;
                    } else if (s < this.s) {
                        i++;
                    } else {
                        long c1 = 1;
                        long c2 = 1;
                        while (i < m1 - 1 && l1[i + 1] == l1[i]) {
                            i++;
                            c1++;
                        }
                        while (j >= 1 && l2[j - 1] == l2[j]) {
                            j--;
                            c2++;
                        }
                        i++;
                        j--;
                        res += c1 * c2;
                    }
                }
            }
        }
        out.println(res);


    }

    private void gen(int i, int k, long s) {
        if (s > this.s) return;
        if (i == a.length) {
            l[n++] = s;
            return;
        }
        if (k > 0 && a[i] < 19) {
            gen(i + 1, k - 1, s + f[a[i]]);
        }
        if (i + k < a.length) {
            gen(i + 1, k, s + a[i]);
            gen(i + 1, k, s);
        }
    }

    private long nextLong() throws IOException {
        return Long.parseLong(next());
    }


    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new E().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}
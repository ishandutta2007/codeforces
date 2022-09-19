import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class F {

    private int[] s;
    private int k;
    private int[] x;
    private int zzz;

    private void solve() throws IOException {
        int n = nextInt();
        x = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = nextInt();
        }
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            y[i] = nextInt();
        }
        s = new int[50];
        k = 0;
        for (int i = 0; i < n; i++) {
            if (x[i] > 0 && !canMake(x[i])) {
                s[k++] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!canMake(y[i])) {
//                System.err.println(y[i]);
                out.println(-1);
                return;
            }
        }
        for (int i = 0; i < n; i++) {
            boolean ok = true;
            for (int j = 0; j < k; j++) {
                if (s[j] == i) ok = false;
            }
            if (ok) {
                move(i, i);
                canMake(y[i]);
                for (int j = 0; j < k; j++) {
                    if (bit(zzz, j)) {
                        move(i, s[j]);
                    }
                }
            }
        }
        int[] a = new int[k];
        for (int i = 0; i < k; i++) {
            canMake(y[s[i]]);
            a[i] = zzz;
        }
//        for (int i = 0; i < k; i++) {
//            for (int i = 0; i )
//        }
        int c1 = mn;
        for (int i = 0; i < k; i++) {
            for (int t = i; t < k; t++) {
                if (bit(a[t], i)) {
                    if (t != i) {
                        move(s[i], s[t]);
                        a[i] ^= a[t];
                    }
                    for (int j = 0; j < k; j++) {
                        if (i != j && bit(a[j], i)) {
                            move(s[j], s[i]);
                            a[j] ^= a[i];
                        }
                    }
                    break;
                }
            }
        }
        int c2 = mn;
        for (int i = 0; i < k; i++) {
            if (!bit(a[i], i)) {
                for (int j = 0; j < k; j++) {
                    if (bit(a[j], i)) {
                        move(s[j], s[i]);
                    }
                }
                move(s[i], s[i]);
            }
        }
//
//        for (int i = 0; i < mn; i++) {
//            x[moves[0][i]] ^= x[moves[1][i]];
//        }
//        for (int i = 0; i < n; i++) {
//            if (x[i] != y[i]){
//                System.out.println(Arrays.toString(x) + " " + Arrays.toString(y));
//                break;
//            }
//        }
//        System.out.println(ll);
        out.println(mn);
        for (int i = 0; i < c1; i++) {
            out.println((moves[0][i] + 1) + " " + (moves[1][i] + 1));
            x[moves[0][i]] ^= x[moves[1][i]];
        }
//        out.println();
        for (int i = c2; i < mn; i++) {
            out.println((moves[0][i] + 1) + " " + (moves[1][i] + 1));
            x[moves[0][i]] ^= x[moves[1][i]];
        }
//        out.println();
        for (int i = c2 - 1; i >= c1; i--) {
            out.println((moves[0][i] + 1) + " " + (moves[1][i] + 1));
            x[moves[0][i]] ^= x[moves[1][i]];
        }
        for (int i = 0; i < n; i++) {
            if (x[i] != y[i]) {
                throw new RuntimeException();
            }
        }
    }

    int[][] moves = new int[2][1000000];
    int mn;

    private void move(int i, int j) {
        moves[0][mn] = i;
        moves[1][mn] = j;
        mn++;
    }

    private boolean canMake(int z) {
        int[] q = new int[k + 1];
        int[] w = new int[k + 1];
        boolean[] zz = new boolean[k + 1];
        for (int i = 0; i < k; i++) {
            q[i] = x[s[i]];
            w[i] = (1 << i);
        }
        q[k] = z;
        for (int j = 0; j < 31; j++) {
            int t = 0;
            while (t < k && (zz[t] || !bit(q[t], j))) t++;
            if (t < k) {
                zz[t] = true;
                for (int i = 0; i <= k; i++) {
                    if (i != t && bit(q[i], j)) {
                        q[i] ^= q[t];
                        w[i] ^= w[t];
                    }
                }
            }
        }
        zzz = w[k];
        return q[k] == 0;
    }

    private boolean bit(int i, int j) {
        return ((i >> j) & 1) == 1;
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
        new F().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}
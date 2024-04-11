import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Z123D {

    private String ss;
    private SuffixAutomaton aut;

    private void solve() throws IOException {
        ss = next();
        ss += (char)('z' + 1);
        aut = new SuffixAutomaton(ss);
//        for (int i= 1; i < aut.n; i++) {
//            for (int j = 0; j < aut.ALPHA_SIZE; j++) {
//                int x = aut.next[i * aut.ALPHA_SIZE + j];
//                if (x != 0) {
//                    System.out.println(i + " - " + x + " " + (char)('a'+j));
//                }
//            }
//        }
        size = new int[aut.n];
        p = new int[aut.n];
        cur = aut.n - 1;
        z = new boolean[aut.n];
        dfs(aut.root);
        size2 = new int[aut.n];
        size2[aut.root] = 1;
        for (int vv = 0; vv < aut.n; vv++) {
            int v = p[vv];
            for (int i = 0; i < SuffixAutomaton.ALPHA_SIZE; i++) {
                int x = v * SuffixAutomaton.ALPHA_SIZE + i;
                int u = aut.next[x];
                if (u > 0) {
                    size2[u] += size2[v];
                    res += 1l * size2[v] * size[u] * (size[u] + 1) / 2;
                }
            }
        }
//        System.out.println(Arrays.toString(p));
//        System.out.println(Arrays.toString(size));
//        System.out.println(Arrays.toString(size2));
        out.println(res - ss.length());
    }

    int[] size;
    int[] size2;
    int[] p;
    int cur;
    boolean[] z;

    long res = 0;

    private void dfs(int v) {
        if (z[v]) return;
        z[v] = true;
        if (v == aut.last) {
            size[v] = 1;
        } else {
            for (int i = 0; i < SuffixAutomaton.ALPHA_SIZE; i++) {
                int x = v * SuffixAutomaton.ALPHA_SIZE + i;
                int u = aut.next[x];
                if (u > 0) {
                    dfs(u);
                    size[v] += size[u];
                }
            }
        }
        p[cur--] = v;
    }


    /**
     * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
     * (translated from C++ by Pavel Mavrin)
     */

    class SuffixAutomaton {

        public static final int ALPHA_SIZE = 27;
        public int root, last, n;
        public final int len[], suf[], next[];

        public SuffixAutomaton(String s) {
            len = new int[2 * s.length() + 2];
            suf = new int[2 * s.length() + 2];
            //compressed 2d array. next[i][j] -> next[i * ALPHA_SIZE + j];
            next = new int[(2 * s.length() + 2) * ALPHA_SIZE];
            for (int i = 0; i < ALPHA_SIZE; i++)
                next[i] = 1;
            n = 1;
            root = last = newV(0, 0);
            for (int i = 0; i < s.length(); i++) {
                int ch = s.charAt(i) - 'a';
                int R, Q, P = last;
                last = newV(len[last] + 1, 0);
                while (next[P * ALPHA_SIZE + ch] == 0) {
                    next[P * ALPHA_SIZE + ch] = last;
                    P = suf[P];
                }
                if (P == 0)
                    suf[last] = 1;
                else if (len[Q = next[P * ALPHA_SIZE + ch]] == len[P] + 1)
                    suf[last] = Q;
                else {
                    R = newV(len[P] + 1, suf[Q]);
                    suf[last] = suf[Q] = R;
                    System.arraycopy(next, Q * ALPHA_SIZE, next, R * ALPHA_SIZE, ALPHA_SIZE);
                    while (P > 0 && next[P * ALPHA_SIZE + ch] == Q) {
                        next[P * ALPHA_SIZE + ch] = R;
                        P = suf[P];
                    }
                }
            }
        }

        private int newV(int l, int _suf) {
            if ((n >= len.length)) throw new AssertionError();
            for (int i = 0; i < ALPHA_SIZE; i++) {
                next[n * ALPHA_SIZE + i] = 0;
            }
            len[n] = l;
            suf[n] = _suf;
            return n++;
        }
    }


    //eqkrqe
    // e 3 6+5+4+3+2+1 21

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
        new Z123D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}
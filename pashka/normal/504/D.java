import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.BitSet;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    private void solve() throws IOException {
        int m = nextInt();
        BitSet[] a = new BitSet[m];
        BitSet[] b = new BitSet[m];
        for (int i = 0; i < m; i++) {
            BigInteger z = new BigInteger(next());
            a[i] = new BitSet(2000);
            for (int j = 0; j < 2000; j++) {
                if (z.testBit(j)) {
                    a[i].set(j, true);
                }
            }
            b[i] = new BitSet(2000);
            b[i].set(i, true);
        }
        for (int i = 0; i < m; i++) {
            int q = a[i].nextSetBit(0);
            if (q >= 0) {
                for (int j = i + 1; j < m; j++) {
                    if (a[j].get(q)) {
                        a[j].xor(a[i]);
                        b[j].xor(b[i]);
                    }
                }
                out.println(0);
            } else {
                out.print(b[i].cardinality() - 1 + " ");
                for (int j = b[i].nextSetBit(0); j >= 0; j = b[i].nextSetBit(j + 1)) {
                    if (j != i)
                        out.print(j + " ");
                }
                out.println();
            }
        }

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
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}
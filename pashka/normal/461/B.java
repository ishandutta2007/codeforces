import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private static final long MOD = 1000000007;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintStream out = System.out;

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
        new B().solve();
    }

    private void solve() throws IOException {
        int n = nextInt();
        IntList[] c = new IntList[n];
        for (int i = 0; i < n; i++) c[i] = new IntList();
        for (int i = 1; i < n; i++) {
            c[nextInt()].add(i);
        }
        boolean[] b = new boolean[n];
        for (int i = 0; i < n; i++) b[i] = nextInt() == 1;
        long[] d1 = new long[n];
        long[] d2 = new long[n];
        for (int i = n - 1; i >= 0; i--) {
            if (b[i]) {
                d2[i] = 0;
                d1[i] = 1;
                for (int j = 0; j < c[i].size; j++) {
                    int x = c[i].get(j);
                    d1[i] *= (d1[x] + d2[x]);
                    d1[i] %= MOD;
                }
            } else {
                d2[i] = 1;
                for (int j = 0; j < c[i].size; j++) {
                    int x = c[i].get(j);
                    d2[i] *= (d1[x] + d2[x]);
                    d2[i] %= MOD;
                }
                d1[i] = 0;
                for (int j = 0; j < c[i].size; j++) {
                    int x = c[i].get(j);
                    long z = d2[i] * d1[x];
                    z %= MOD;
                    z *= inv(d1[x] + d2[x]);
                    z %= MOD;
                    d1[i] += z;
                    d1[i] %= MOD;
                }
            }
        }
        out.println(d1[0]);
    }

    private long inv(long l) {
        return BigInteger.valueOf(l).modInverse(BigInteger.valueOf(MOD)).longValue();
    }

    class IntList {
        int[] ints = new int[1];
        int size;
        void add(int v) {
            if (size == ints.length) {
                int[] newInts = new int[ints.length * 2];
                System.arraycopy(ints, 0, newInts, 0, ints.length);
                ints = newInts;
            }
            ints[size++] = v;
        }
        int get(int i) {
            return ints[i];
        }
    }
}
import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class H {
    FastScanner in;
    PrintWriter out;

    public static final long P = 1_000_000_007;

    public void solve() throws IOException {
        long n = in.nextInt() + 1;
        long s = 1;
        long s2 = 1;
        for (long i = 1; i <= n; i++) {
            s = (s * i) % P;
        }
        for (long i = 1; i <= 2 * n; i++) {
            s2 = (s2 * i) % P;
        }
        long m = BigInteger.valueOf(s).modPow(BigInteger.valueOf(P - 2), BigInteger.valueOf(P)).longValue();
        out.println((((s2 * m) % P )* m  + P - 1) % P);
    }

    public void run() {
        try {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);
            Locale.setDefault(Locale.US);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new H().run();
    }
}
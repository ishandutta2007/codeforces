import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Set;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public static final int BUBEN = 24;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            Random random = new Random(5631653553151L + System.currentTimeMillis());
            BigInteger n = new BigInteger(in.next());
            List<BigInteger> factors = factor(n, random, in, out);
            Collections.sort(factors);
            out.print("! " + factors.size());
            for (BigInteger x : factors) {
                out.print(" " + x);
            }
            out.println();
            out.flush();
        }

        private List<BigInteger> factor(BigInteger n, Random random, InputReader in, PrintWriter out) {
            List<BigInteger> result = new ArrayList<>();
            if (n.bitLength() < BUBEN) {
                long v = n.longValue();
                for (long i = 2; i * i <= v; ++i) {
                    while (v % i == 0) {
                        result.add(BigInteger.valueOf(i));
                        v /= i;
                    }
                }
                if (v > 1) {
                    result.add(BigInteger.valueOf(v));
                }
                return result;
            }
            long start = System.currentTimeMillis();
            int requests = 0;
            Set<BigInteger> divisors = new HashSet<>();
            while (requests < 90 && System.currentTimeMillis() < start + 4000) {
                BigInteger x = new BigInteger(n.bitLength() + 1, random);
                x = x.mod(n);
                if (x.equals(BigInteger.ZERO)) continue;
                BigInteger g = x.gcd(n);
                if (!g.equals(BigInteger.ONE)) {
                    divisors.add(g);
                    continue;
                }
                BigInteger y = x.multiply(x).mod(n);
                out.println("sqrt " + y);
                out.flush();
                ++requests;
                BigInteger z = new BigInteger(in.next()).mod(n);
                if (z.signum() < 0) z = z.add(n);
                if (z.equals(x) || z.add(x).equals(n)) continue;
                g = z.add(x).gcd(n);
                if (g.equals(BigInteger.ONE) || g.equals(n)) continue;//throw new RuntimeException();
                divisors.add(g);
            }
            {
                List<BigInteger> old = new ArrayList<>(divisors);
                for (BigInteger x : old) divisors.add(n.divide(x));
            }
            {
                List<BigInteger> have = new ArrayList<>(divisors);
                for (int i = 0; i < have.size(); ++i) {
                    for (int j = 0; j < i; ++j) {
                        BigInteger g = have.get(i).gcd(have.get(j));
                        if (!g.equals(BigInteger.ONE) && divisors.add(g)) {
                            have.add(g);
                        }
                    }
                }
                outer:
                for (BigInteger o : divisors) {
                    for (BigInteger g : divisors) {
                        if (o.compareTo(g) > 0 && o.mod(g).equals(BigInteger.ZERO)) continue outer;
                    }
                    result.add(o);
                }
            }
            return result;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

    }
}
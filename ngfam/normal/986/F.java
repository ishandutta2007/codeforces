import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ngfam
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        FOppaFuncanStyleRemastered solver = new FOppaFuncanStyleRemastered();
        solver.solve(1, in, out);
        out.close();
    }

    static class FOppaFuncanStyleRemastered {
        static int MAXN = 100005;
        static int maxprime = 32000000;

        public void solve(int testNumber, InputReader in, OutputWriter out) {

            int lp[] = new int[maxprime];
            ArrayList<Integer> primes = new ArrayList<>();

            for (int i = 2; i < maxprime; ++i) {
                if (lp[i] == 0) {
                    lp[i] = i;
                    primes.add(i);
                }
                for (int pr : primes) {
                    if (pr > lp[i] || pr * i >= maxprime) break;
                    lp[i * pr] = pr;
                }
            }

            int q = in.nextInt();

            Query queries[] = new Query[q];

            TreeSet<Long> unique = new TreeSet<Long>();

            for (int i = 0; i < q; ++i) {
                queries[i] = new Query();
                queries[i].n = in.nextLong();
                queries[i].k = in.nextLong();
                unique.add(queries[i].k);
            }

            long values[] = new long[unique.size()];

            int id = 0;
            for (long x : unique) {
                values[id++] = x;
            }

            int count[] = new int[values.length];
            long first_prime[] = new long[values.length];

            long f[][] = new long[values.length][MAXN];

            for (int i = 0; i < values.length; ++i) {
                long n = values[i];
                if (n == 1) {
                    count[i] = 1;
                    first_prime[i] = 1;
                    continue;
                }
                ArrayList<Long> factors = new ArrayList<>();
                for (int j : primes) {
                    if (n % j > 0) continue;
                    factors.add((long) j);
                    while (n % j == 0) n /= j;
                }
                if (n > 1) factors.add(n);
                count[i] = factors.size();

                first_prime[i] = factors.get(0);

                if (count[i] <= 2) continue;

                int done[] = new int[MAXN];
                TreeSet<Modular> myset = new TreeSet<Modular>(new ModularComp());

                Arrays.fill(f[i], Long.MAX_VALUE);
                f[i][0] = 0;
                myset.add(new Modular(0, 0));

                long small_prime = factors.get(0);

                while (myset.size() > 0) {
                    Modular cur = myset.first();
                    myset.remove(cur);

                    int modun = cur.modun;
                    long cost = cur.cost;

                    if (done[modun] > 0) continue;
                    done[modun] = 1;

                    for (long prime : factors) {
                        int newModun = (modun + (int) (prime % small_prime)) % ((int) small_prime);
                        long newCost = cost + prime;
                        if (f[i][newModun] > newCost) {
                            f[i][newModun] = newCost;
                            myset.add(new Modular(newModun, newCost));
                        }
                    }
                }
            }

            for (int i = 0; i < q; ++i) {
                long n = queries[i].n, k = queries[i].k;

                if (n == 1 || k == 1) {
                    out.println("NO");
                    continue;
                }

                int pos = Arrays.binarySearch(values, k);
                //   out.println(pos);
                if (count[pos] == 1) {
                    if (n % first_prime[pos] == 0) out.println("YES");
                    else out.println("NO");
                } else if (count[pos] == 2) {
                    long a = first_prime[pos];
                    long b = k / first_prime[pos];

                    if (n % gcd(a, b) > 0) {
                        out.println("NO");
                        continue;
                    }

                    long x = (n % a) * fpow(b % a, a - 2, a) % a;
                    if (x * b <= n) {
                        out.println("YES");
                    } else {
                        out.println("NO");
                    }
                } else {
                    int mod = (int) (n % first_prime[pos]);
                    if (f[pos][mod] <= n) out.println("YES");
                    else out.println("NO");
                }
            }
        }

        public long fpow(long x, long y, long mod) {
            long answer = 1;
            while (y > 0) {
                if (y % 2 == 1) answer = (answer * x) % mod;
                y = y / 2;
                x = (x * x) % mod;
            }
            return answer;
        }

        public long gcd(long a, long b) {
            return (b == 0 ? a : gcd(b, a % b));
        }

        class Query {
            long n;
            long k;

            Query() {
            }

        }

        class Modular implements Comparable<Modular> {
            long cost;
            int modun;

            Modular(int _modun, long _cost) {
                modun = _modun;
                cost = _cost;
            }

            public int compareTo(Modular rhs) {
                if (cost < rhs.cost) return -1;
                if (cost > rhs.cost) return 1;
                if (modun < rhs.modun) return -1;
                if (modun > rhs.modun) return 1;
                return 0;
            }

        }

        class ModularComp implements Comparator<Modular> {
            public int compare(Modular lhs, Modular rhs) {
                return lhs.compareTo(rhs);
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}
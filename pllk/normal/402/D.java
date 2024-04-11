import java.io.*;
import java.math.*;
import java.util.*;
import java.util.concurrent.ArrayBlockingQueue;


public class Main {

    InputReader in;
    PrintWriter out;

    void run(){
        /*try {
            out = new PrintWriter(new FileOutputStream("output.txt"));
            in = new InputReader(new FileInputStream("input.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }*/
        out = new PrintWriter(new OutputStreamWriter(System.out));
        in = new InputReader(System.in);
        solve();
        out.flush();
    }

    public static void main(String[] args){
        new Main().run();
    }
    

    HashSet<Integer> b;
    ArrayList<Integer> primes;
    boolean[] isPrime;
    
    public void SieveEratosthenes(int max) {
        isPrime = new boolean[max+1];
        primes = new ArrayList<Integer>();
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        int idx = (int)Math.sqrt((double)max);
        for(int i = 2; i <= idx; i++) {
            if(isPrime[i]) {
                for(int j = 2*i; j <= max; j += i) {
                    isPrime[j] = false;
                }
                primes.add(i);
            }
        }
        for(int i = idx; i <= max; i++)
            if(isPrime[i])
                primes.add(i);
    }
    
    int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        return gcd(b, a%b);
    }
    
    void solve() {
        int n = in.ni();
        int m = in.ni();
        int[] a = new int[n];
        b = new HashSet<Integer>(m);
        for(int i = 0; i < n; i++)
            a[i] = in.ni();
        for(int i = 0; i < m; i++)
            b.add(in.ni());
        SieveEratosthenes((int)Math.sqrt(1e9+6));
        int[] g = new int[n];
        g[0] = a[0];
        for(int i = 1; i < n; i++)
            g[i] = gcd(g[i-1], a[i]);
        int div = 1;
        for(int i = n-1; i >= 0; i--) {
            g[i] /= div;
            a[i] /= div;
            if(g[i] == 1)
                continue;
            int gain = factorize(g[i]);
            if(gain < 0) {
                div *= g[i];
                a[i] /= g[i];
            }
        }
        int total = 0;
        for(int i = 0; i < n; i++)
            total += factorize(a[i]);
        out.println(total);
    }
    
    int factorize(int v) {
        int penalty = 0;
        for(int p : primes) {
            if (p*p > v) break;
            int cnt = 0;
            while(v % p == 0) {
                v /= p;
                cnt++;
            }
            penalty += (b.contains(p) ? -cnt : cnt);
        }
        if(v > 1)
            penalty += (b.contains(v) ? -1 : 1);
        return penalty;
    }
    
    class InputReader {
        private boolean finished = false;
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int peek() {
            if (numChars == -1)
                return -1;
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar];
        }

        public int ni() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nl() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String ns() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return isWhitespace(c);
        }

        public boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String readLine0() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r')
                    buf.appendCodePoint(c);
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = readLine0();
            while (s.trim().length() == 0)
                s = readLine0();
            return s;
        }

        public String readLine(boolean ignoreEmptyLines) {
            if (ignoreEmptyLines)
                return readLine();
            else
                return readLine0();
        }

        public BigInteger readBigInteger() {
            try {
                return new BigInteger(ns());
            } catch (NumberFormatException e) {
                throw new InputMismatchException();
            }
        }

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, ni());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, ni());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public boolean eof() {
            int value;
            while (isSpaceChar(value = peek()) && value != -1)
                read();
            return value == -1;
        }

        public String next() {
            return ns();
        }

        public SpaceCharFilter getFilter() {
            return filter;
        }

        public void setFilter(SpaceCharFilter filter) {
            this.filter = filter;
        }
    }
    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }

}
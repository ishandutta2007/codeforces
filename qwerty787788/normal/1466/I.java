import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class IOK {
    FastScanner in;
    PrintWriter out;

    String toString(BigInteger x, int maxBits) {
        char[] res = new char[maxBits];
        String ok = x.toString(2);
        Arrays.fill(res, '0');
        int moreZeros = (res.length - ok.length());
        if (moreZeros < 0) {
            throw new AssertionError();
        }
        for (int i = 0; i < ok.length(); i++) {
            res[i + moreZeros] = ok.charAt(i);
        }
        return new String(res);
    }

    void solve() {
        int n = in.nextInt();
        int maxBits = in.nextInt();
        BigInteger upperBound = BigInteger.ONE.shiftLeft(maxBits);
        Number[] numbers = new Number[n];
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = new Number(i, upperBound);
        }
        BigInteger lowerBound = BigInteger.ZERO;
        int numQueries = 0;
        while (true) {
            Arrays.sort(numbers);
            numbers = updateNumbers(numbers, lowerBound);
            if (numbers.length == 0) {
                break;
            }
            Number toAsk = numbers[numbers.length - 1];
            if (toAsk.upperBound.compareTo(lowerBound) == 0) {
                break;
            }
            numQueries++;
            Number first = numbers[0];
            BigInteger dist = first.upperBound.subtract(lowerBound).add(BigInteger.ONE);
            if (dist.compareTo(BigInteger.ONE) <= 0) {
                throw new AssertionError();
            }
            dist = dist.shiftRight(1);
            BigInteger y = lowerBound.add(dist).subtract(BigInteger.ONE);
            if (isBigger(toAsk.id, y, maxBits)) {
                lowerBound = y.add(BigInteger.ONE);

                if (upperBound.compareTo(first.upperBound) != 0) {
                    y = first.upperBound;
                    if (isBigger(toAsk.id, y, maxBits)) {
                        lowerBound = y.add(BigInteger.ONE);
                    } else {
                        toAsk.upperBound = y;
                    }
                }
            } else {
                toAsk.upperBound = y;
            }
        }
//        System.err.println("num queries = " + numQueries);
        answerIs(lowerBound, maxBits);
    }

    void answerIs(BigInteger res, int maxBits) {
        out.println("0 " + toString(res, maxBits));
        out.flush();
    }

    Number[] updateNumbers(Number[] numbers, BigInteger lowerBound) {
        int first = 0;
        while (first != numbers.length && numbers[first].upperBound.compareTo(lowerBound) <= 0) {
            first++;
        }
        Number[] res = new Number[numbers.length - first];
        for (int i = 0; i < res.length; i++) {
            res[i] = numbers[i + first];
        }
        return res;
    }

    boolean isBigger(int id, BigInteger y, int maxBits) {
        out.println((id + 1) + " " + toString(y, maxBits));
        out.flush();
        return in.next().equals("yes");
    }

    class Number implements Comparable<Number> {
        int id;
        BigInteger upperBound;

        public Number(int id, BigInteger upperBound) {
            this.id = id;
            this.upperBound = upperBound;
        }

        @Override
        public int compareTo(Number o) {
            return upperBound.compareTo(o.upperBound);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("I.in"));
            out = new PrintWriter(new File("I.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new IOK().runIO();
    }
}
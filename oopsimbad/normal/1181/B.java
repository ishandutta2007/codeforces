import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;

public class template {
    public static void main(String[] args) throws Exception {
        new template().run();
    }

    public void run() throws Exception {
        FastScanner f = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = f.nextInt();
        String s = f.next();
        int i = n / 2;
        while (i < s.length() && s.charAt(i) == '0')
            i++;
        BigInteger b1 = i == s.length() ? new BigInteger("-1")
                : new BigInteger(s.substring(0, i)).add(new BigInteger(s.substring(i)));
        i = (n + 1) / 2;
        while (i >= 0 && s.charAt(i) == '0')
            i--;
        BigInteger b2 = i == s.length() ? new BigInteger("-1")
                : new BigInteger(s.substring(0, i)).add(new BigInteger(s.substring(i)));
        if (b1.compareTo(BigInteger.ZERO) < 0)
            out.println(b2);
        else if (b2.compareTo(BigInteger.ZERO) < 0)
            out.println(b1);
        else if (b1.compareTo(b2) < 0)
            out.println(b1);
        else
            out.println(b2);
        ///
        out.flush();
    }

    ///
    static class FastScanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
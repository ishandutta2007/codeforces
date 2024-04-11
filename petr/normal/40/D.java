import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class People {
    class Possibility implements Comparable<Possibility> {
        long cur;
        long prev;

        Possibility(long cur, long prev) {
            this.cur = cur;
            this.prev = prev;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Possibility that = (Possibility) o;

            if (cur != that.cur) return false;
            if (prev != that.prev) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = (int) (cur ^ (cur >>> 32));
            result = 31 * result + (int) (prev ^ (prev >>> 32));
            return result;
        }

        @Override
        public String toString() {
            return "Possibility{" +
                    "cur=" + Long.toString(cur, 12) +
                    ", prev=" + Long.toString(prev, 12) +
                    ", delta = " + Long.toString(cur - prev, 12) +
                    '}';
        }

        public int compareTo(Possibility other) {
            if (prev < other.prev) {
                return -1;
            } else if (prev > other.prev) {
                return 1;
            } else if (cur < other.cur) {
                    return -1;
                } else if (cur > other.cur) {
                    return 1;
            } else return 0;
        }
    }

    private void solve() {
        /*Set<Possibility> cur = new TreeSet<Possibility>();
        cur.add(new Possibility(13, 2));
        writer.println(cur);
        for (int i = 0; i < 10; ++i) {
            Set<Possibility> next = new TreeSet<Possibility>();
            for (Possibility old : cur) {
                next.add(new Possibility(old.prev * 12, old.cur));
                next.add(new Possibility(old.cur * 13 - old.prev * 12, old.cur));
            }
            cur = next;
            writer.println(cur);
        }*/
        //writer.println(BigInteger.valueOf(12).pow(200).multiply(BigInteger.valueOf(2)));

        String got = new BigInteger(nextToken()).toString(12);
        int total = 0;
        int posSum = 0;
        for (int i = 0; i < got.length(); ++i) {
            int digit = got.charAt(got.length() - 1 - i) - '0';
            for (int j = 0; j < digit; ++j) {
                ++total;
                if (total >= 3) break;
                posSum += i;
            }
            if (total >= 3) break;
        }
        if (total != 2) {
            writer.println("NO");
            return;
        }
        writer.println("YES");
        writer.println(1);
        writer.println(posSum + 1);
        List<String> others = new ArrayList<String>();
        for (int i = 0; i <= posSum - i; ++i) {
            StringBuilder cur = new StringBuilder();
            for (int j = 0; j <= posSum - i; ++j) {
                int t = 0;
                if (posSum - i - j == i)
                    ++t;
                if (posSum - i - j == posSum - i)
                    ++t;
                cur.append((char) ('0' + t));
            }
            String line = cur.toString();
            if (!line.equals(got)) {
                others.add(new BigInteger(line, 12).toString());
            }
        }
        Collections.reverse(others);
        writer.println(others.size());
        for (String x : others) {
            writer.println(x);
        }
    }


    public static void main(String[] args) {
        new People().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    private void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
            tokenizer = null;
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private String nextToken() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    private int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() {
        return Double.parseDouble(nextToken());
    }
}
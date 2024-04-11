import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Parens implements Runnable {
    long INF = 1000000000000L;

    static class Possibility implements Comparable<Possibility> {
        long cost;
        int at;

        Possibility(long cost, int at) {
            this.cost = cost;
            this.at = at;
        }

        public int compareTo(Possibility possibility) {
            if (cost < possibility.cost)
                return -1;
            else if (cost > possibility.cost)
                return 1;
            else if (at < possibility.at)
                return -1;
            else if (at > possibility.at)
                return 1;
            else
                return 0;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Possibility that = (Possibility) o;

            if (at != that.at) return false;
            if (cost != that.cost) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = (int) (cost ^ (cost >>> 32));
            result = 31 * result + at;
            return result;
        }
    }

    private void solve() throws IOException {
        String s = nextToken();
        long[] costChange = new long[s.length()];
        long haveCost = 0;
        char[] seq = new char[s.length()];
        int n = s.length();
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch == '?') {
                long a = nextLong();
                long b = nextLong();
                if (a < b) {
                    seq[i] = '(';
                    costChange[i] = b - a;
                    haveCost += a;
                } else {
                    seq[i] = ')';
                    costChange[i] = a - b;
                    haveCost += b;
                }
            } else if (ch == '(') {
                seq[i] = '(';
                costChange[i] = INF;
            } else {
                seq[i] = ')';
                costChange[i] = INF;
            }
        }

        int balance = 0;
        TreeSet<Possibility> poss = new TreeSet<Possibility>();
        for (int i = 0; i < n; ++i) {
            if (seq[i] == ')') {
                poss.add(new Possibility(costChange[i], i));
                --balance;
            } else {
                ++balance;
            }
            if (balance < 0) {
                Possibility use = poss.first();
                poss.remove(use);
                haveCost += costChange[use.at];
                seq[use.at] = '(';
                balance += 2;
            }
        }
        poss.clear();
        balance = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (seq[i] == '(') {
                poss.add(new Possibility(costChange[i], i));
                --balance;
            } else {
                ++balance;
            }
            if (balance < 0) {
                Possibility use = poss.first();
                poss.remove(use);
                haveCost += costChange[use.at];
                seq[use.at] = ')';
                balance += 2;
            }
        }
        if (balance != 0)
            throw new RuntimeException();
        if (haveCost >= INF)
            writer.println(-1);
        else {
            writer.println(haveCost);
            for (int i = 0; i < n; ++i)
                writer.print(seq[i]);
            writer.println();
        }
    }


    public static void main(String[] args) {
        new Parens().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
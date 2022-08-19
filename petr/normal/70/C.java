import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Lucky implements Runnable {
    static class Fraction {
        int p;
        int q;

        Fraction(int p, int q) {
            int g = gcd(p, q);
            this.p = p / g;
            this.q = q / g;
        }

        private int gcd(int p, int q) {
            while (q > 0) {
                int t = p % q;
                p = q;
                q = t;
            }
            return p;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Fraction fraction = (Fraction) o;

            if (p != fraction.p) return false;
            if (q != fraction.q) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = p;
            result = 31 * result + q;
            return result;
        }
    }

    private void solve() throws IOException {
        int maxX = nextInt();
        int maxY = nextInt();
        long W = nextInt();
        long res = Long.MAX_VALUE / 2;
        int resX = -1;
        int resY = -1;
        Fraction[] xf = new Fraction[maxX + 1];
        for (int x = 1; x <= maxX; ++x) {
            xf[x] = new Fraction(x, rev(x));
        }
        Fraction[] yf = new Fraction[maxY + 1];
        for (int y = 1; y <= maxY; ++y) {
            yf[y] = new Fraction(rev(y), y);
        }
        HashMap<Fraction, Integer> xCount = new HashMap<Fraction, Integer>();
        HashMap<Fraction, Integer> yCount = new HashMap<Fraction, Integer>();
        for (int x = 1; x <= maxX; ++x) {
            Fraction f = xf[x];
            if (xCount.containsKey(f))
                xCount.put(f, xCount.get(f) + 1);
            else
                xCount.put(f, 1);
        }

        int y = 0;
        long curW = 0;
        for (int x = maxX; x >= 1; --x) {
            while (curW < W && y < maxY) {
                ++y;
                Fraction f = yf[y];
                if (yCount.containsKey(f))
                    yCount.put(f, yCount.get(f) + 1);
                else
                    yCount.put(f, 1);
                if (xCount.containsKey(f))
                    curW += xCount.get(f);
            }
            if (curW < W) break;
            if (x * (long) y < res) {
                res = x * (long) y;
                resX = x;
                resY = y;
            }
            {
                Fraction f = xf[x];
                if (yCount.containsKey(f))
                    curW -= yCount.get(f);
                xCount.put(f, xCount.get(f) - 1);
            }
        }
        writer.print(resX);
        if (resX >= 0) {
            writer.println(" " + resY);
        } else {
            writer.println();
        }
    }

    private int rev(int x) {
        int p10 = 1;
        while (p10 <= x)
            p10 *= 10;
        int y = 0;
        while (x > 0) {
            p10 /= 10;
            y += p10 * (x % 10);
            x /= 10;
        }
        return y;
    }

    public static void main(String[] args) {
        new Lucky().run();
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
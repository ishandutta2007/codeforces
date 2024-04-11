import java.beans.beancontext.BeanContextMembershipEvent;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Chocolate implements Runnable {
    static class Rect {
        long x1;
        long y1;
        long x2;
        long y2;

        Rect(long x1, long y1, long x2, long y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        public long size() {
            if (x1 > x2)
                return 0;
            if (y1 > y2)
                return 0;
            return (x2 - x1 + 1) * (y2 - y1 + 1);
        }

        public Rect intersection(Rect o) {
            return new Rect(Math.max(x1, o.x1), Math.max(y1, o.y1), Math.min(x2, o.x2), Math.min(y2, o.y2));
        }
    }

    private void solve() throws IOException {
        int nt = nextInt();
        for (int it = 0; it < nt; ++it) {
            long maxx = nextInt();
            long maxy = nextInt();
            long x1 = nextInt();
            long y1 = nextInt();
            long x2 = nextInt();
            long y2 = nextInt();
            Rect first = new Rect(Math.max(1, x1 - x2 + 1), Math.max(1, y1 - y2 + 1), maxx - Math.max(0, x2 - x1), maxy - Math.max(0, y2 - y1));
            Rect second = new Rect(Math.max(1, x2 - x1 + 1), Math.max(1, y2 - y1 + 1), maxx - Math.max(0, x1 - x2), maxy - Math.max(0, y1 - y2));
            writer.println(maxx * maxy - first.size() - second.size() + first.intersection(second).size());
        }
        
    }

    public static void main(String[] args) {
        new Chocolate().run();
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Emperor implements Runnable {
    static class Side implements Comparable<Side> {
        int dx;
        int dy;
        double alpha;
        Side next;

        public int compareTo(Side side) {
            return Double.compare(alpha, side.alpha);
        }

        public void getAlpha() {
            alpha = Math.atan2(dy, dx);
        }
    }

    static final int MAX = 500;
    static final int MAGIC = 7;
    List<Side> res;
    int tdx;
    int tdy;

    private void solve() throws IOException {
        int n = nextInt();
        Side[] first = new Side[MAX * MAX + 1];
        for (int dx = -MAX; dx <= MAX; ++dx)
            for (int dy = -MAX; dy <= MAX; ++dy) {
                int z = dx * dx + dy * dy;
                if (z <= MAX * MAX) {
                    Side s = new Side();
                    s.dx = dx;
                    s.dy = dy;
                    s.next = first[z];
                    first[z] = s;
                }
            }
        int total = 0;
        List<Side> firsts = new ArrayList<Side>();
        for (int len = 1;; ++len) {
            if (first[len] == null)
                continue;
            ++total;
            firsts.add(first[len]);
            if (total < n)
                continue;
            if (doit(firsts, n)) {
                System.err.println(n + " " + total);
                break;
            }
        }
        for (Side s : res)
            s.getAlpha();
        Collections.sort(res);
        int x = 0;
        int y = 0;
        writer.println("YES");
        for (Side s : res) {
            writer.println(x + " " + y);
            x += s.dx;
            y += s.dy;
        }
    }

    private boolean doit(List<Side> firsts, int n) {
        res = new ArrayList<Side>();
        tdx = 0;
        tdy = 0;
        return rec(firsts, n, firsts.size() - 1);
    }

    private boolean rec(List<Side> firsts, int toMake, int at) {
        if (toMake == 0) {
            return (tdx == 0 && tdy == 0);
        }
        if (at < 0) {
            throw new RuntimeException();
        }
        if (at >= MAGIC) {
            Side best = firsts.get(at);
            int bdist = (tdx + best.dx) * (tdx + best.dx) + (tdy + best.dy) * (tdy + best.dy);
            Side cur = best.next;
            while (cur != null) {
                int cdist = (tdx + cur.dx) * (tdx + cur.dx) + (tdy + cur.dy) * (tdy + cur.dy);
                if (cdist < bdist) {
                    bdist = cdist;
                    best = cur;
                }
                cur = cur.next;
            }
            res.add(best);
            tdx += best.dx;
            tdy += best.dy;
            if (rec(firsts, toMake - 1, at - 1))
                return true;
            res.remove(res.size() - 1);
            tdx -= best.dx;
            tdy -= best.dy;
        } else {
            Side best = firsts.get(at);
            while (best != null) {
                res.add(best);
                tdx += best.dx;
                tdy += best.dy;
                if (rec(firsts, toMake - 1, at - 1))
                    return true;
                res.remove(res.size() - 1);
                tdx -= best.dx;
                tdy -= best.dy;
                best = best.next;
            }
            if (at >= toMake)
                if (rec(firsts, toMake, at - 1))
                    return true;
        }
        return false;
    }

    public static void main(String[] args) {
        new Emperor().run();
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
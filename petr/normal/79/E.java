import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.regex.Matcher;

public class SafetySystem implements Runnable {

    int[] a;
    int[] b;
    int x;
    int y;
    long[] s;
    long[] t;
    long[] t2;
    int n;

    private void solve() throws IOException {
        n = nextInt();
        long t = nextLong();
        a = new int[2];
        b = new int[2];
        a[0] = nextInt();
        b[0] = nextInt();
        int c = nextInt();
        a[1] = a[0] + c - 1;
        b[1] = b[0] + c - 1;
        s = new long[4];
        this.t = new long[4];
        this.t2 = new long[4];
        Arrays.fill(s, t);
        x = 1;
        y = 1;
        if (!valid()) {
            writer.println("Impossible");
            return;
        }
        while (x < n || y < n) {
            if (x < n) {
                ++x;
                add(-1);
                if (valid()) {
                    writer.print("R");
                    continue;
                }
                add(1);
                --x;
            }
            ++y;
            add(-1);
            writer.print("U");
        }
        if (!valid()) throw new RuntimeException();
        writer.println();
    }

    private boolean valid() {
        int sx = x;
        int sy = y;
        Arrays.fill(t, 0);
        if (x < a[0]) {
            addline(1, 0, a[0] - x);
        }
        if (y < b[0]) {
            addline(0, 1, b[0] - y);
        }
        if (x < a[1]) {
            addline(1, 0, a[1] - x);
        }
        if (y < b[1]) {
            addline(0, 1, b[1] - y);
        }
        if (x < n) {
            addline(1, 0, n - x);
        }
        if (y < n) {
            addline(0, 1, n - y);
        }
        System.arraycopy(t, 0, t2, 0, 4);
        Arrays.fill(t, 0);
        x = sx;
        y = sy;
        if (x < a[0]) {
            addline(1, 0, a[0] - x);
        }
        if (y < b[0]) {
            addline(0, 1, b[0] - y);
        }
        if (y < b[1]) {
            addline(0, 1, b[1] - y);
        }
        if (x < a[1]) {
            addline(1, 0, a[1] - x);
        }
        if (x < n) {
            addline(1, 0, n - x);
        }
        if (y < n) {
            addline(0, 1, n - y);
        }
        x = sx;
        y = sy;
        if (s[0] < t[0]) return false;
        if (s[3] < t[3]) return false;
        long ns1 = Math.min(s[1], Math.max(t[1], t2[1])) - Math.min(t[1], t2[1]);
        long ns2 = Math.min(s[2], Math.max(t[2], t2[2])) - Math.min(t[2], t2[2]);
        if (ns1 % 2 != 0) --ns1;
        if (ns2 % 2 != 0) --ns2;
        if (ns1 < 0 || ns2 < 0 || ns1 + ns2 < Math.max(t[1], t2[1]) - Math.min(t[1], t2[1])) return false;
        return true;
    }

    private void addline(int dx, int dy, int count) {
        int nx = x + count * dx;
        int ny = y + count * dy;
        int mx = x + dx;
        int my = y + dy;
        for (int ai = 0; ai < 2; ++ai)
            for (int bi = 0; bi < 2; ++bi) {
                int ma = 1;
                if (mx + nx >= a[ai] * 2) ma = -1;
                int mb = 1;
                if (my + ny >= b[bi] * 2) mb = -1;
                t[ai * 2 + bi] += (long) ma * ((long) count * a[ai] - (long) (nx + mx) * count / 2) + (long) mb * ((long) count * b[bi] - (long) (ny + my) * count / 2);
            }
        x = nx;
        y = ny;
    }

    private void add(int koef) {
        for (int ai = 0; ai < 2; ++ai)
            for (int bi = 0; bi < 2; ++bi) {
                s[ai * 2 + bi] += koef * (Math.abs(a[ai] - x) + Math.abs(b[bi] - y));
            }
    }

    public static void main(String[] args) {
        new SafetySystem().run();
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
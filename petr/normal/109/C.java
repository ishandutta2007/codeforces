import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class HappyTree implements Runnable {
    int[] dest;
    int[] next;
    boolean[] lucky;
    int[] first;
    int[] componentId;

    private void solve() throws IOException {
        int n = nextInt();
        dest = new int[2 * (n - 1)];
        next = new int[2 * (n - 1)];
        lucky = new boolean[2 * (n - 1)];
        first = new int[n];
        Arrays.fill(first, -1);
        for (int i = 0; i < n - 1; ++i) {
            int a = nextInt() - 1;
            int b = nextInt() - 1;
            boolean c = isLucky(nextInt());
            dest[2 * i] = b;
            next[2 * i] = first[a];
            lucky[2 * i] = c;
            first[a] = 2 * i;
            dest[2 * i + 1] = a;
            next[2 * i + 1] = first[b];
            lucky[2 * i + 1] = c;
            first[b] = 2 * i + 1;
        }
        componentId = new int[n];
        Arrays.fill(componentId, -1);
        int lastComponent = 0;
        for (int i = 0; i < n; ++i)
            if (componentId[i] < 0)
                doit(i, lastComponent++);
        int[] componentSize = new int[lastComponent];
        for (int i = 0; i < n; ++i)
            ++componentSize[componentId[i]];
        long res = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = n - componentSize[componentId[i]];
            res += cnt * (long) (cnt - 1);
        }
        System.out.println(res);
    }

    void doit(int root, int component) {
        if (componentId[root] >= 0) {
            if (componentId[root] != component)
                throw new RuntimeException();
            return;
        }
        componentId[root] = component;
        int cur = first[root];
        while (cur >= 0) {
            if (!lucky[cur])
                doit(dest[cur], component);
            cur = next[cur];
        }
    }

    private boolean isLucky(long x) {
        while (x > 0) {
            long dig = x % 10;
            x /= 10;
            if (dig == 4 || dig == 7) continue;
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        new HappyTree().run();
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
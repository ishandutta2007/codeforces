import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Monks implements Runnable {
    int[] d;
    int[][] stacks;
    int[] sp;
    int[] frozen;
    List<String> moves = new ArrayList<String>();

    private void solve() throws IOException {
        int n = nextInt();
        d = new int[n];
        for (int i = 0; i < n; ++i) {
            d[i] = nextInt();
        }
        stacks = new int[3][n];
        sp = new int[3];
        for (int i = 0; i < n; ++i) {
            stacks[0][i] = i;
        }
        sp[0] = n;
        frozen = new int[3];
        moves = new ArrayList<String>();
        doit(0, 2, false);
        if (sp[2] != n) throw new RuntimeException();
        for (int i = 0; i < n; ++i)
            if (stacks[2][i] != i) throw new RuntimeException();
        writer.println(moves.size());
        for (String x : moves) writer.println(x);
    }

    private void doit(int src, int dst, boolean mayReverse) {
        if (frozen[src] == sp[src])
            return;
        int what = d[stacks[src][frozen[src]]];
        int cnt = 0;
        while (frozen[src] < sp[src] && d[stacks[src][frozen[src]]] == what) {
            ++cnt;
            ++frozen[src];
        }
        if (cnt == 1 || mayReverse) {
            doit(src, 3 - src - dst, true);
            frozen[src] -= cnt;
            for (int i = 0; i < cnt; ++i)
                moveIt(src, dst);
            frozen[dst] += cnt;
            doit(3 - src - dst, dst, true);
            frozen[dst] -= cnt;
        } else if (frozen[src] == sp[src]) {
            frozen[src] -= cnt;
            for (int i = 0; i < cnt - 1; ++i)
                moveIt(src, 3 - src - dst);
            moveIt(src, dst);
            for (int i = 0; i < cnt - 1; ++i)
                moveIt(3 - src - dst, dst);
        } else {
            doit(src, dst, true);
            frozen[src] -= cnt;
            for (int i = 0; i < cnt; ++i)
                moveIt(src, 3 - src - dst);
            frozen[3 - src - dst] += cnt;
            doit(dst, src, true);
            frozen[3 - src - dst] -= cnt;
            for (int i = 0; i < cnt; ++i)
                moveIt(3 - src - dst, dst);
            frozen[dst] += cnt;
            doit(src, dst, false);
            frozen[dst] -= cnt;
        }
    }

    private void moveIt(int src, int dst) {
        if (frozen[src] >= sp[src]) throw new RuntimeException();
        stacks[dst][sp[dst]++] = stacks[src][--sp[src]];
        moves.add((src + 1) + " " + (dst + 1));
    }

    public static void main(String[] args) {
        new Monks().run();
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Pipes implements Runnable {
    static final int MODULO = 1000003;

    private void solve() throws IOException {
        int height = nextInt();
        int width = nextInt();
        String[] field = new String[height];
        for (int i = 0; i < height; ++i) field[i] = nextToken();
        int res = 1;
        for (int r = 0; r < height; ++r) {
            boolean[] bad = new boolean[2];
            for (int c = 0; c < width; ++c) {
                char what = field[r].charAt(c);
                if (what == '.') continue;
                boolean normal = (what == '1' || what == '2');
                bad[c & 1] |= normal;
                bad[(c & 1) ^ 1] |= !normal;
            }
            int cnt = 0;
            if (!bad[0]) ++cnt;
            if (!bad[1]) ++cnt;
            res = res * cnt % MODULO;
        }
        for (int c = 0; c < width; ++c) {
            boolean[] bad = new boolean[2];
            for (int r = 0; r < height; ++r) {
                char what = field[r].charAt(c);
                if (what == '.') continue;
                boolean normal = (what == '1' || what == '4');
                bad[r & 1] |= normal;
                bad[(r & 1) ^ 1] |= !normal;
            }
            int cnt = 0;
            if (!bad[0]) ++cnt;
            if (!bad[1]) ++cnt;
            res = res * cnt % MODULO;
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new Pipes().run();
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
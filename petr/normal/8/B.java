import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Robot implements Runnable {
    private void solve() throws IOException {
        String s = nextToken();
        Map<Integer, Integer> seen = new HashMap<Integer, Integer>();
        int x = 200;
        int y = 200;
        seen.put(x * 3137 + y, 0);
        boolean ok = true;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            switch (ch) {
                case 'L':
                    --x;
                    break;
                case 'R':
                    ++x;
                    break;
                case 'U':
                    --y;
                    break;
                case 'D':
                    ++y;
                    break;
            }
            if (seen.containsKey(x * 3137 + y))
                ok = false;
            seen.put(x * 3137 + y, i + 1);
        }
        for (Map.Entry<Integer, Integer> p : seen.entrySet()) {
            int sx = p.getKey() / 3137;
            int sy = p.getKey() % 3137;
            for (int nx = -1; nx <= 1; ++nx)
                for (int ny = -1; ny <= 1; ++ny)
                    if (nx == 0 ^ ny == 0) {
                        int np = (sx + nx) * 3137 + (sy + ny);
                        if (seen.containsKey(np) && seen.get(np) > p.getValue() + 1)
                            ok = false;
                    }

        }
        if (ok)
            writer.println("OK");
        else
            writer.println("BUG");
    }


    public static void main(String[] args) {
        new Robot().run();
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
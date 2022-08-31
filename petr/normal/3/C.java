import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class XO implements Runnable {
    Map<String, String> ans = new HashMap<String, String>();
    String ILLEGAL = "illegal";
    String FIRST = "first";
    String SECOND = "second";
    String FIRSTWON = "the first player won";
    String SECONDWON = "the second player won";
    String DRAW = "draw";

    private void solve() throws IOException {
        build();
        String s = "";
        for (int i = 0; i < 3; ++i) {
            s += nextToken();
        }
        if (ans.containsKey(s)) {
            writer.println(ans.get(s));
        } else {
            writer.println(ILLEGAL);
        }
    }

    private void build() {
        buildAll(".........", true);
    }

    private void buildAll(String pos, boolean first) {
        if (ans.containsKey(pos))
            return;
        String over = getOverMessage(pos);
        if (over != null) {
            ans.put(pos, over);
        } else {
            if (first) {
                ans.put(pos, FIRST);
                for (int i = 0; i < 9; ++i)
                    if (pos.charAt(i) == '.') {
                        buildAll(pos.substring(0, i) + 'X' + pos.substring(i + 1), !first);
                    }
            } else {
                ans.put(pos, SECOND);
                for (int i = 0; i < 9; ++i)
                    if (pos.charAt(i) == '.') {
                        buildAll(pos.substring(0, i) + '0' + pos.substring(i + 1), !first);
                    }
            }
        }
    }

    private String getOverMessage(String pos) {
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c)
                for (int dr = -1; dr <= 1; ++dr)
                    for (int dc = -1; dc <= 1; ++dc) {
                        if (r + 2 * dr >= 0 && r + 2 * dr < 3 && c + 2 * dc >= 0 && c + 2 * dc < 3 && (dr != 0 || dc != 0)) {
                            if (pos.charAt(r * 3 + c) == pos.charAt(r * 3 + dr * 3 + c + dc) &&
                                pos.charAt(r * 3 + c) == pos.charAt(r * 3 + 2 * dr * 3 + c + 2 * dc)) {
                                char ch = pos.charAt(r * 3 + c);
                                if (ch == 'X')
                                    return FIRSTWON;
                                else if (ch == '0')
                                    return SECONDWON;
                            }
                        }
                    }
        if (pos.indexOf('.') < 0)
            return DRAW;
        return null;
    }


    public static void main(String[] args) {
        new XO().run();
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
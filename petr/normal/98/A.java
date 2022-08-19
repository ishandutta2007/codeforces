import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Cube implements Runnable {
    Set<String> seen;

    private void solve() throws IOException {
        String s = nextToken();
        seen = new HashSet<String>();
        rec(s, 0, new StringBuilder(), new boolean[6]);
        writer.println(seen.size());
    }

    private void rec(String s, int at, StringBuilder got, boolean[] used) {
        if (at >= 6) {
            seen.add(genSmallestRotation(got.toString()));
            return;
        }
        for (int i = 0; i < 6; ++i) if (!used[i]) {
            used[i] = true;
            got.append(s.charAt(i));
            rec(s, at + 1, got, used);
            got.deleteCharAt(got.length() - 1);
            used[i] = false;
        }
    }

    String rotFront(String source) {
        StringBuilder res = new StringBuilder();
        res.append(source.charAt(3));
        res.append(source.charAt(0));
        res.append(source.charAt(1));
        res.append(source.charAt(2));
        res.append(source.charAt(4));
        res.append(source.charAt(5));
        return res.toString();
    }

    String rotRight(String source) {
        StringBuilder res = new StringBuilder();
        res.append(source.charAt(0));
        res.append(source.charAt(5));
        res.append(source.charAt(2));
        res.append(source.charAt(4));
        res.append(source.charAt(1));
        res.append(source.charAt(3));
        return res.toString();
    }

    String genSmallestRotation(String source) {
        String res = tryFour(source);
        for (int i = 0; i < 4; ++i) {
            source = rotFront(source);
            res = getMin(res, tryFour(source));
        }
        source = rotRight(source);
        for (int i = 0; i < 4; ++i) {
            source = rotFront(source);
            res = getMin(res, tryFour(source));
        }
        return res;
    }

    private String getMin(String a, String b) {
        if (a.compareTo(b) < 0)
            return a;
        else
            return b;
    }

    private String tryFour(String source) {
        String res = source;
        for (int i = 0; i < 4; ++i) {
            source = rotRight(source);
            res = getMin(res, source);
        }
        return res;
    }

    public static void main(String[] args) {
        new Cube().run();
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
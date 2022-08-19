import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Train implements Runnable {
    private void solve() throws IOException {
        String s = nextToken();
        String a = nextToken();
        String b = nextToken();
        int p1 = find(s, a);
        if (p1 >= 0) {
            p1 = find(s.substring(p1 + a.length()), b);
        }
        boolean forward = false;
        if (p1 >= 0) {
            forward = true;
        }
        s = new StringBuilder(s).reverse().toString();
        p1 = find(s, a);
        if (p1 >= 0) {
            p1 = find(s.substring(p1 + a.length()), b);
        }
        boolean backward = false;
        if (p1 >= 0) {
            backward = true;
        }
        if (forward)
            if (backward)
                writer.println("both");
        else
                writer.println("forward");
        else
            if (backward)
                writer.println("backward");
        else
                writer.println("fantasy");
    }

    private int find(String s, String a) {
        long h = 0;
        long pw = 1;
        for (int i = 0; i < a.length(); ++i) {
            h = h * 3137 + a.charAt(i);
            pw = pw * 3137;
        }
        long hh = 0;
        for (int i = 0; i < s.length(); ++i) {
            hh = hh * 3137 + s.charAt(i);
            if (i >= a.length()) {
                hh = hh - pw * s.charAt(i - a.length());
            }
            if (i + 1 >= a.length()) {
                if (hh == h) {
                    return i - a.length() + 1;
                }
            }
        }
        return -1;
    }


    public static void main(String[] args) {
        new Train().run();
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
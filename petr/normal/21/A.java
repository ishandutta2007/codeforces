import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

public class Jabber implements Runnable {
    private void solve() throws IOException {
        String s = reader.readLine();
        if (s.indexOf('@') < 0) {
            writer.println("NO");
            return;
        }
        String user = s.substring(0, s.indexOf('@'));
        if (!verifyUser(user)) {
            writer.println("NO");
            return;
        }
        String rest = s.substring(s.indexOf('@') + 1);
        if (rest.indexOf('/') >= 0) {
            String host = rest.substring(0, rest.indexOf('/'));
            if (!verifyHost(host)) {
                writer.println("NO");
                return;
            }
            String res = rest.substring(rest.indexOf('/') + 1);
            if (!verifyUser(res)) {
                writer.println("NO");
                return;
            }
        } else {
            if (!verifyHost(rest)) {
                writer.println("NO");
                return;
            }
        }
        writer.println("YES");
    }

    private boolean verifyHost(String s) {
        if (s.length() < 1 || s.length() > 32)
            return false;
        s = s + ".";
        while (!s.isEmpty()) {
            String t = s.substring(0, s.indexOf('.'));
            if (!verifyUser(t))
                return false;
            s = s.substring(s.indexOf('.') + 1);
        }
        return true;
    }

    private boolean verifyUser(String s) {
        if (s.length() < 1 || s.length() > 16)
            return false;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch == '_')
                continue;
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        new Jabber().run();
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
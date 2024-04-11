import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Formatting implements Runnable {
    private void solve() throws IOException {
        String s = reader.readLine();
        List<String> parts = new ArrayList<String>();
        int pos = 0;
        while (pos < s.length()) {
            char ch = s.charAt(pos++);
            if (ch == ',') {
                parts.add(",");
            } else if (ch == '.') {
                parts.add("...");
                pos += 2;
            } else if (ch >= '0' && ch <= '9') {
                String t = "" + ch;
                while (pos < s.length()) {
                    char ch2 = s.charAt(pos);
                    if (ch2 < '0' || ch2 > '9') break;
                    t += ch2;
                    ++pos;
                }
                parts.add(t);
            }
        }
        writer.print(parts.get(0));
        for (int i = 1; i < parts.size(); ++i) {
            String prev = parts.get(i - 1);
            String cur = parts.get(i);
            if (prev.equals(",") || cur.equals("...") || (prev.charAt(0) >= '0' && prev.charAt(0) <= '9' && cur.charAt(0) >= '0' && cur.charAt(0) <= '9'))
                writer.print(" ");
            writer.print(cur);
        }
        writer.println();
    }

    public static void main(String[] args) {
        new Formatting().run();
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
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Types implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        Map<String, String> types = new HashMap<String, String>();
        types.put("void", "void");
        for (int j = 0; j < n; ++j) {
            String s = nextToken();
            if (s.toLowerCase().equals("typedef")) {
                String a = nextToken();
                String b = nextToken();
                String what = eval(types, a);
                types.put(b, what);
            } else {
                String a = nextToken();
                String what = eval(types, a);
                writer.println(what);
            }
        }
    }

    private String eval(Map<String, String> types, String a) {
        int delta = 0;
        while (!a.isEmpty() && a.charAt(0) == '&') {
            --delta;
            a = a.substring(1);
        }
        while (!a.isEmpty() && a.charAt(a.length() - 1) == '*') {
            ++delta;
            a = a.substring(0, a.length() - 1);
        }
        String what = types.get(a);
        if (what == null) {
            what = "errtype";
        }
        if (!what.equals("errtype")) {
            if (delta > 0) {
                for (int i = 0; i < delta; ++i) what += '*';
            }
            if (delta < 0) {
                for (int i = 0; i < -delta; ++i) {
                    if (what.endsWith("*")) what = what.substring(0, what.length() - 1); else {
                        what = "errtype";
                        break;
                    }
                }
            }
        }
        return what;
    }

    public static void main(String[] args) {
        new Types().run();
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
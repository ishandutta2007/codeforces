import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Memory implements Runnable {
    private void solve() throws IOException {
        int t = nextInt();
        int m = nextInt();
        int[] what = new int[m];
        int last = 0;
        for (int i = 0; i < t; ++i) {
            String op = nextToken();
            if (op.equals("alloc")) {
                int size = nextInt();
                int got = 0;
                boolean ok = false;
                for (int j = 0; j < m; ++j) {
                    if (what[j] == 0) {
                        ++got;
                        if (got >= size) {
                            ok = true;
                            ++last;
                            for (int k = j; k > j - size; --k) {
                                what[k] = last;
                            }
                            writer.println(last);
                            break;
                        }
                    } else {
                        got = 0;
                    }
                }
                if (!ok)
                    writer.println("NULL");
            } else if (op.equals("erase")) {
                int id = nextInt();
                boolean ok = false;
                if (id > 0) {
                    for (int j = 0; j < m; ++j)
                        if (what[j] == id) {
                            ok = true;
                            what[j] = 0;
                        }
                }
                if (!ok) {
                    writer.println("ILLEGAL_ERASE_ARGUMENT");
                }
            } else {
                int delta = 0;
                for (int j = 0; j < m; ++j) {
                    if (what[j] > 0) {
                        what[j - delta] = what[j];
                    } else {
                        ++delta;
                    }
                }
                for (int j = m - delta; j < m; ++j) {
                    what[j] = 0;
                }
            }
        }
    }


    public static void main(String[] args) {
        new Memory().run();
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
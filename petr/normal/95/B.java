import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class VeryLucky implements Runnable {
    private void solve() throws IOException {
        String n = nextToken();
        int[] nextDifferentFrom7 = new int[n.length() + 1];
        nextDifferentFrom7[n.length()] = n.length();
        for (int i = n.length() - 1; i >= 0; --i) {
            if (n.charAt(i) != '7')
                nextDifferentFrom7[i] = i;
            else
                nextDifferentFrom7[i] = nextDifferentFrom7[i + 1];
        }
        int[] nextDifferentFrom4 = new int[n.length() + 1];
        nextDifferentFrom4[n.length()] = n.length();
        for (int i = n.length() - 1; i >= 0; --i) {
            if (n.charAt(i) != '4')
                nextDifferentFrom4[i] = i;
            else
                nextDifferentFrom4[i] = nextDifferentFrom4[i + 1];
        }
        int times = (n.length() + 1) / 2;
        StringBuilder res = new StringBuilder();
        while (!willBeGEQ(times, times, nextDifferentFrom7, nextDifferentFrom4, 0, n)) {
            ++times;
        }
        int n4 = times;
        int n7 = times;
        boolean alreadyGreater = false;
        for (int i = 0; i < times * 2; ++i) {
            if (!alreadyGreater && n4 > 0 && n7 > 0) {
                int pos = n.length() - times * 2 + i;
                if (pos < 0) {
                    alreadyGreater = true;
                } else {
                    char ch = n.charAt(i);
                    if (ch == '4') {
                        if (willBeGEQ(n7, n4 - 1, nextDifferentFrom7, nextDifferentFrom4, pos + 1, n)) {
                            res.append('4');
                            --n4;
                            continue;
                        } else {
                            res.append('7');
                            --n7;
                            alreadyGreater = true;
                            continue;
                        }
                    } else if (ch > '4') {
                        if (ch > '7') throw new RuntimeException();
                        --n7;
                        res.append('7');
                        if (ch < '7') alreadyGreater = true;
                        continue;
                    } else {
                        alreadyGreater = true;
                        res.append('4');
                        --n4;
                        continue;
                    }
                }
            }
            if (n4 > 0) {
                res.append('4');
                --n4;
            } else {
                res.append('7');
                --n7;
            }
        }
        writer.println(res);
    }

    private boolean willBeGEQ(int n7, int n4, int[] nextDifferentFrom7, int[] nextDifferentFrom4, int at, String n) {
        if (at < 0)
            return true;
        if (n7 + n4 > n.length() - at)
            return true;
        if (n7 + n4 < n.length() - at)
            return false;
        int diff = nextDifferentFrom7[at];
        if (diff - at < n7) {
            char ch = n.charAt(diff);
            if (ch > '7')
                return false;
            if (ch < '7')
                return true;
            throw new RuntimeException();
        }
        diff = nextDifferentFrom4[at + n7];
        if (diff - at - n7 < n4) {
            char ch = n.charAt(diff);
            if (ch > '4')
                return false;
            if (ch < '4')
                return true;
            throw new RuntimeException();
        }
        return true;
    }

    public static void main(String[] args) {
        new VeryLucky().run();
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
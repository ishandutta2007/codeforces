import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Xorg implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        long k = nextLong();
        writer.println(doit(n, k));
    }

    private String doit(int n, long k) {
        long total = howMany("", n);
        if (k > total)
            return "-1";
        else {
            String res = "";
            for (int i = 0; i < n; ++i) {
                String cur = res + "0";
                long am = howMany(cur, n);
                if (k > am) {
                    k -= am;
                    cur = res + "1";
                }
                res = cur;
            }
            return res;
        }
    }

    private long howMany(String prefix, int n) {
        if (prefix.length() == 0)
            return howMany("0", n);
        if (prefix.charAt(0) == '1')
            return 0;
        long res = 0;
        if (prefix.length() < n || prefix.charAt(n - 1) == '0')
            res += howManyWith0(prefix, n);
        if (prefix.length() < n || prefix.charAt(n - 1) == '1')
            res += howManyWith1(prefix, n);
        return res;
    }

    private long howManyWith1(String prefix, int n) {
        StringBuilder b = new StringBuilder();
        b.append(prefix);
        while (b.length() < n - 1)
            b.append("?");
        if (b.length() < n)
            b.append("1");
        String mask = b.toString();
        long res = 0;
        for (int numMatch = 0; numMatch <= n; ++numMatch) {
            int[] rel = new int[n];
            Arrays.fill(rel, -2);
            for (int eqi = 0; eqi < numMatch; ++eqi) {
                setRel2(eqi, n - 1 - eqi, rel, 0);
            }
            if (numMatch < n)
                setRel2(numMatch, n - 1 - numMatch, rel, -1);
            long cur = 1;
            for (int i = 0; i <= n - 1 - i; ++i) {
                int cases = 0;
                for (int ca = '0'; ca <= '1'; ++ca)
                    if (ca == mask.charAt(i) || mask.charAt(i) == '?')
                        for (int cb = '0'; cb <= '1'; ++cb)
                            if ((cb == mask.charAt(n - 1 - i) || mask.charAt(n - 1 - i) == '?') && (i < n - 1 - i || ca == cb)) {
                                switch (rel[i]) {
                                    case -2:
                                        ++cases;
                                        break;
                                    case -1:
                                        if (ca < (cb ^ 1))
                                            ++cases;
                                        break;
                                    case 0:
                                        if (ca == (cb ^ 1))
                                            ++cases;
                                        break;
                                    case 1:
                                        if (ca > (cb ^ 1))
                                            ++cases;
                                        break;
                                }
                            }
                cur *= cases;
            }
            res += cur;
        }
        return res;
    }

    private long howManyWith0(String prefix, int n) {
        StringBuilder b = new StringBuilder();
        b.append(prefix);
        while (b.length() < n - 1)
            b.append("?");
        if (b.length() < n)
            b.append("0");
        String mask = b.toString();
        long res = 0;
        for (int numMatch = 0; numMatch <= n; ++numMatch) {
            int[] rel = new int[n];
            Arrays.fill(rel, -2);
            for (int eqi = 0; eqi < numMatch; ++eqi) {
                setRel(eqi, n - 1 - eqi, rel, 0);
            }
            if (numMatch < n)
                setRel(numMatch, n - 1 - numMatch, rel, -1);
            long cur = 1;
            for (int i = 0; i <= n - 1 - i; ++i) {
                int cases = 0;
                for (int ca = '0'; ca <= '1'; ++ca)
                    if (ca == mask.charAt(i) || mask.charAt(i) == '?')
                        for (int cb = '0'; cb <= '1'; ++cb)
                            if ((cb == mask.charAt(n - 1 - i) || mask.charAt(n - 1 - i) == '?') && (i < n - 1 - i || ca == cb)) {
                                switch (rel[i]) {
                                    case -2:
                                        ++cases;
                                        break;
                                    case -1:
                                        if (ca < cb)
                                            ++cases;
                                        break;
                                    case 0:
                                        if (ca == cb)
                                            ++cases;
                                        break;
                                    case 1:
                                        if (ca > cb)
                                            ++cases;
                                        break;
                                }
                            }
                cur *= cases;
            }
            res += cur;
        }
        if (mask.indexOf("1") < 0)
            --res;
        return res;
    }

    private void setRel(int a, int b, int[] rel, int what) {
        if (rel[a] == 2 || rel[b] == 2)
            return;
        if (rel[a] == -2) {
            rel[a] = what;
        } else if (rel[a] != what) {
            rel[a] = 2;
            rel[b] = 2;
            return;
        }
        if (rel[b] == -2) {
            rel[b] = -what;
        } else if (rel[b] != -what) {
            rel[b] = 2;
            rel[a] = 2;
            return;
        }
    }


    private void setRel2(int a, int b, int[] rel, int what) {
        if (rel[a] == 2 || rel[b] == 2)
            return;
        if (rel[a] == -2) {
            rel[a] = what;
        } else if (rel[a] != what) {
            rel[a] = 2;
            rel[b] = 2;
            return;
        }
        if (rel[b] == -2) {
            rel[b] = what;
        } else if (rel[b] != what) {
            rel[b] = 2;
            rel[a] = 2;
            return;
        }
    }


    public static void main(String[] args) {
        new Xorg().run();
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
import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    boolean[] can = new boolean[10];
    boolean[] used = new boolean[10];

    ArrayList<Integer> alr = new ArrayList<>();

    ArrayList<String> answ = new ArrayList<>();

    int[] xx = new int[12];
    int xxLen = -1;

    boolean isOk(int fr, int to) {
        if (fr == to)
            return true;
        if (xx[fr] == 0)
            return false;
        if (to -fr == 1)
            return true;
        if (xx[fr] < 2)
            return true;
        if (xx[fr] > 2)
            return false;
        if (xx[fr + 1] > 5)
            return false;
        if (xx[fr + 1] < 5)
            return true;
        return xx[fr + 2] <= 5;
    }

    void check() {
        Arrays.fill(used, false);
        for (int i = 0; i < xxLen; i++) {
            used[xx[i]] = true;
        }
        for (int i = 0; i < 10; i++)
            if (can[i] && !used[i])
                return;
        for (int f = 1; f <= 3; f++)
            for (int s = 1; s <= 3; s++)
                for (int t = 1; t <= 3; t++) {
                    int len4 = xxLen - f - s - t;
                    if (len4 > 3 || len4 < 1)
                        continue;
                    boolean part1 = isOk(0, f - 1);
                    boolean part2 = isOk(f, f + s - 1);
                    boolean part3 = isOk(f + s, f + s + t - 1);
                    boolean part4 = isOk(f + s + t, xxLen - 1);
                    if (part1 && part2 && part3 && part4) {
                        char[] ans = new char[3 + xxLen];
                        for (int i = 0; i <= f - 1; i++)
                            ans[i] = (char) (xx[i] + '0');
                        ans[f] = '.';
                        for (int i = f; i <= f + s - 1; i++)
                            ans[i + 1] = (char) (xx[i] + '0');
                        ans[f + s + 1] = '.';
                        for (int i = f + s; i <= f + s + t - 1; i++)
                            ans[i + 2] = (char) (xx[i] + '0');
                        ans[f + s + t + 2] = '.';
                        for (int i = f + s + t; i <= xxLen - 1; i++)
                            ans[i + 3] = (char) (xx[i] + '0');
                        answ.add(new String(ans));
                    }
                }
    }

    void gen(int len) {
        if (len >= 2) {
            for (int i = 0; i < alr.size(); i++) {
                xx[i] = alr.get(i);
                xx[alr.size() * 2 - i - 1] = xx[i];
            }
            xxLen = alr.size() * 2;
            check();
            xxLen--;
            for (int i = 0; i < alr.size(); i++) {
                xx[xxLen - i - 1] = xx[i];
            }
            check();
        }
        if (len < 6) {
            for (int i = 0; i < 10; i++)
                if (can[i]) {
                    alr.add(i);
                    gen(len + 1);
                    alr.remove(alr.size() - 1);
                }
        }
    }

    void solve() throws IOException {
        int n = in.nextInt();
        if (n > 6) {
            out.println(0);
            return;
        }
        for (int i = 0; i < n; i++) {
            can[in.nextInt()] = true;
        }
        gen(0);
        out.println(answ.size());
        for (String s : answ) {
            out.println(s);
        }
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() throws IOException {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        new CF().runIO();
    }
}
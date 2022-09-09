import java.io.*;
import java.util.*;

public class Test {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int cntZero = 0;
        List<Integer> all = new ArrayList<>();
        List<Integer> go = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            char[] s = in.next().toCharArray();
            int minBalance = 0;
            int curBalance = 0;
            for (char c : s) {
                if (c == '(') {
                    curBalance++;
                } else {
                    curBalance--;
                    minBalance = Math.min(minBalance, curBalance);
                }
            }
            if (minBalance == curBalance && minBalance == 0) {
                cntZero++;
            } else {
                if (minBalance == 0) {
                    all.add(curBalance);
                } else {
                    if (curBalance == minBalance) {
                        go.add(-curBalance);
                    }
                }
            }
        }
        int res = cntZero / 2;
        Collections.sort(all);
        Collections.sort(go);
        int it = 0;
        for (int i : all) {
            while (it < go.size() && go.get(it) < i) {
                it++;
            }
            if (it != go.size() && go.get(it) == i) {
                it++;
                res++;
            }
        }
        out.println(res);
    }

    void run() {
        try {
            in = new FastScanner(new File("Test.in"));
            out = new PrintWriter(new File("Test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

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

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Test().runIO();
    }
}
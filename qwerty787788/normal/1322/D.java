import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] agg = new int[n];
        for (int i = 0; i < n; i++) {
            agg[i] = in.nextInt();
        }
        int[] costToBuy = new int[n];
        for (int i = 0; i < n; i++) {
            costToBuy[i] = in.nextInt();
        }
        final int SHIFT = 20;
        add = new int[n + m + SHIFT];
        for (int i = 0; i < n + m; i++) {
            add[i + 1] = in.nextInt();
        }
        res = new int[m + SHIFT][n + 1]; // last aggression, how much add
        for (int i = 0; i < res.length; i++) {
            Arrays.fill(res[i], Integer.MIN_VALUE / 2);
        }
        res[res.length - 1][0] = 0;
        for (int curA = res.length - 2; curA >= 0; curA--) {
            for (int needAdd = 0; needAdd < res[0].length; needAdd++) {
                res[curA][needAdd] = Math.max(res[curA][needAdd], add[curA] * needAdd + res[curA + 1][needAdd / 2]);
            }
        }
        for (int id = 0; id < n; id++) {
            int curAgg = agg[id];
            updateBack(curAgg, res[0].length);
            for (int more = 0; more < n; more++) {
                res[curAgg][more] = Math.max(res[curAgg][more], -costToBuy[id] + res[curAgg][more + 1]);
            }
            update(curAgg - 1);
        }
        int ans = 0;
        for (int i = 0; i < res.length; i++) {
            ans = Math.max(ans, res[i][0]);
        }
        out.println(ans);
    }

    int[] add;

    void update(int fromLine) {
        int start = 2;
        for (int curA = fromLine; curA >= 0; curA--) {
            if (start > res[0].length) {
                break;
            }
            for (int needAdd = start; needAdd < res[0].length; needAdd++) {
                res[curA][needAdd] = Math.max(res[curA][needAdd], add[curA] * needAdd + res[curA + 1][needAdd / 2]);
            }
            start *= 2;
        }
    }

    void updateBack(int fromLine, int till) {
        if (fromLine == res.length - 1) {
            return;
        }
        if (till == 0) {
            for (int i = fromLine + 1; i < res.length; i++) {
                res[fromLine][0] = Math.max(res[fromLine][0], res[i][0]);
            }
            return;
        }
        updateBack(fromLine + 1, till / 2);
        for (int needAdd = 0; needAdd < res[0].length; needAdd++) {
            res[fromLine][needAdd] = Math.max(res[fromLine][needAdd], add[fromLine] * needAdd + res[fromLine + 1][needAdd / 2]);
        }
    }

    int[][] res;


    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

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
        new A().runIO();
    }
}
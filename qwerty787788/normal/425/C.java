import java.io.*;
import java.util.*;
import java.util.Map.Entry;
import java.util.concurrent.atomic.AtomicLong;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int s = in.nextInt();
        int e = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        for (int i = 0; i < m; i++)
            b[i] = in.nextInt();
        final int MAX = (int) 1e5 + 123;
        ArrayList<Integer>[] pos = new ArrayList[MAX];
        for (int i = 0; i < pos.length; i++)
            pos[i] = new ArrayList<>();
        for (int i = 0; i < m; i++)
            pos[b[i]].add(i);
        int res = 0;
        int[] lastDp = new int[n];
        int[] nextDp = new int[n];
        Arrays.fill(lastDp, 0);
        int[] iters = new int[MAX];
        for (int del = 1; del <= 333; del++) {
            if (del * e > s)
                break;
            Arrays.fill(nextDp, Integer.MAX_VALUE);
            for (int i = 0; i < MAX; i++)
                iters[i] = pos[i].size();
            for (int curPos = 0; curPos < n; curPos++) {
                if (curPos > 0) {
                    nextDp[curPos] = nextDp[curPos - 1];
                }
                int from = 0;
                if (del != 1) {
                    if (curPos == 0) {
                        from = Integer.MAX_VALUE;
                    } else {
                        from = lastDp[curPos - 1];
                        if (from != Integer.MAX_VALUE)
                            from++;
                    }
                }
                if (from != Integer.MAX_VALUE) {
                    int needValue = a[curPos];
                    while (iters[needValue] != 0
                            && pos[needValue].get(iters[needValue] - 1) >= from)
                        iters[needValue]--;
                    if (iters[needValue] < pos[needValue].size()) {
                        nextDp[curPos] = Math.min(nextDp[curPos],
                                pos[needValue].get(iters[needValue]));
                    }
                }
                if (nextDp[curPos] != Integer.MAX_VALUE) {
                    int totalCost = curPos + 1 + nextDp[curPos] + 1 + del * e;
                    if (totalCost <= s) {
                        res = Math.max(res, del);
                    }
                }
            }
            int[] tmp = lastDp;
            lastDp = nextDp;
            nextDp = tmp;
        }
        out.println(res);

    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}
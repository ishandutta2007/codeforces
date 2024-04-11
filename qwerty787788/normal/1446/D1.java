import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;


    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        int maxValue = 0;
//        TreeSet<Integer>[] where = new TreeSet[n];
//        for (int i = 0; i < n; i++) {
//            where[i] = new TreeSet<>();
//        }
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
            maxValue = Math.max(maxValue, a[i]);
//            where[a[i]].add(i);
        }
        int[] cnt = new int[maxValue + 1];
        for (int x : a) {
            cnt[x]++;
        }
        int maxId = 0;
        for (int i = 1; i <= maxValue; i++) {
            if (cnt[i] > cnt[maxId]) {
                maxId = i;
            }
        }
        int offset = cnt[maxId];
//        where[maxId].add(-1);
//        where[maxId].add(n);
//        HashMap<Integer, Integer>[] deltasPos = new HashMap[n];
//        for (int i = 0; i < n; i++) {
//            deltasPos[i] = new HashMap<>();
//        }
        int[][] deltasPos = new int[maxValue + 1][n + 1];
        for (int i = 0; i < deltasPos.length; i++) {
            if (i == maxId) {
                continue;
            }
            Arrays.fill(deltasPos[i], -1);
            deltasPos[i][offset] = 0;
        }
        Arrays.fill(cnt, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
            for (int another = 0; another <= maxValue; another++) {
                if (another == maxId) {
                    continue;
                }
                int curDelta = -cnt[maxId] + cnt[another] + offset;

                int firstSuchDelta = deltasPos[another][curDelta];
                if (firstSuchDelta == -1) {
                    deltasPos[another][curDelta] = i + 1;
                } else {
                    int from = firstSuchDelta, to = i;
                    res = Math.max(res, to - from + 1);
                }
            }
        }
        out.println(res);
    }

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
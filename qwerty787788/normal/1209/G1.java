import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int q = in.nextInt();
        int[] a = new int[n];
        final int MAX = (int) 2e5 + 10;
        List<Integer>[] where = new List[MAX];
        for (int i = 0; i < MAX; i++) {
            where[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            where[a[i]].add(i);
        }
        int[] delta = new int[n];
        for (int val = 0; val < MAX; val++) {
            if (where[val].isEmpty()) {
                continue;
            }
            int from = where[val].get(0);
            int to = where[val].get(where[val].size() - 1);
            delta[from]++;
            delta[to]--;
        }
        int[] cnt = new int[MAX];
        int res = 0;
        for (int i = 0; i < n; ) {
            int j = i + 1;
            int prefSum = delta[i];
            while (prefSum != 0) {
                prefSum += delta[j];
                j++;
            }
            int maxSame = 0;
            for (int pos = i; pos < j; pos++) {
                cnt[a[pos]]++;
                maxSame = Math.max(maxSame, cnt[a[pos]]);
            }
            res += (j - i) - maxSame;
            for (int pos = i; pos < j; pos++) {
                cnt[a[pos]] = 0;
            }
            i = j;
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
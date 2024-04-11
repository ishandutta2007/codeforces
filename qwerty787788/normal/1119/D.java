import java.io.*;
import java.util.*;

public class Test {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        long[] s = new long[n];
        for (int i = 0; i < n; i++) {
            s[i] = in.nextLong();
        }
        Arrays.sort(s);
        int q = in.nextInt();
        Query[] queries = new Query[q];
        for (int i = 0; i < q; i++) {
            long l = in.nextLong();
            long r = in.nextLong();
            queries[i] = new Query(i, r - l + 1);
        }
        Arrays.sort(queries);
        long[] events = new long[n - 1];
        for (int i = 0; i < events.length; i++) {
            events[i] = s[i + 1] - s[i];
        }
        Arrays.sort(events);
        int evIt = 0;
        long curLen = 0, curDelta = n;
        long curAns = 0;
        long[] ans = new long[queries.length];
        for (Query qu : queries) {
            long needLen = qu.len;
            while (evIt != events.length && events[evIt] < needLen) {
                long nextLen = events[evIt];
                curAns += (nextLen - curLen) * curDelta;
                curLen = nextLen;
                curDelta--;
                evIt++;
            }
            {
                long nextLen = needLen;
                curAns += (needLen - curLen) * curDelta;
                curLen = nextLen;
            }
            ans[qu.id] = curAns;
        }
        for (long z : ans) {
            out.print(z + " ");
        }
        out.println();
    }

    class Query implements Comparable<Query> {
        int id;
        long len;

        public Query(int id, long len) {
            this.id = id;
            this.len = len;
        }

        @Override
        public int compareTo(Query o) {
            return Long.compare(len, o.len);
        }
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
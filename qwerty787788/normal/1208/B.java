import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        HashMap<Integer, Integer> hm = new HashMap<>();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            Integer z = hm.get(x);
            if (z == null) {
                hm.put(x, hm.size());
                x = hm.size() - 1;
            } else {
                x = z;
            }
            a[i] = x;
        }
//        System.err.println(Arrays.toString(a));
        int[] cnt = new int[hm.size()];
        int ans = n;
        for (int start = 0; start < n; start++) {
            Arrays.fill(cnt, 0);
            for (int i = 0; i < n; i++) {
                cnt[a[i]]++;
            }
            int cntBig = 0;
            for (int i = 0; i < cnt.length; i++) {
                if (cnt[i] > 1) {
                    cntBig++;
                }
            }
            for (int end = start; end <= n; end++) {
                if (cntBig == 0) {
                    ans = Math.min(ans, end - start);
                    break;
                }
                if (end != n) {
                    cnt[a[end]]--;
                    if (cnt[a[end]] == 1) {
                        cntBig--;
                    }
                }
            }
        }
        out.println(ans);
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
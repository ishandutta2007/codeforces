import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] cnt = new int[n];
        for (int i = 0; i < m; i++) {
            int f = in.nextInt() - 1;
            int t = in.nextInt() - 1;
            cnt[f]++;
            cnt[t]++;
        }
        Random rnd = new Random();
        for (int i = 0; i < n; i++) {
            int t = rnd.nextInt(i + 1);
            int tmp = cnt[t];
            cnt[t] = cnt[i];
            cnt[i] = tmp;
        }
        Arrays.sort(cnt);
        if (cnt[0] == 1 && cnt[1] == 1 && cnt[2] == 2 && cnt[n - 1] == 2) {
            out.println("bus topology");
            return;
        }
        if (cnt[0] == 2 && cnt[n - 1] == 2) {
            out.println("ring topology");
            return;
        }
        if (cnt[0] == 1 && cnt[n - 2] == 1 && cnt[n - 1] == n - 1) {
            out.println("star topology");
            return;
        }
        out.println("unknown topology");
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
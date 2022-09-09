import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] l = new int[n];
        int[] id = new int[n];
        Arrays.fill(l, -1);
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt() - 1;
            int len = in.nextInt();
            if (l[fr] < len) {
                l[fr] = len;
                id[fr] = i + 1;
            }
        }
        int bestR = -1;
        int bestId = -1;
        int lastR = -1;
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (l[i] != -1 || (bestR >= i)) {
                if (bestR < i - 1 + l[i]) {
                    bestR = i - 1 + l[i];
                    bestId = id[i];
                }
                if (lastR < i) {
                    ans.add(bestId);
                    lastR = bestR;
                }
            }
        }
        boolean[] canRemove = new boolean[m];
        Arrays.fill(canRemove, true);
        for (int x : ans)
            canRemove[x - 1] = false;
        out.println(m - ans.size());
        for (int i = 0; i < m; i++)
            if (canRemove[i])
                out.print((i + 1) + " ");
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
import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        char[] s = in.next().toCharArray();
        List<Integer> open = new ArrayList<>();
        List<Integer> close = new ArrayList<>();
        for (int i = 0; i < s.length; i++) {
            if (s[i] == '(') {
                open.add(i);
            } else {
                close.add(i);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < open.size() && i < close.size(); i++) {
            if (open.get(i) < close.get(close.size() - 1 - i)) {
                ans.add(open.get(i));
                ans.add(close.get(close.size() - 1 - i));
            }
        }
        if (ans.isEmpty()) {
            out.println(0);
        } else {
            out.println(1);
            out.println(ans.size());
            Collections.sort(ans);
            for (int x : ans) {
                out.print((1 + x) + " ");
            }
            out.println();
        }
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
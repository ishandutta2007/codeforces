import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            String s = in.next();
            int[] cnt = new int[10];
            for (char c : s.toCharArray()) {
                cnt[c - '0']++;
            }
            char[] res = new char[n];
            int expValue = 0;
            for (int it = 0; it < 2; it++) {
                char curChar = (char) ('1' + it);
                for (int pos = 0; pos < n; pos++) {
                    while (expValue != 10 && cnt[expValue] == 0) {
                        expValue++;
                    }
                    if (s.charAt(pos) - '0' == expValue) {
                        cnt[expValue]--;
                        res[pos] = curChar;
                    }
                }
            }
            while (expValue != 10 && cnt[expValue] == 0) {
                expValue++;
            }
            if (expValue != 10) {
                out.println('-');
            } else {

                out.println(new String(res));
            }
        }
    }

    class O implements Comparable<O> {
        int pos;
        int value;

        public O(int pos, int value) {
            this.pos = pos;
            this.value = value;
        }

        @Override
        public int compareTo(O o) {
            if (value != o.value) {
                return Integer.compare(value, o.value);
            }
            return Integer.compare(pos, o.pos);
        }

        @Override
        public String toString() {
            return "O{" +
                    "pos=" + pos +
                    ", value=" + value +
                    '}';
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
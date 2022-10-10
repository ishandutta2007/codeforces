import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Admin on 11.03.2017.
 */
public class Maximize {

    public static void main(String[] args) {
        new Maximize().run();
    }

    private void run() {
        IO files = new IO();
        long x = files.nextLong();
        char[] s = String.valueOf(x).toCharArray();

        int sum = 0, pref = 0, res = -1;

        for (int i = 0; i < s.length; i++) {
            int cur = 9 * (s.length - i - 1) + pref + (s[i] - '0' - 1);
            if (cur >= sum) {
                sum = cur;
                res = i;
            }
            pref += s[i] - '0';
        }

        int cur = 0;
        for (char c : s) {
            cur += c - '0';
        }
        if (cur >= sum) {
            res = s.length;
        }

        for (int i = 0; i < res; i++) {
            files.out.print(s[i]);
        }
        if (res < s.length) {
            if (res > 0 || s[res] > '1') {
                files.out.print((char) (s[res] - 1));
            }
            for (int i = res + 1; i < s.length; i++) {
                files.out.print(9);
            }
        }

        files.out.close();
    }

    class IO {
        private BufferedReader in;
        private StringTokenizer st;
        PrintWriter out;

        public IO(String name) {
            try {
                in = new BufferedReader(new FileReader(name + ".in"));
                out = new PrintWriter(name + ".out");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public IO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out, true);
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine() {
            try {
                return in.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
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

}
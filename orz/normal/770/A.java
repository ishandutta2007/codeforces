import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Admin on 11.03.2017.
 */
public class Password {

    public static void main(String[] args) {
        new Password().run();
    }

    private void run() {
        IO files = new IO();
        int n = files.nextInt(), k = files.nextInt();

        for (int i = 0; i < n; i++) {
            files.out.print((char) ('a' + i % k));
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
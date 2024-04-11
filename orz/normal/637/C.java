import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by asus on 13.03.2016.
 */
public class C_Codes {

    public static void main(String[] args) {
        new C_Codes().run();
    }

    private void run() {
        IO files = new IO();
        int n = files.nextInt();

        String[] codes = new String[n];
        for (int i = 0; i < n; i++) {
            codes[i] = files.next();
        }

        int k = 7;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int t = 0;
                for (int bit = 0; bit < 6; bit++) {
                    if (codes[i].charAt(bit) != codes[j].charAt(bit)) {
                        t++;
                    }
                }
                k = Math.min(k, (t + 1) / 2);
            }
        }

        files.println(k - 1);
        files.close();
    }

    private class IO {
        BufferedReader in;
        PrintWriter out;
        StringTokenizer st;

        public IO(String name) {
            try {
                in = new BufferedReader(new FileReader(name + ".in"));
                out = new PrintWriter(name + ".out");
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public IO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }

        String nextLine() {
            String s = null;
            while (s == null) {
                try {
                    s = in.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return s;
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

        int nextInt() {
            return Integer.parseInt(next());
        }

        void print(Object s) {
            out.print(s);
        }

        void println(Object s) {
            out.println(s);
        }

        void close() {
            out.close();
        }
    }

}
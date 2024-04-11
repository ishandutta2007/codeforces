import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by  on 28.03.2016.
 */
public class Tree {

    public static void main(String[] args) {
        new Tree().run();
    }

    private void run() {
        IO std = new IO();
        int n = std.nextInt(), d = std.nextInt(), h = std.nextInt();

        if (2 * h < d) {
            std.println(-1);
        } else if (d > h) {
            for (int i = 1; i <= h; i++) {
                std.println(i + " " + (i + 1));
            }
            std.println(1 + " " + (h + 2));
            for (int i = h + 2; i <= d; i++) {
                std.println(i + " " + (i + 1));
            }
            for (int i = d + 2; i <= n; i++) {
                std.println(1 + " " + i);
            }
        } else {
            if (d == 1) {
                if (n == 2) {
                    std.println("1 2");
                } else {
                    std.println(-1);
                }
            } else {
                for (int i = 1; i <= h; i++) {
                    std.println(i + " " + (i + 1));
                }
                for (int i = h + 2; i <= n; i++) {
                    std.println(h + " " + i);
                }
            }
        }
        std.close();
    }

    public class IO {
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

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public void print(Object o) {
            out.print(o);
        }

        public void println(Object o) {
            out.println(o);
        }

        public void close() {
            out.close();
        }
    }

}
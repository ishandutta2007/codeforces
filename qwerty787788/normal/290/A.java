import java.io.*;
import java.util.*;

public class FirstApril {
    FastScanner in;
    PrintWriter out;
    
    String[] s = {"Washington",
            "Adams",
            "Jefferson",
            "Madison",
            "Monroe",
            "Adams",
            "Jackson",
            "Van Buren",
            "Harrison",
            "Tyler",
            "Polk",
            "Taylor",
            "Fillmore",
            "Pierce",
            "Buchanan",
            "Lincoln",
            "Johnson",
            "Grant",
            "Hayes",
            "Garfield",
            "Arthur",
            "Cleveland",
            "Harrison",
            "Cleveland",
            "McKinley",
            "Roosevelt",
            "Taft",
            "Wilson",
            "Harding",
            "Coolidge",
            "Hoover",
            "Roosevelt",
            "Truman",
            "Eisenhower",
            "Kennedy",
            "Johnson",
            "Nixon",
            "Ford",
            "Carter",
            "Reagan"
};
    
    void solve() {
        out.println(s[in.nextInt() - 1]);
    }

    void run() {
        try {
            in = new FastScanner(new File("object.in"));
            out = new PrintWriter(new File("object.out"));

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
    }

    public static void main(String[] args) {
        new FirstApril().runIO();
    }
}
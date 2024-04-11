import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() throws IOException {
        int n = in.nextInt();
        String s1 = in.next();
        String s2 = in.next();
        int x11 = 0;
        int x10 = 0;
        int x01 = 0;
        int x00 = 0;
        for (int i =0; i < n * 2; i++) {
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            if (c1 == '1' && c2 == '1')
                x11++;
            if (c1 == '1' && c2 == '0')
                x10++;
            if (c1 == '0' && c2 == '1')
                x01++;
            if (c1 == '0' && c2 == '0')
                x00++;
        }
        int f = 0;
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (x11 > 0) {
                x11--;
                f++;
            } else {
                if (x10 > 0) {
                    x10--;
                    f++;
                } else {
                    if (x01 > 0) {
                        x01--;
                    } else {
                        x00--;
                    }
                }
            }
            
            if (x11 > 0) {
                x11--;
                s++;
            } else {
                if (x01 > 0) {
                    x01--;
                    s++;
                } else {
                    if (x10 > 0) {
                        x10--;
                    } else {
                        x00--;
                    }
                }
            }
        }
        if (f > s) {
            out.println("First");
            return;
        }
        if (f < s) {
            out.println("Second");
            return;
        }
        out.println("Draw");
        
        
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
import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() throws IOException {
        String s = in.br.readLine();
        boolean onlyQ = false;
        boolean write = false;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '"') {
                if (write) {
                    out.println(">");
                    onlyQ = false;
                    write = false;
                } else {
                    out.print("<");
                    onlyQ = true;
                    write = true;
                }
            } else {
                if (c == ' ') {
                    if (write && !onlyQ) {
                        out.println(">");
                        write = false;
                    } else {
                        if (write) {
                            out.print(c);
                        }
                    }
                } else {
                    if (!write) {
                        out.print("<");
                        write = true;
                    }
                    out.print(c);
                }
            }
        }
        if (write) {
            out.println(">");
        }
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
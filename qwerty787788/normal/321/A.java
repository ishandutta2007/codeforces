import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    boolean check(int stX, int stY, String s, int nx, int ny) {
        if (stX == nx && stY == ny)
            return true;
        int x = stX;
        int y = stY;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'U') {
                y++;
            } else {
                if (c == 'D') {
                    y--;
                } else {
                    if (c == 'R') {
                        x++;
                    } else {
                        x--;
                    }
                }
            }
            if (x == nx && y == ny)
                return true;
        }
        return false;
    }

    void solve() {
        int a = in.nextInt();
        int b = in.nextInt();
        String s = in.next();
        int x = 0;
        int y = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'U') {
                y++;
            } else {
                if (c == 'D') {
                    y--;
                } else {
                    if (c == 'R') {
                        x++;
                    } else {
                        x--;
                    }
                }
            }
        }
        boolean ok = check(0, 0, s, a, b);
        int time = 0;
        if (x != 0) {
            time = a / x;
            int stTime = Math.max(0, time - 1000);
            int lastTime = time + 1000;
            for (int t = stTime; t < lastTime; t++) {
                long curX = x * 1L * t;
                long curY = y * 1L * t;
                if (curX >= 2 * 1e9 || curY > 2 * 1e9)
                    continue;
                int cx = (int) curX;
                int cy = (int) curY;
                ok |= check(cx, cy, s, a, b);
            }
        }
        if (y != 0) {
            time = b / y;
            int stTime = Math.max(0, time - 1000);
            int lastTime = time + 1000;
            for (int t = stTime; t < lastTime; t++) {
                long curX = x * 1L * t;
                long curY = y * 1L * t;
                if (curX >= 2 * 1e9 || curY > 2 * 1e9)
                    continue;
                int cx = (int) curX;
                int cy = (int) curY;
                ok |= check(cx, cy, s, a, b);
            }
        }
        
        if (ok) {
            out.println("Yes");
        } else {
            out.println("No");
        }

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
        new CF().runIO();
    }
}
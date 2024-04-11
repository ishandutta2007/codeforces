import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve(int n, int k) {
        int block = Math.max(1, k / 2);
        int maxMoves = 3 * n * n / 2 / k;
        if (maxMoves > 16000) {
            throw new AssertionError();
        }
        int blocks = 1 + (n - 1) / block;
        boolean[][] seen = new boolean[blocks][blocks];
        List<Integer>[] insideBlock = new List[blocks];
        for (int i = 0; i < insideBlock.length; i++) {
            insideBlock[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            insideBlock[i / block].add(i + 1);
        }
        int resets = 30000;
        boolean[] alive = new boolean[n];
        Arrays.fill(alive, true);
        while (true) {
            out.println("R");
            out.flush();
            if (resets-- < 0) {
                throw new AssertionError();
            }
            int first = -1;
            if (blocks == 1) {
                first = 0;
            }
            for (int i = 0; i < blocks; i++) {
                for (int j = i + 1; j < blocks; j++) {
                    if (!seen[i][j]) {
                        first = i;
                        break;
                    }
                }
                if (first != -1) {
                    break;
                }
            }
            if (first == -1) {
                break;
            }
            while (true) {
                for (int v : insideBlock[first]) {
                    out.println("? " + v);
                    out.flush();
                    String s = in.next();
                    if (s.equals("Y")) {
                        alive[v - 1] = false;
                    }
                    if (!s.equals("N") && !s.equals("Y")) {
                        throw new AssertionError();
                    }
                }
                maxMoves -= block;
                boolean found = false;
                for (int next = first + 1; next < blocks; next++) {
                    if (!seen[first][next]) {
                        seen[first][next] = true;
                        first = next;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    break;
                }
            }
            if (blocks == 1) {
                break;
            }
        }
        int cntAlive = 0;
        for (int i = 0; i < n; i++) {
            if (alive[i]) {
                cntAlive++;
            }
        }
        out.println("! " + cntAlive);
        out.flush();
    }

    void solve() {
        solve(in.nextInt(), in.nextInt());
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
        try {
            new A().runIO();
        } catch (AssertionError e) {
            while (true) {}
        }
    }
}
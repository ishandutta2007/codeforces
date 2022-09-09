import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = 4;
        int m = in.nextInt();
        int cars = in.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = in.nextInt();
            }
        }
        List<Move> ans = new ArrayList<>();
        for (int it = 0; it < 500; it++) {
            for (int y = 0; y < m; y++) {
                int id = a[1][y];
                if (id == 0) {
                    continue;
                }
                if (a[0][y] == id) {
                    ans.add(new Move(id, 0, y));
                    a[1][y] = 0;
                } else {
                    int nx = 1, ny = y - 1;
                    if (ny == -1) {
                        nx = 2;
                        ny = 0;
                    }
                    if (a[nx][ny] == 0) {
                        a[nx][ny] = id;
                        a[1][y] = 0;
                        ans.add(new Move(id, nx, ny));
                    }
                }
            }
            for (int y = m - 1; y >= 0; y--) {
                int id = a[2][y];
                if (id == 0) {
                    continue;
                }
                if (a[3][y] == id) {
                    ans.add(new Move(id, 3, y));
                    a[2][y] = 0;
                } else {
                    int nx = 2, ny = y + 1;
                    if (ny == m) {
                        nx--;
                        ny = m - 1;
                    }
                    if (a[nx][ny] == 0) {
                        a[nx][ny] = id;
                        a[2][y] = 0;
                        ans.add(new Move(id, nx, ny));
                    }
                }
            }
        }
        for (int i = 1; i <= 2; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0) {
                    out.println(-1);
                    return;
                }
            }
        }
        out.println(ans.size());
        for (Move mv : ans) {
            out.println(mv.carId + " " + (mv.x + 1) + " " + (mv.y + 1));
        }
    }

    class Move {
        int carId;
        int x, y;

        public Move(int carId, int x, int y) {
            this.carId = carId;
            this.x = x;
            this.y = y;
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
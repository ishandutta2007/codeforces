import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class C {

    BufferedReader br;
    StringTokenizer st;
    PrintStream out = System.out;
    private int n;
    private int[] c;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new C().run();
    }

    private void run() {
        br = new BufferedReader(new InputStreamReader(System.in));
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

    int[] d = new int[6];
    int m;
    int[] dd = new int[12];
    char[] ddd = new char[15];

    private void solve() throws IOException {
        n = nextInt();
        c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = nextInt();
        }
        bt(0);
        out.println(res.size());
        for (String re : res) {
            out.println(re);
        }

        //To change body of created methods use File | Settings | File Templates.
    }

    int[] o = new int[10];

    List<String> res = new ArrayList<String>();


    private void bt(int x) {
        {
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                if (o[c[i]] == 0) ok = false;
            }
//            System.out.println(x + " " + Arrays.toString(d) + Arrays.toString(o));
            if (ok) {
                m = 0;
                for (int i = 0; i < x; i++) {
                    dd[m++] = d[i];
                }
                for (int i = x - 1; i >= 0; i--) {
                    dd[m++] = d[i];
                }
                bt2(0, 0, -1);
                m = 0;
                for (int i = 0; i < x - 1; i++) {
                    dd[m++] = d[i];
                }
                for (int i = x - 1; i >= 0; i--) {
                    dd[m++] = d[i];
                }
                bt2(0, 0, -1);
            }
        }
        if (x == 6) return;
        for (int i = 0; i < n; i++) {
            d[x] = c[i];
            o[d[x]]++;
            bt(x + 1);
            o[d[x]]--;
        }
    }

    private void bt2(int x, int y, int s) {
        if (s >= 256) return;
        if (y > 3) return;
        if (x == m) {
//            System.out.println(y + " " + Arrays.toString(ddd));
            if (y == 3 && s >= 0 && s < 256) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < x + y; i++) {
                    sb.append(ddd[i]);
                }
                res.add(sb.toString());
//                out.println(sb.toString());
            }
            return;
        }
        if (s >= 0) {
            ddd[x + y] = '.';
            bt2(x, y + 1, -1);
        }
        if (s == 0) return;
        if (s == -1) s = 0;
        ddd[x + y] = (char) ('0' + dd[x]);
        bt2(x + 1, y, s * 10 + dd[x]);
    }
}

import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class C {

    BufferedReader br;
    StringTokenizer st;
    PrintStream out = System.out;

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

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            String s = next();
            String[] ss = s.split("\\.");
            a[i] = (Integer.parseInt(ss[0]) << 24) +
                    (Integer.parseInt(ss[1]) << 16) +
                    (Integer.parseInt(ss[2]) << 8) +
                    (Integer.parseInt(ss[3]));
        }

        int m = 0;
        int res = -1;
        for (int l = 0; l <= 32; l++) {
            Set<Integer> set = new HashSet<Integer>();
            for (int i : a) {
                set.add(i & m);
            }
            if (l > 0 && set.size() == k) {
                res = l;
                break;
            }
            m |= (1 << (31 - l));
        }
        if (res == -1) {
            out.println(-1);
        } else {
            out.println(((m >> 24) & 255) + "." + ((m >> 16) & 255) + "." + ((m >> 8) & 255) + "." + (m & 255));
        }
    }
}
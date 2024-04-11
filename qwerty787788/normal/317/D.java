import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    boolean firstWin(int n) {
        boolean[] fWin = new boolean[1 << n];
        for (int st = 1; st < 1 << n; st++) {
            for (int ch = 0; ch < n; ch++)
                if (((1 << ch) & st) != 0) {
                    int newSt = st;
                    int k = ch + 1;
                    while (k <= n) {
                        if (((1 << (k - 1)) & newSt) != 0)
                            newSt ^= 1 << (k - 1);
                        k *= ch + 1;
                        if (k == 1)
                            break;
                    }
                    if (!fWin[newSt]) {
                        fWin[st] = true;
                    }
                }
        }
        return fWin[(1 << n) - 1];
    }

    int firstWin2(int n) {
        byte[] fWin = new byte[1 << n];
        int[] tmp = new int[20];
        for (int st = 1; st < 1 << n; st++) {
            for (int i = 0; i < tmp.length; i++)
                tmp[i] = 0;
            for (int ch = 0; ch < n; ch++) {
                if (((1 << ch) & st) != 0) {
                    int newSt = st;
                    for (int k = ch + 1; k <= n; k += ch + 1) {
                        if (((1 << (k - 1)) & newSt) != 0)
                            newSt ^= 1 << (k - 1);
                    }
                    tmp[fWin[newSt]] = 1;
                }

            }
            while (tmp[fWin[st]] != 0)
                fWin[st]++;
        }
        for (int i = 1; i <= n; i++) {
            System.err.print(fWin[(1 << i) - 1] + ", ");
            // System.err.println(i + ": " + fWin[(1 << i) - 1]);
        }
        return fWin[(1 << n) - 1];
    }

    int[] xx = {1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12 };

    boolean isPrime(int x) {
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }

    boolean fWin3(int n) {
        int res = 0;
        int MAX = 10 + (int) Math.sqrt(n);
        boolean[] fail = new boolean[MAX];
        int ost = n;
        for (int i = 2; i * i <= n; i++) {
            if (!fail[i]) {
                int s = 0;
                long j = i;
                while (j <= n) {
                    s++;
                    if (j < fail.length)
                        fail[(int)j] = true;
                    ost--;
                    j *= i;
                }
                res ^= xx[s - 1];
            }
        }
        if (ost % 2 != 0)
            res ^= 1;
        return res == 0;
    }

    void solve() {

        // for (int i = 1; i < 25; i++) {
        // System.err.println(firstWin2(i));
        // }
        // firstWin2(29);
        int n = in.nextInt(); 
        out.println(fWin3(n) ? "Petya" : "Vasya");
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
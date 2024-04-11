import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    int toInt(String s) {
        String[] arr = s.split("\\.");
        int res = 0;
        for (int i = 0; i < arr.length; i++) {
            res = (res << 8) + Integer.parseInt(arr[i]);
        }
        return res;
    }

    int[] ips;
    int n, k;

    int isOk(int curMask) {
        HashSet<Integer> all = new HashSet<>();
        for (int i = 0; i < ips.length; i++) {
            all.add(ips[i] & curMask);
        }
        return all.size();
    }

    void printMask(int mask) {
        int[] xx = new int[4];
        for (int i = 0; i < 4; i++) {
            xx[i] = (int) (mask & 255);
            mask >>>= 8;
        }
        for (int i = 3; i >= 0; i--) {
            out.print(xx[i]);
            if (i != 0)
                out.print(".");
        }
        out.println();
    }

    void solve() throws IOException {
        n = in.nextInt();
        k = in.nextInt();
        ips = new int[n];
        for (int i = 0; i < n; i++) {
            ips[i] = toInt(in.next());
        }
        int MAX = 1 << 31;
        int curMask = MAX;
        int[] allPossibleMasks = new int[32];
        int it = 0;
        while (MAX != 0) {
            allPossibleMasks[it++] = curMask;
            MAX >>>= 1;
            curMask |= MAX;
        }
        // < k
        int l = -1, r = 31;
        while (r - l > 1) {
            int m = (r + l) / 2;
            int sum = isOk(allPossibleMasks[m]);
            if (sum < k) {
                l = m;
            } else {
                r = m;
            }
        }
        if (isOk(allPossibleMasks[r]) == k) {
            printMask(allPossibleMasks[r]);
        } else {
            out.println(-1);
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
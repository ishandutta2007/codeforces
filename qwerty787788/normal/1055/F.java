import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;


    void solve() {
        int n = in.nextInt();
        long k = in.nextLong() - 1;
        int[] p = new int[n];
        long[] w = new long[n];
        for (int i = 1; i < n; i++) {
            p[i] = in.nextInt() - 1;
            w[i] = in.nextLong() ^ w[p[i]];
        }
        Arrays.sort(w);
//        System.err.println(Arrays.toString(w));
        final int MAX = n * 2 + 10;
        int[] firstLeft = new int[MAX];
        int[] firstRight = new int[MAX];
        int[] secondLeft = new int[MAX];
        int[] secondRight = new int[MAX];

        int[] nfirstLeft = new int[MAX];
        int[] nfirstRight = new int[MAX];
        int[] nsecondLeft = new int[MAX];
        int[] nsecondRight = new int[MAX];
        int sz = 1;
        long result = 0;
        firstLeft[0] = 0;
        firstRight[0] = n;
        secondLeft[0] = 0;
        secondRight[0] = n;
        final int BIT = 62;
        int[] firstMid = new int[MAX];
        int[] secondMid = new int[MAX];
        for (int bit = BIT - 1; bit >= 0; bit--) {
//            System.err.println("bit = " + bit);
//            for (int i = 0; i < sz; i++) {
//                System.err.println(firstLeft[i] + " " + firstRight[i] + " " + secondLeft[i] + " " + secondRight[i]);
//            }
            long CURRENT = 1L << bit;
            for (int i = 0; i < sz; i++) {
                firstMid[i] = firstLeft[i];
                while (firstMid[i] != firstRight[i] && (w[firstMid[i]] & CURRENT) != CURRENT) {
                    firstMid[i]++;
                }
            }
            for (int i = 0; i < sz; i++) {
                secondMid[i] = secondLeft[i];
                while (secondMid[i] != secondRight[i] && (w[secondMid[i]] & CURRENT) != CURRENT) {
                    secondMid[i]++;
                }
            }
            long sum = 0;
            for (int i = 0; i < sz; i++) {
                sum += (firstMid[i] - firstLeft[i]) * 1L * (secondMid[i] - secondLeft[i]);
                sum += (firstRight[i] - firstMid[i]) * 1L * (secondRight[i] - secondMid[i]);
            }
//            System.err.println("sum = " + sum);
            if (sum > k) {
                // use zero
                int nsz = 0;
                for (int i = 0; i < sz; i++) {
                    if ((firstMid[i] - firstLeft[i]) * 1L * (secondMid[i] - secondLeft[i]) > 0) {
                        nfirstLeft[nsz] = firstLeft[i];
                        nfirstRight[nsz] = firstMid[i];
                        nsecondLeft[nsz] = secondLeft[i];
                        nsecondRight[nsz] = secondMid[i];
                        nsz++;
                    }
                    if ((firstRight[i] - firstMid[i]) * 1L * (secondRight[i] - secondMid[i]) > 0) {
                        nfirstLeft[nsz] = firstMid[i];
                        nfirstRight[nsz] = firstRight[i];
                        nsecondLeft[nsz] = secondMid[i];
                        nsecondRight[nsz] = secondRight[i];
                        nsz++;
                    }
                }
                sz = nsz;
            } else {
                int nsz = 0;
                for (int i = 0; i < sz; i++) {
                    if ((firstMid[i] - firstLeft[i]) * 1L * (secondRight[i] - secondMid[i]) > 0) {
                        nfirstLeft[nsz] = firstLeft[i];
                        nfirstRight[nsz] = firstMid[i];
                        nsecondLeft[nsz] = secondMid[i];
                        nsecondRight[nsz] = secondRight[i];
                        nsz++;
                    }
                    if ((firstRight[i] - firstMid[i]) * 1L * (secondMid[i] - secondLeft[i]) > 0) {
                        nfirstLeft[nsz] = firstMid[i];
                        nfirstRight[nsz] = firstRight[i];
                        nsecondLeft[nsz] = secondLeft[i];
                        nsecondRight[nsz] = secondMid[i];
                        nsz++;
                    }
                }
                sz = nsz;
                result |= 1L << bit;
                k -= sum;
            }
            {
                int[] tmp = nfirstLeft;
                nfirstLeft = firstLeft;
                firstLeft = tmp;
            }
            {
                int[] tmp = nfirstRight;
                nfirstRight = firstRight;
                firstRight = tmp;
            }
            {
                int[] tmp = nsecondLeft;
                nsecondLeft = secondLeft;
                secondLeft = tmp;
            }
            {
                int[] tmp = nsecondRight;
                nsecondRight = secondRight;
                secondRight = tmp;
            }
        }
        out.println(result);

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
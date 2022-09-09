import java.io.*;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;

    int convert(int x) {
        String s = Integer.toString(x);
        int r = 0;
        for (char c : s.toCharArray()) {
            r += c - '0';
        }
        return r;
    }

    boolean ok(int v) {
        return convert(convert(v)) < 10;
    }

    boolean solvable(int xxx) {
        String s = Integer.toString(xxx);
        Random rnd = new Random(123);
        for (int z = 0; z < 100; z++) {
            double f = rnd.nextDouble() * 0.3;
            ArrayList<Integer> split = new ArrayList<>();
            int sum = 0;
            for (int pos = 0; pos < s.length(); pos++) {
                if (pos != 0) {
                    split.add(pos);
                }
                int x = s.charAt(pos) - '0';
                if (pos + 1 != s.length() && rnd.nextDouble() < f) {
                    pos++;
                    x = x * 10 + s.charAt(pos) - '0';
                }
                sum += x;
            }
//                System.err.println("sum = " + sum);
            if (convert(sum) < 10) {
                return true;
            }
        }
        return false;
    }

    boolean solve(int xxx) {
        String s = Integer.toString(xxx);
        Random rnd = new Random(123);
        for (int z = 0; z < 100; z++) {
            double f = rnd.nextDouble() * 0.3;
            ArrayList<Integer> split = new ArrayList<>();
            int sum = 0;
            for (int pos = 0; pos < s.length(); pos++) {
                if (pos != 0) {
                    split.add(pos);
                }
                int x = s.charAt(pos) - '0';
                if (pos + 1 != s.length() && rnd.nextDouble() < f) {
                    pos++;
                    x = x * 10 + s.charAt(pos) - '0';
                }
                sum += x;
            }
            if (convert(sum) < 10) {
                int it = 0;
                for (int i = 0; i < s.length(); i++) {
                    if (it != split.size() && split.get(it).equals(i)) {
                        out.print("+");
                        it++;
                    }
                    out.print(s.charAt(i));
                }
                out.println();
                print(sum);
                return true;
            }
        }
        return false;
    }

    void solve111() {
        Random rnd = new Random(123);
        int cntOk = 0;
        for (int it = 0; ; it++) {
            int n = rnd.nextInt(2000000);
            if (solvable(n)) {
                cntOk++;
            }
            System.err.println(it + " " + (cntOk + 0.) / (it + 1.));
        }
    }

    private void solve() {
        long m = 0;
        in.nextInt();
        Random rnd = new Random(123);
        String s = in.next();
//        for (int iter = 0; ; iter++) {
//            System.err.println("iter = " + iter);
//            char[] tmp = new char[200000];
//            for (int i = 0; i < tmp.length; i++) {
//                tmp[i] = (char) ('0' + rnd.nextInt(10));
//            }
//            String s = new String(tmp);
//            long START = System.currentTimeMillis();
        while (true) {
            double f = rnd.nextDouble() * 0.3;
//                System.err.println("!!");
            ArrayList<Integer> split = new ArrayList<>();
            int sum = 0;
            for (int pos = 0; pos < s.length(); pos++) {
                if (pos != 0) {
                    split.add(pos);
                }
                int x = s.charAt(pos) - '0';
                if (pos + 1 != s.length() && rnd.nextDouble() < f) {
                    pos++;
                    x = x * 10 + s.charAt(pos) - '0';
                }
                sum += x;
            }
//                System.err.println("sum = " + sum);
            if (solvable(sum)) {
                int it = 0;
                for (int i = 0; i < s.length(); i++) {
                    if (it != split.size() && split.get(it).equals(i)) {
                        out.print("+");
                        it++;
                    }
                    out.print(s.charAt(i));
                }
                out.println();
                solve(sum);
                break;
            }
        }
//            long tim = System.currentTimeMillis() - START;
//            m = Math.max(tim, m);
//            System.err.println(tim + " " + m);
//        }
    }

    void print(int sum) {
        String z = Integer.toString(sum);
        for (int i = 0; i < z.length(); i++) {
            out.print(z.charAt(i));
            if (i != z.length() - 1) {
                out.print("+");
            } else {
                out.println();
            }
        }
    }

    private void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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
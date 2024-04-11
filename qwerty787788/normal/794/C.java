import java.io.*;
import java.util.*;

public class C {
    private FastScanner in;
    private PrintWriter out;

    int[] get() {
        int[] res = new int[26];
        String s = in.next();
        for (char c : s.toCharArray()) {
            res[c - 'a']++;
        }
        return res;
    }

    private void solve() {
        int[] smaller = get();
        int[] greater = get();
        int n = 0;
        for (int x : smaller) {
            n += x;
        }
        int needRemove = n / 2;
        for (int i = 25; i >= 0; i--) {
            int rem = Math.min(needRemove, smaller[i]);
            needRemove -= rem;
            smaller[i] -= rem;
        }
        needRemove = (n + 1) / 2;
        for (int i = 0; i < 26; i++) {
            int rem = Math.min(needRemove, greater[i]);
            needRemove -= rem;
            greater[i] -= rem;
        }
        char[] res = new char[n];
        int it1 = 0, it2 = n - 1;
        for (int i = 0; i < n; i++) {
            int smallest = 26;
            for (int j = 25; j >= 0; j--) {
                if (smaller[j] > 0) {
                    smallest = j;
                }
            }
            int greatest = -1;
            for (int j = 0; j < 26; j++) {
                if (greater[j] > 0) {
                    greatest = j;
                }
            }
            if (smallest >= greatest) {
                if (i % 2 == 0) {
                    for (int j = 25; j >= 0; j--) {
                        if (smaller[j] > 0) {
                            res[it2--] = (char) ('a' + j);
                            smaller[j]--;
                            break;
                        }
                    }
                } else {
                    for (int j = 0; j < 26; j++) {
                        if (greater[j] > 0) {
                            res[it2--] = (char) ('a' + j);
                            greater[j]--;
                            break;
                        }
                    }
                }
            } else {
                if (i % 2 == 0) {
                    smaller[smallest]--;
                    res[it1++] = (char) ('a' + smallest);
                } else {
                    greater[greatest]--;
                    res[it1++] = (char) ('a' + greatest);
                }
            }
        }
        out.println(new String(res));
    }

    private void run() {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

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
        new C().runIO();
    }
}
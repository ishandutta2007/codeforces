import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    int[] findConsecutive(int[] a) {
        int posOf1 = 0;
        while (a[posOf1] != 1) {
            posOf1++;
        }
        int posOf2 = 0;
        while (a[posOf2] != 2) {
            posOf2++;
        }
        if (Math.abs(posOf1 - posOf2) != 1) {
            return new int[]{posOf1, posOf1};
        }
        if (posOf2 > posOf1) {
            int till = posOf2;
            while (till != a.length && a[till] == a[till - 1] + 1) {
                till++;
            }
            return new int[]{posOf1, till - 1};
        } else {
            int till = posOf2;
            while (till != -1 && a[till] == a[till + 1] + 1) {
                till--;
            }
            return new int[]{posOf1, till + 1};
        }
    }

    List<int[]> res = new ArrayList<>();

    void applyMove(int[] a, int[] d) {
        res.add(d);
        List<int[]> parts = new ArrayList<>();
        int from = 0;
        for (int i = 0; i < d.length; i++) {
            int[] tmp = new int[d[i]];
            for (int j = 0; j < tmp.length; j++) {
                tmp[j] = a[from + j];
            }
            parts.add(tmp);
            from += d[i];
        }
        Collections.reverse(parts);
        from = 0;
        for (int[] part : parts) {
            for (int j = 0; j < part.length; j++) {
                a[from + j] = part[j];
            }
            from += part.length;
        }
    }

    int[] moveBySplits(boolean[] splits, int n) {
        List<Integer> di = new ArrayList<>();
        int from = 0;
        while (from != n) {
            int to = from + 1;
            while (!splits[to] && to != n) {
                to++;
            }
            di.add(to - from);
            from = to;
        }
        int[] res = new int[di.size()];
        for (int i = 0; i < res.length; i++) {
            res[i] = di.get(i);
        }
        return res;
    }

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        if (n == 1) {
            out.println(0);
            return;
        }
        while (true) {
            int[] cons = findConsecutive(a);
            if (cons[0] == 0 && cons[1] == n - 1) {
                break;
            }
            if (cons[0] == n - 1 && cons[1] == 0) {
                int[] d = new int[n];
                Arrays.fill(d, 1);
                applyMove(a, d);
                continue;
            }
            int len = Math.abs(cons[0] - cons[1]) + 1;
            int nextNumber = len + 1;
            int posNext = 0;
            while (a[posNext] != nextNumber) {
                posNext++;
            }
            boolean curDirRight = cons[1] > cons[0];
            boolean nextDirRight = posNext > cons[0];
            boolean sameDir = curDirRight == nextDirRight;
            boolean[] splits = new boolean[n + 1];
            int min = Math.min(cons[0], cons[1]);
            int max = Math.max(cons[0], cons[1]);
            if (sameDir) {
                for (int i = min; i <= max + 1; i++) {
                    splits[i] = true;
                }
            } else {
                splits[min] = true;
                splits[max + 1] = true;
            }
            if (nextDirRight) {
                splits[posNext + 1] = true;
            } else {
                splits[posNext] = true;
            }
            int[] move = moveBySplits(splits, n);
            applyMove(a, move);
        }
        if (res.size() > n) {
            throw new AssertionError();
        }
        out.println(res.size());
        for (int[] move : res) {
            out.print(move.length);
            for (int d : move) {
                out.print(" " + d);
            }
            out.println();
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

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
        new D().runIO();
    }
}
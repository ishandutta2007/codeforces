import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class O implements Comparable<O> {
        int id;
        int pos;

        public O(int id, int pos) {
            this.id = id;
            this.pos = pos;
        }

        @Override
        public int compareTo(O o) {
            return Integer.compare(pos, o.pos);
        }
    }

    void solve() {
        int n = in.nextInt();
        O[] a = new O[n];
        for (int i = 0; i < n; i++) {
            a[i] = new O(i, in.nextInt());
        }
        Arrays.sort(a);
        int[] needPos = new int[n];
        for (int i = 0; i < n; i++) {
            needPos[i] = in.nextInt();
        }
        Arrays.sort(needPos);
        final String NO = "NO";
        int right = 0;
        List<int[]> res = new ArrayList<>();
        for (int left = 0; left < n;) {
            if (a[left].pos > needPos[left]) {
                break;
            }
            if (a[left].pos == needPos[left]) {
                left++;
                continue;
            }
            right = Math.max(right, left);
            while (right != n && a[right].pos <= needPos[right]) {
                right++;
            }
            if (right == n) {
                break;
            }
//            System.err.println(left + " "+ right);
            int canMove = (a[right].pos - a[left].pos) / 2;
            canMove = Math.min(canMove, needPos[left] - a[left].pos);
            canMove = Math.min(canMove, a[right].pos - needPos[right]);
            res.add(new int[]{a[left].id + 1, a[right].id + 1, canMove});
            a[left].pos += canMove;
            a[right].pos -= canMove;
        }
        for (int i = 0; i < n; i++) {
            if (a[i].pos != needPos[i]) {
//                System.err.println(Arrays.toString(needPos));
                out.println(NO);
                return;
            }
        }
        out.println("YES");
        if (res.size() > 5 * n) {
            throw new AssertionError();
        }
        out.println(res.size());
        for (int[] z : res) {
            out.println(z[0] + " " + z[1] + " " + z[2]);
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
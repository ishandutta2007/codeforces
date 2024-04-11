import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve333() {
        Random rnd = new Random(123);
        for (int it = 0; it < 123132; it++) {
            int n = 1 + rnd.nextInt(10);
            System.err.println("it = " + it);
            int[] a = new int[n];
            int[] b = new int[n];
            final int M = 20;
            for (int i = 0; i < n; i++) {
                a[i] = rnd.nextInt(M);
                b[i] = rnd.nextInt(M);
            }
            if (it == 28) {
                System.err.println("!!!");
            }
            solve(a, b);
        }
    }

    class MyList {
        int n;
        int[] a;
        int sz;

        MyList(int n) {
            this.n = n;
            a = new int[n];
        }

        boolean isEmpty() {
            return sz == 0;
        }

        void add(int x) {
            a[sz++] = x;
        }

        int popBack() {
            return a[--sz];
        }

        void clear() {
            sz = 0;
        }

        int last() {
            return a[sz - 1];
        }
    }

    void solve(int[] a, int[] b) {
        final int n = a.length;
        int left = -1, right = 21;
        int[] realAns = null;
        List<Integer>[] g = new List[1 << 20];
        for (int i = 0; i < g.length; i++) {
            g[i] = new ArrayList<>();
        }
        boolean[] usedEdge = new boolean[n];

        MyList stack = new MyList(2 * n);
        MyList toAnswer = new MyList(2 * n);
        MyList answer = new MyList(2 * n);
        while (right - left > 1) {
            int mid = (left + right) >> 1;
            int mask = (1 << mid) - 1;
            int[] deg = new int[mask + 1];
            for (int i = 0; i <= mask; i++) {
                g[i].clear();
            }
            for (int i = 0; i < n; i++) {
                int idA = a[i] & mask;
                deg[idA]++;
                int idB = b[i] & mask;
                deg[idB]++;
                g[idA].add(i);
                g[idB].add(i);
            }
            Arrays.fill(usedEdge, false);
            boolean ok = true;
            for (int i = 0; i <= mask; i++) {
                if (deg[i] % 2 != 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                int start = 0;
                while (deg[start] == 0) {
                    start++;
                }
                stack.clear();
                toAnswer.clear();
                answer.clear();
                stack.add(start);
                while (!stack.isEmpty()) {
                    int v = stack.last();
                    if (g[v].isEmpty()) {
                        stack.popBack();
                        if (!toAnswer.isEmpty()) {
                            int x = toAnswer.popBack();
                            int y = toAnswer.popBack();
                            answer.add(x);
                            answer.add(y);
                        }
                    } else {
                        int edgeId = g[v].get(g[v].size() - 1);
                        g[v].remove(g[v].size() - 1);
                        if (usedEdge[edgeId]) {
                            continue;
                        }
                        usedEdge[edgeId] = true;
                        int idA = a[edgeId] & mask, idB = b[edgeId] & mask;
                        if (idA == v) {
                            toAnswer.add(edgeId * 2 + 1);
                            toAnswer.add(edgeId * 2 + 2);
                            stack.add(idB);
                        } else {
                            if (idB != v) {
                                throw new AssertionError();
                            }
                            toAnswer.add(edgeId * 2 + 2);
                            toAnswer.add(edgeId * 2 + 1);
                            stack.add(idA);
                        }
                    }
                }
                if (answer.sz != n * 2) {
                    ok = false;
                } else {
                    realAns = Arrays.copyOf(answer.a, answer.a.length);
                }
            }
            if (ok) {
//                System.err.println("!OK " + mid + " -> " + realAns + ", mask = " + mask);
                left = mid;
            } else {
                right = mid;
            }
        }
        check(realAns, a, b, left);
        out.println(left);
        for (int x : realAns) {
            out.print(x + " ");
        }
        out.println();
    }

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
        }
        solve(a, b);
    }

    int conv(int[] a, int[] b, int id) {
        return id % 2 == 1 ? a[id / 2] : b[(id - 1) / 2];
    }

    int ans(int xor) {
        if (xor == 0) {
            return 20;
        }
        for (int pw = 1; ; pw++) {
            if (xor % (1 << pw) != 0) {
                return pw - 1;
            }
        }
    }

    void check(int[] ans, int[] a, int[] b, int answer) {
        int myAns = 20;
        for (int i = 1; i + 1 < ans.length; i += 2) {
            int left = conv(a, b, ans[i]);
            int right = conv(a, b, ans[i + 1]);
            myAns = Math.min(myAns, ans(left ^ right));
        }
        myAns = Math.min(myAns, ans(conv(a, b, ans[0]) ^ conv(a, b, ans[ans.length - 1])));
        if (answer != myAns) {
            System.err.println("a = " + Arrays.toString(a));
            System.err.println("b = " + Arrays.toString(b));
            System.err.println(ans);
            throw new AssertionError("correct = " + myAns + ", predict = " + answer);
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
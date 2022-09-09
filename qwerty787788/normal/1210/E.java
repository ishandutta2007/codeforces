import java.io.*;
import java.util.*;

public class E {
    FastScanner in;
    PrintWriter out;

    int k;

    int[] ids;
    int[][] fromId;

    int read(int[] perm) {
        int res = 0;
        for (int x : perm) {
            res = res * 5 + x;
        }
        return res;
    }

    int tot;

    void go(int[] perm, boolean[] was, int pos) {
        if (pos == perm.length) {
            fromId[tot] = perm.clone();
            ids[read(perm)] = tot;
            tot++;
        } else {
            for (int i = 0; i < perm.length; i++) {
                if (!was[i]) {
                    perm[pos] = i;
                    was[i] = true;
                    go(perm, was, pos + 1);
                    was[i] = false;
                }
            }
        }
    }

    int[][] mul;

    void solve() {
        int n = in.nextInt();
        k = in.nextInt();
        int[] perm = new int[k];
        boolean[] was = new boolean[k];
        int expTotal = 1;
        for (int i = 1; i <= k; i++) {
            expTotal *= i;
        }
        ids = new int[5 * 5 * 5 * 5 * 5];
        fromId = new int[expTotal][];
        go(perm, was, 0);
//        System.err.println("tot = " + tot);
        mul = new int[tot][tot];
        for (int i = 0; i < tot; i++) {
            for (int j = 0; j < tot; j++) {
                int[] p1 = fromId[i];
                int[] p2 = fromId[j];
                mul[i][j] = ids[read(mul(p1, p2))];
            }
        }
//        for (int i = 0; i < tot; i++) {
//            System.err.println(Arrays.toString(mul[i]));
//        }
        boolean[] start = new boolean[tot];
        start[0] = true;
        State s = new State(start);
        rec(s, 0);
//        System.err.println("totalStates = " + hs.size());
        int[] firstPos = new int[tot];
        Arrays.fill(firstPos, n);
        int[] queue = new int[tot];
        int[] whereInQueue = new int[tot];
        for (int i = 0; i < tot; i++) {
            queue[i] = i;
            whereInQueue[i] = i;
        }
        int[][] go = new int[hs.size()][tot];
        int[] sz = new int[hs.size()];
        for (Map.Entry<State, Integer> entry : hs.entrySet()) {
//            System.err.println("id = " + entry.getValue() + " " +Arrays.toString(entry.getKey().was));
//            System.err.println(Arrays.toString(allStates.get(entry.getValue()).was));
            for (int i = 0; i < tot; i++) {
                go[entry.getValue()][i] = entry.getKey().next[i];
                if (entry.getKey().was[i]) {
                    sz[entry.getValue()]++;
                }
            }
        }
        long res = 0;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                perm[j] = in.nextInt() - 1;
            }
            a[i] = ids[read(perm)];
        }
//        System.err.println("!!!!!!!!!!!!!! " + hs.size());
//        System.err.println(Arrays.toString(a));
        for (int left = n - 1; left >= 0; left--) {
//            System.err.println("!!!  "+ a[left]);
            for (int pos = whereInQueue[a[left]]; pos > 0; pos--) {
                queue[pos] = queue[pos - 1];
                whereInQueue[queue[pos]] = pos;
            }
            queue[0] = a[left];
            whereInQueue[a[left]] = 0;
            firstPos[a[left]] = left;
            int myState = 0;
            int myPos = left;
            for (int i = 0; i < tot; i++) {
                int curPerm = queue[i];
//                System.err.println("check , perm = " + Arrays.toString(fromId[queue[i]]) + ", pos = " + firstPos[curPerm]);
                int nextState = go[myState][curPerm];
//                if (nextState != myState) {
//                    System.err.println(left + " " + myState + " " + nextState + " " + sz[nextState] + " " + myPos + ", add = " + sz[myState] * 1L * (firstPos[curPerm] - myPos));
//                }
                res += sz[myState] * 1L * (firstPos[curPerm] - myPos);
                myPos = firstPos[curPerm];
                myState = nextState;
            }
            res += sz[myState] * 1L * (n - myPos);
//            System.err.println("After left = " + left + "->" + res);
        }
        out.println(res);
    }

    void rec(State s, int yourId) {
        allStates.add(s);
        hs.put(s, yourId);
        s.next = new int[tot];
        for (int i = 0; i < tot; i++) {
            if (!s.was[i]) {
                State nextState = s.add(i);
                Integer go = hs.get(nextState);
                if (go == null) {
                    go = hs.size();
                    rec(nextState, go);
                }
                s.next[i] = go;
            } else {
                s.next[i] = yourId;
            }
        }
    }

    HashMap<State, Integer> hs = new HashMap<>();
    List<State> allStates = new ArrayList<>();

    class State {
        boolean[] was;
        int[] next;

        State add(int next) {
            boolean[] nextWas = was.clone();
            List<Integer> queue = new ArrayList<>();
            queue.add(next);
            nextWas[next] = true;
            while (queue.size() > 0) {
                int p = queue.get(queue.size() - 1);
                queue.remove(queue.size() - 1);
                for (int i = 0; i < tot; i++) {
                    if (nextWas[i]) {
                        int go = mul[i][p];
                        if (!nextWas[go]) {
                            nextWas[go] = true;
                            queue.add(go);
                        }
                    }
                }
            }
            return new State(nextWas);
        }

        public State(boolean[] was) {
            this.was = was;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            State state = (State) o;
            return Arrays.equals(was, state.was);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(was);
        }
    }

    int[] mul(int[] a, int[] b) {
        int[] r = new int[a.length];
        for (int i = 0; i < r.length; i++) {
            r[i] = a[b[i]];
        }
        return r;
    }

    void run() {
        try {
            in = new FastScanner(new File("E.in"));
            out = new PrintWriter(new File("E.out"));

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
        new E().runIO();
    }
}
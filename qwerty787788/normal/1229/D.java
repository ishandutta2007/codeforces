import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void genAllPerm(int[] a, int pos, boolean[] used) {
        if (pos == a.length) {
            Perm p = new Perm(a);
            p.id = allPerms.size();
            allPerms.add(p);
            ident.put(p, p);
            return;
        }
        for (int i = 0; i < used.length; i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            a[pos] = i;
            genAllPerm(a, pos + 1, used);
            used[i] = false;
        }
    }

    class BitSet {
        boolean[] a;

        boolean get(int x) {
            return a[x];
        }

        public BitSet(boolean[] a) {
            this.a = a.clone();
        }

        BitSet(int n) {
            a = new boolean[n];
        }

        void set(int x) {
            a[x] = true;
        }

        int cardinality() {
            int r = 0;
            for (boolean x : a) {
                if (x) {
                    r++;
                }
            }
            return r;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            BitSet bitSet = (BitSet) o;
            return Arrays.equals(a, bitSet.a);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(a);
        }
    }

    void solve() {
        int len = in.nextInt();
        int n = in.nextInt();
        long START = System.currentTimeMillis();
        genAllPerm(new int[n], 0, new boolean[n]);
        applyPerm = new int[allPerms.size()][allPerms.size()];
        for (int i = 0; i < allPerms.size(); i++) {
            for (int j = 0; j < allPerms.size(); j++) {
                applyPerm[i][j] = allPerms.get(i).apply(allPerms.get(j)).id;
            }
        }
        BitSet startExist = new BitSet(allPerms.size());
        startExist.set(0);
        State start = new State(startExist, allPerms.size());
        identState.put(start, start);
        allStates.add(start);
        for (int it = 0; it < allStates.size(); it++) {
            State s = allStates.get(it);
            s.next = new int[allPerms.size()];
            for (int i = 0; i < allPerms.size(); i++) {
                State checkNext = s.getNext(allPerms.get(i));
                if (identState.containsKey(checkNext)) {
                    checkNext = identState.get(checkNext);
                } else {
                    identState.put(checkNext, checkNext);
                    checkNext.id = allStates.size();
                    allStates.add(checkNext);
                }
                s.next[i] = checkNext.id;
            }
        }
//        System.err.println("all size = " + allStates.size());
        System.err.println(System.currentTimeMillis() - START);
        int[] perms = new int[len];
        for (int i = 0; i < len; i++) {
            int[] t = new int[n];
            for (int j = 0; j < t.length; j++) {
                t[j] = in.nextInt() - 1;
            }
            perms[i] = ident.get(new Perm(t)).id;
        }
        int[] closestPos = new int[allPerms.size() + 1];
        Arrays.fill(closestPos, len);
        int[] queue = new int[allPerms.size() + 1];
        for (int i = 0; i < queue.length; i++) {
            queue[i] = i;
        }
        long result = 0;
        int[] precCnt = new int[allStates.size()];
        for (int i = 0; i < precCnt.length; i++) {
            precCnt[i] = allStates.get(i).cnt;
        }
        int[][] precNext = new int[allStates.size()][allPerms.size()];
        for (int i = 0; i < precNext.length; i++) {
            for (int j = 0; j < precNext[i].length; j++) {
                precNext[i][j] = allStates.get(i).next[j];
            }
        }
        for (int left = len - 1; left >= 0; left--) {
            closestPos[perms[left]] = left;
            int id = perms[left];
            int pos = -1;
            for (int i = 0; i < queue.length; i++) {
                if (queue[i] == id) {
                    pos = i;
                    break;
                }
            }
            for (int i = pos; i > 0; i--) {
                queue[i] = queue[i - 1];
            }
            queue[0] = id;
            int stateId = 0;
            int curTill = left;
            for (int i = 0; i < queue.length; i++) {
                int permId = queue[i];
                int nextPos = closestPos[permId];
                result += (nextPos - curTill) * precCnt[stateId];
                curTill = nextPos;
                if (curTill != len) {
                    stateId = precNext[stateId][permId];
                } else {
                    break;
                }
            }
        }
        out.println(result);
    }

    int[][] applyPerm;

    class State {
        BitSet exist;
        int sz;
        int id;
        int[] next;
        int cnt;

        public State(BitSet exist, int sz) {
            this.exist = exist;
            cnt = exist.cardinality();
            this.sz = sz;
        }

        State getNext(Perm p) {
            BitSet nextExist = new BitSet(exist.a);
            nextExist.set(p.id);
            while (true) {
                boolean ch = false;
                for (int i = 0; i < sz; i++) {
                    if (nextExist.get(i)) {
                        for (int j = 0; j < sz; j++) {
                            if (nextExist.get(j)) {
                                int to = applyPerm[i][j];
                                if (!nextExist.get(to)) {
                                    nextExist.set(to);
                                    ch = true;
                                }
                            }
                        }
                    }
                }
                if (!ch) {
                    break;
                }
            }
            return new State(nextExist, sz);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            State state = (State) o;
            return sz == state.sz &&
                    Objects.equals(exist, state.exist);
        }

        @Override
        public int hashCode() {
            return Objects.hash(exist, sz);
        }
    }

    Map<Perm, Perm> ident = new HashMap<>();
    Map<State, State> identState = new HashMap<>();
    List<Perm> allPerms = new ArrayList<>();
    List<State> allStates = new ArrayList<>();

    class Perm {
        int[] a;
        int id;

        public Perm(int[] a) {
            this.a = a.clone();
        }

        Perm apply(Perm another) {
            int[] res = new int[a.length];
            for (int i = 0; i < another.a.length; i++) {
                res[i] = a[another.a[i]];
            }
            return ident.get(new Perm(res));
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Perm perm = (Perm) o;
            return Arrays.equals(a, perm.a);
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(a);
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
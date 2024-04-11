import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class Change implements Comparable<Change> {
        int value;
        int type; // -1 ,  + 1
        int time;

        public Change(int value, int type, int time) {
            this.value = value;
            this.type = type;
            this.time = time;
        }

        @Override
        public int compareTo(Change o) {
            if (value != o.value) {
                return Integer.compare(value, o.value);
            }
            if (type != o.type) {
                return -Integer.compare(type, o.type);
            }
            return Integer.compare(time, o.time);
        }
    }

    class Murena implements Comparable<Murena> {
        int fromT, toT, value, id;

        public Murena(int fromT, int toT, int value, int id) {
            if (fromT > toT) {
                throw new AssertionError();
            }
            this.fromT = fromT;
            this.toT = toT;
            this.value = value;
            this.id = id;
        }

        @Override
        public int compareTo(Murena o) {
            if (value != o.value) {
                return Integer.compare(value, o.value);
            }
            return 0;
        }

        @Override
        public String toString() {
            return "Murena{" +
                    "fromT=" + fromT +
                    ", toT=" + toT +
                    ", value=" + value +
                    ", id=" + id +
                    '}';
        }
    }

    void solve() {
        int q = in.nextInt();
        Change[] changes = new Change[q];
        for (int i = 0; i < q; i++) {
            if (in.next().equals("+")) {
                changes[i] = new Change(in.nextInt(), 1, i);
            } else {
                changes[i] = new Change(in.nextInt(), -1, i);
            }
        }
        Arrays.sort(changes);
        List<Murena> murenas = new ArrayList<>();
        for (int i = 0; i < q; ) {
            int j = i;
            while (j != q && changes[i].value == changes[j].value && changes[i].type == changes[j].type) {
                j++;
            }
            int k = j;
            while (k != q && changes[i].value == changes[k].value) {
                k++;
            }
            int stJ = j;
            while (j < k) {
                murenas.add(new Murena(changes[i].time, changes[j].time - 1, changes[i].value, -1));
                i++;
                j++;
            }
            if (i > stJ) {
                throw new AssertionError();
            }
            while (i < stJ) {
                murenas.add(new Murena(changes[i].time, q - 1, changes[i].value, -1));
                i++;
            }
            i = k;
        }
        Collections.sort(murenas);
        for (int i = 0; i < murenas.size(); i++) {
            murenas.get(i).id = i;
        }
//        System.err.println(murenas);
        int[] ans = new int[q];
        go(0, q - 1, murenas, 0, new Fenwick(murenas.size()), new TreeSet<>(), ans, murenas);
        for (int i = 0; i < q; i++) {
            out.println(ans[i]);
        }
    }

    void go(int leftTime, int rightTime, List<Murena> murenas, int cntMurenas, Fenwick fenw, TreeSet<Integer> bigMurenas, int[] ans, List<Murena> allMurenas) {
        List<Murena> nextMurenas = new ArrayList<>();
        List<Integer> addBack = new ArrayList<>();
        List<Integer> removeFrom = new ArrayList<>();
        List<Murena> removeFromFenw = new ArrayList<>();
//        System.err.println("time = " + leftTime + " .. " + rightTime + ", murenas = " + murenas);
        for (Murena m : murenas) {
            if (m.toT < leftTime || m.fromT > rightTime) {
                continue;
            }
            if (m.fromT <= leftTime && m.toT >= rightTime) {
                fenw.upd(m.id, m.value);
//                System.err.println("ADD " + m.value + ", sum =  " + fenw.get(m.id - 1));
                if (fenw.get(m.id - 1) * 2 < m.value) {
                    bigMurenas.add(m.id);
                    removeFrom.add(m.id);
                }
                removeFromFenw.add(m);
                List<Integer> check = new ArrayList<>(bigMurenas);
                for (int next : check) {
                    long sum = fenw.get(next - 1);
                    if (sum * 2 < allMurenas.get(next).value) {
                        continue;
                    }
                    bigMurenas.remove(next);
                    addBack.add(next);
                }
                cntMurenas++;
            } else {
                nextMurenas.add(m);
            }
        }
        if (leftTime == rightTime) {
//            System.err.println("time = " + leftTime + ", cnt = " + cntMurenas + " , big = " + bigMurenas);
            ans[leftTime] = cntMurenas - bigMurenas.size();
        } else {
            int mid = (leftTime + rightTime) >> 1;
            go(leftTime, mid, nextMurenas, cntMurenas, fenw, bigMurenas, ans, allMurenas);
            go(mid + 1, rightTime, nextMurenas, cntMurenas, fenw, bigMurenas, ans, allMurenas);
        }
        for (int i : removeFrom) {
            bigMurenas.remove(i);
        }
        for (int i : addBack) {
            bigMurenas.add(i);
        }
        for (Murena m : removeFromFenw) {
            fenw.upd(m.id, -m.value);
        }
    }

    class Fenwick {
        long[] sum;

        Fenwick(int n) {
            sum = new long[n];
        }

        long get(int r) {
            long res = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1) {
                res += sum[r];
            }
            return res;
        }

        void upd(int pos, long delta) {
            for (; pos < sum.length; pos |= pos + 1) {
                sum[pos] += delta;
            }
        }
    }

    void solve123() {
        int q = in.nextInt();
        List<Integer> all = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            if (in.next().equals("+")) {
                all.add(in.nextInt());
            } else {
                Integer z = in.nextInt();
                all.remove(z);
            }
            Collections.sort(all);
            int sum = 0;
            int res = 0;
            for (int z : all) {
                if (sum * 2 >= z) {
                    res++;
                }
                sum += z;
            }
            System.err.println(all + " " + res);
            out.println(res);
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
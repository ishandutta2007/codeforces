import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class C implements Comparable<C> {
        int type;
        int need;

        public C(int type, int need) {
            super();
            this.type = type;
            this.need = need;
        }

        @Override
        public int compareTo(C o) {
            return Integer.compare(need, o.need);
        }

    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        boolean[] type = new boolean[n];
        int[] arm = new int[n];
        // true - atack
        for (int i = 0; i < n; i++) {
            String s = in.next();
            if (s.equals("ATK"))
                type[i] = true;
            arm[i] = in.nextInt();
        }
        int[] arm2 = new int[m];
        for (int i = 0; i < m; i++) {
            arm2[i] = in.nextInt();
        }
        long best = 0;
        ArrayList<C> need = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (type[i]) {
                need.add(new C(1, arm[i]));
            } else {
                need.add(new C(0, arm[i] + 1));
            }
        }
        Collections.sort(need);
        boolean[] used = new boolean[m];
        boolean ok = true;
        for (int type1 = 0; type1 < 2; type1++) {
            for (int i = 0; i < need.size(); i++) {
                boolean needType = type1 == 0 ? false : true;
                boolean curType = need.get(i).type == 1 ? true : false;
                if (curType != needType)
                    continue;
                int best1 = -1;
                int min = Integer.MAX_VALUE;
                for (int j = 0; j < m; j++)
                    if (!used[j])
                        if (arm2[j] >= need.get(i).need)
                            if (arm2[j] < min) {
                                best1 = j;
                                min = arm2[j];
                            }
                if (best1 == -1) {
                    ok = false;
                    break;
                } else {
                    used[best1] = true;
                    if (curType) {
                        best += arm2[best1] - need.get(i).need;
                    }
                }
            }
            if (!ok)
                break;
        }
        if (!ok) {
            best = 0;
        } else {
            for (int i = 0; i < m; i++)
                if (!used[i])
                    best += arm2[i];
        }
        ArrayList<Integer> atack = new ArrayList<>();
        for (int i = 0; i < n; i++)
            if (type[i])
                atack.add(arm[i]);
        Collections.sort(atack);
        Arrays.sort(arm2);
        for (int sz = 1; sz <= atack.size(); sz++) {
            int fr = m - sz;
            if (fr < 0)
                break;
            boolean okay = true;
            for (int i = 0; i < sz; i++) {
                if (arm2[fr + i] < atack.get(i))
                    okay = false;
            }
            if (okay) {
                long cost = 0;
                for (int i = 0; i < sz; i++)
                    cost += arm2[fr + i] - atack.get(i);
                best = Math.max(best, cost);
            }
        }
        out.println(best);
    }

    void run() {
        try {
            in = new FastScanner(new File("object.in"));
            out = new PrintWriter(new File("object.out"));

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
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}
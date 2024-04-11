import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class C {

    class Segment implements Comparable<Segment> {
        int l, r;
        double p;
        boolean leaf = true;
        Segment parent;
        List<Val> vals = new ArrayList<Val>();

        public int compareTo(Segment o) {
            if (r == o.r) {
                return o.l - l;
            } else {
                return r - o.r;
            }
        }
    }

    class Val {
        int max;
        double p;

        public Val(int max, double p) {
            this.max = max;
            this.p = p;
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        int q = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Segment[] w = new Segment[q + 1];
        for (int i = 0; i < q; i++) {
            w[i] = new Segment();
            w[i].l = nextInt() - 1;
            w[i].r = nextInt();
            w[i].p = Double.parseDouble(next());
        }
//        for (int i = 0; i < n; i++) {
//            w[q + i] = new Segment();
//            w[q + i].l = i;
//            w[q + i].r = i + 1;
//        }
        w[q] = new Segment();
        w[q].l = 0;
        w[q].r = n;
        q++;
        Arrays.sort(w);
        Segment[] p = new Segment[q];
        int pn = 0;
        Segment[] c = new Segment[q];
        int cn = 0;
        for (int i = 0; i < q; i++) {
            Val val = new Val(0, 1);
            int r = w[i].r;
            while (pn > 0 && p[pn - 1].l >= w[i].l) {
                for (int j = p[pn - 1].r; j < r; j++) {
                    val.max = Math.max(val.max, a[j]);
                }
                r = p[pn - 1].l;
                p[pn - 1].parent = w[i];
                c[cn++] = p[pn - 1];
                pn--;
            }
            for (int j = w[i].l; j < r; j++) {
                val.max = Math.max(val.max, a[j]);
            }
            w[i].vals.add(val);
            p[pn++] = w[i];
        }
        if (pn != 1) {
            throw new RuntimeException();
        }
        for (int i = 0; i < cn; i++) {
            Segment s = c[i];
            List<Val> z = new ArrayList<Val>();
            for (Val val : s.vals) {
                z.add(new Val(val.max + 1, val.p * s.p));
                val.p *= (1 - s.p);
            }
            s.vals = merge(s.vals, z);
            s.parent.vals = combine(s.parent.vals, s.vals);
            s.parent.vals = compress(s.parent.vals);
        }
        Segment root = p[0];
        double res = 0;
        for (Val val : root.vals) {
            res += val.max * val.p;
        }
        out.println(res);
    }

    private List<Val> compress(List<Val> vals) {
        List<Val> res = new ArrayList<Val>();
        for (Val val : vals) {
            if (res.size() > 0 && res.get(res.size() - 1).max == val.max) {
                res.get(res.size() - 1).p += val.p;
            } else if (val.p > 0) {
                res.add(val);
            }
        }
        return res;
    }

    private List<Val> merge(List<Val> a, List<Val> b) {
        List<Val> res = new ArrayList<Val>(0);
        int i = 0, j = 0;
        Val last = null;
        while (i < a.size() || j < b.size()) {
            if (j == b.size() || i < a.size() && a.get(i).max > b.get(j).max) {
                if (last != null && last.max == a.get(i).max) {
                    last.p += a.get(i).p;
                } else {
                    last = a.get(i);
                    res.add(last);
                }
                i++;
            } else {
                if (last != null && last.max == b.get(j).max) {
                    last.p += b.get(j).p;
                } else {
                    last = b.get(j);
                    res.add(last);
                }
                j++;
            }
        }
        return res;
    }

    private List<Val> combine(List<Val> a, List<Val> b) {
        List<Val> res = new ArrayList<Val>(0);
        int i = 0, j = 0;
        double sa = 1, sb = 1;
        Val last = null;
        while (i < a.size() || j < b.size()) {
            if (j == b.size() || i < a.size() && a.get(i).max > b.get(j).max) {
                sa -= a.get(i).p;
                if (last != null && last.max == a.get(i).max) {
                    last.p += a.get(i).p * sb;
                } else {
                    last = a.get(i);
                    last.p *= sb;
                    res.add(last);
                }
                i++;
            } else {
                sb -= b.get(j).p;
                if (last != null && last.max == b.get(j).max) {
                    last.p += b.get(j).p * sa;
                } else {
                    last = b.get(j);
                    last.p *= sa;
                    res.add(last);
                }
                j++;
            }
        }
        return res;
    }


    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}
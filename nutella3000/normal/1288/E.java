import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, m;
    static int min[], max[];
    static ArrayList<pair> line = new ArrayList<>();
    static int p[];

    static void scan() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        min = new int [n];
        max = new int [n];
        for(int i = 0;i < n;i++) {
            min[i] = i;
            max[i] = i;
        }
        p = new int [m];
        for(int i = 0;i < m;i++) {
            p[i] = sc.nextInt() - 1;
            min[p[i]] = 0;
        }

        int last[] = new int [n];
        for(int i = 0;i < n;i++) last[i] = 0;
        segment_tree temp = new segment_tree(n);

        for(int i = 0;i <= m;i++) {
            if (i == m) {
                for(int j = 0;j < n;j++) {
                    if (last[j] == 0) max[j] += temp.get(n - 1) - temp.get(j);
                    else if (last[j] <= m - 1)
                        line.add(new pair(last[j], m - 1, j));
                }
                break;
            }

            if (last[p[i]] == 0) {
                max[p[i]] += temp.get(n - 1) - temp.get(p[i]);
            }else if (last[p[i]] <= i - 1)
                line.add(new pair(last[p[i]], i - 1, p[i]));

            if (last[p[i]] == 0)
                temp.add(i, p[i]);
            last[p[i]] = i + 1;

        }

        Collections.sort(line, new Comparator<pair>() {
            @Override
            public int compare(pair o1, pair o2) {
                return -Integer.compare(o1.l, o2.l);
            }
        });
    }

    static void solve() throws IOException {
        scan();
        segment_tree a = new segment_tree(m);
        int id = m - 1;
        for(pair v : line) {
            while(id >= v.l) {
                a.add(p[id], id);
                id--;
            }

            int cnt = a.get(v.r);
            //if (v.l == 0) cnt += v.id;
            max[v.id] = Math.max(max[v.id], cnt);
        }

        for(int i = 0;i < n;i++) {
            pw.println(min[i] + 1 + " " + (max[i] + 1));
        }
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}

class pair {
    int l, r, id;
    pair(int l, int r, int id) {
        this.l = l;
        this.r = r;
        this.id = id;
    }

    pair() {}
}

class segment_tree {
    int sum[], last;
    TreeMap<Integer, Integer> val = new TreeMap<>();

    segment_tree(int n) {
        sum = new int [4 * n];
        last = n - 1;
    }

    void add(int x, int id) {
        if (val.containsKey(x)) {
            add(0, 0, last, val.get(x), -1);
            val.remove(x);
        }
        add(0, 0, last, id, 1);
        val.put(x, id);
    }

    void add(int v, int l, int r, int id, int add) {
        if (l > id || r < id) return;
        if (l == id && r == id) {
            sum[v] += add;
            return;
        }
        int m = ((l + r) >> 1);
        add(v * 2 + 1, l, m, id, add);
        add(v * 2 + 2, m + 1, r, id, add);
        sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
    }

    int get(int pref) {
        if (pref == -1) return 0;
        return get(0, 0, last, pref);
    }

    int get(int v, int l, int r, int right) {
        if (l > right) return 0;
        if (r <= right) return sum[v];
        int m = ((l + r) >> 1);
        return get(v * 2 + 1, l, m, right) + get(v * 2 + 2, m + 1, r, right);
    }

}
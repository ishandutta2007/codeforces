import java.io.*;
import java.util.*;

public class Main {
    static int n, m, p;
    static pair sword[], brone[];
    static triple mon[];
    static int ans = -2000000000;
    static segment_tree shit;

    static void scan() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        p = sc.nextInt();
        sword = new pair[n];
        brone = new pair[m];
        mon = new triple[p];
        for(int i = 0;i < n;i++)    sword[i] = new pair(sc.nextInt(), sc.nextInt());
        for(int i = 0;i < m;i++) brone[i] = new pair(sc.nextInt(), sc.nextInt());
        for(int i = 0;i < p;i++) mon[i] = new triple(sc.nextInt(), sc.nextInt(), sc.nextInt());

        Arrays.sort(sword, new pair());
        Arrays.sort(brone, new pair());
        Arrays.sort(mon, new Comparator<triple>() {
            @Override
            public int compare(triple o1, triple o2) {
                return Integer.compare(o1.a, o2.a);
            }
        });


        for(int i = n - 2;i >= 0;i--) sword[i].b = Math.min(sword[i].b, sword[i + 1].b);
        for(int i = m - 2;i >= 0;i--) brone[i].b = Math.min(brone[i].b, brone[i + 1].b);

        TreeMap<Integer, Integer> temp = new TreeMap<>();
        for(int i = 0;i < m;i++) {
            if (!temp.containsKey(brone[i].a)) temp.put(brone[i].a, i);
        }

        for(int i = 0;i < p;i++) {
            if (temp.higherKey(mon[i].b) == null) mon[i].b = m;
            else mon[i].b = temp.higherEntry(mon[i].b).getValue();
        }

        int temp1[] = new int [m];
        for(int i = 0;i < m;i++) temp1[i] = -brone[i].b;

        shit = new segment_tree(temp1);
    }

    static void solve() throws IOException {
        scan();
        int id = 0;
        ans = shit.get() - (sword[0].b);
        for(int i = 0;i < p;i++) {
            while(id < n && sword[id].a <= mon[i].a) id++;
            if (id == n) break;
            shit.add(mon[i].b, mon[i].c);

            int new_ans = shit.get() - sword[id].b;
            ans = Math.max(ans, new_ans);
        }

        pw.println(ans);

    }



    public static void main(String[] args) throws IOException {
        sc = new Fast_Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();
        pw.close();
    }


    static Fast_Scanner sc;
    static PrintWriter pw;

    static class Fast_Scanner {
        static BufferedReader br;
        static StringTokenizer st = new StringTokenizer("");

        Fast_Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Fast_Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        Double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }


}


class segment_tree {
    int max[];
    int push[];
    int last;

    segment_tree(int b[]) {
        int n = b.length;
        last = n - 1;
        max = new int [4 * n];
        push = new int [4 * n];
        build(0, 0, last, b);
    }

    void build(int v, int l, int r, int b[]) {
        if (l == r) {
            max[v] = b[l];
            return;
        }
        int m = ((l + r) >> 1);
        build(v * 2 + 1, l, m, b);
        build(v * 2 + 2, m + 1, r, b);
        max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
    }

    void push(int v) {
        max[v * 2 + 1] += push[v];
        max[v * 2 + 2] += push[v];
        push[v * 2 + 1] += push[v];
        push[v * 2 + 2] += push[v];
        push[v] = 0;
    }

    void upd(int v) {
        max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
    }

    void add(int l, int x) {
        add(0, 0, last, l, last, x);
    }

    void add(int v, int l, int r, int left, int right, int x) {
        if (l > right || r < left) return;
        if (l >= left && r <= right) {
            max[v] += x;
            push[v] += x;
            return;
        }
        push(v);
        int m = ((l + r) >> 1);
        add(v * 2 + 1, l, m, left, right, x);
        add(v * 2 + 2, m + 1, r, left, right, x);
        upd(v);
    }

    int get() {
        return max[0];
    }
}

class pair implements Comparator<pair>{
    int a, b;
    pair(int a, int b) {
        this.a = a;
        this.b = b;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.a, o2.a);
    }
}

class triple {
    int a, b, c;
    triple(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    triple() {}
}
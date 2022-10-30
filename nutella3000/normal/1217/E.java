import sun.reflect.generics.tree.Tree;

import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int p[] = new int [11];
    static boolean check(int a, int b) {
        for(int i = 0;i < 10;i++) {
            if ((a % p[i + 1] / p[i]) != 0 && (b % p[i + 1] / p[i]) != 0) return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        p[0] = 1;
        for(int i = 1;i < 10;i++) p[i] = p[i - 1] * 10;
        p[10] = inf;
        int n = nextInt();
        int m = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        segment_tree b = new segment_tree(a);
        while(m-- > 0) {
            int t = nextInt();
            if (t == 1) {
                int id = nextInt() - 1;
                int x = nextInt();
                b.set(id, x);
            }else{
                int l = nextInt() - 1;
                int r = nextInt() - 1;
                ArrayList<Integer> one = b.get(l, r);
                int min[] = new int [10];
                for(int i = 0; i < 10;i++) min[i] = inf;
                for(int i : one) {
                    int id = 11;
                    for(int j = 9;j >= 0;j--) {
                        if (min[j] > i) id = j;
                    }
                    for(int j = 9;j > id;j--) {
                        min[j] = min[j - 1];
                    }
                    if (id != 11) min[id] = i;
                }
                int ans = inf * 2;
                for(int i = 0;i < 10;i++) {
                    for(int j = i + 1;j < 10;j++) {
                        if (min[j] == inf) continue;
                        if (check(min[i], min[j]) && ans > min[i] + min[j]) ans = min[i] + min[j];
                    }
                }
                if (ans == inf * 2) pw.println(-1);
                else pw.println(ans);
            }

        }

        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}

class segment_tree {
    int min[][], last;
    static int inf = (int) 1e9 + 7;
    segment_tree(int a[]) {
        int n = a.length;
        last = n - 1;
        min = new int [10][4 * n];
        for(int i = 0;i < 10;i++) {
            for(int j = 0;j < 4 * n;j++) {
                min[i][j] = inf;
            }
        }
        build(0, 0, last, a);
    }

    void build(int v, int l, int r, int a[]) {
        if (l == r) {
            min[0][v] = a[l];
            return;
        }
        int m = ((l + r) >> 1);
        build(v * 2 + 1, l, m, a);
        build(v * 2 + 2, m + 1, r, a);
        merge(v);
    }

    void merge(int v) {
        int l = v * 2 + 1;
        int r = v * 2 + 2;
        int id_l = 0, id_r = 0, id = 0;
        while(id != 10) {
            if (min[id_l][l] < min[id_r][r]) {
                min[id][v] = min[id_l][l];
                id_l++;
            }else{
                min[id][v] = min[id_r][r];
                id_r++;
            }
            id++;
        }
    }

    void set(int id, int x) {
        set(0, 0, last, id, x);
    }

    void set(int v, int l, int r, int id, int x) {
        if (l > id || r < id) return;
        if (l == id && r == id) {
            min[0][v] = x;
            return;
        }
        int m = ((l + r) >> 1);
        set(v * 2 + 1, l, m, id, x);
        set(v * 2 + 2, m + 1, r, id, x);
        merge(v);
    }

    static ArrayList<Integer> get_ans = new ArrayList<>();

    ArrayList<Integer> get(int l, int r) {
        get_ans.clear();
        get(0, 0, last, l, r);
        return get_ans;
    }

    void get(int v, int l, int r, int left, int right) {
        if (l > right || r < left) return;
        if (l >= left && r <= right) {
            for(int i = 0;i < 10;i++) get_ans.add(min[i][v]);
            return;
        }
        int m = ((l + r) >> 1);

        get(v * 2 + 1, l, m, left, right);
        get(v * 2 + 2, m + 1, r, left, right);
    }
}
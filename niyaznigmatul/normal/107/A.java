import java.util.Scanner;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    static class DSU {
        int[] p;
        int[] r;
        int[] got;

        public DSU(int n) {
            p = new int[n];
            r = new int[n];
            got = new int[n];
            Arrays.fill(got, Integer.MAX_VALUE);
            clear();
        }

        void clear() {
            for (int i = 0; i < p.length; i++) {
                p[i] = i;
                r[i] = 0;
            }
        }

        int get(int x) {
            return x == p[x] ? x : (p[x] = get(p[x]));
        }

        boolean union(int x, int y, int c) {
            x = get(x);
            y = get(y);
            if (x == y) {
                return false;
            }
            c = Math.min(c, got[y]);
            c = Math.min(c, got[x]);
            if (r[x] >= r[y]) {
                if (r[x] == r[y]) {
                    r[x]++;
                }
                p[y] = x;
            } else {
                p[x] = y;
            }
            got[get(x)] = c;
            return true;
        }
    }


    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        DSU dsu = new DSU(n);
        int[] deg = new int[n];
        int[] deg1 = new int[n];
        int[] deg2 = new int[n];
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int w = in.nextInt();
            deg[from]++;
            deg[to]++;
            deg1[from]++;
            deg2[to]++;
            dsu.union(from, to, w);
        }
        int[] got1 = new int[n];
        int[] got2 = new int[n];
        Arrays.fill(got1, -1);
        Arrays.fill(got2, -1);
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                int j = dsu.get(i);
                if (deg1[i] == 0) {
                    got1[j] = i;
                } else {
                    got2[j] = i;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (got1[i] >= 0) {
                count++;
            }
        }
        out.println(count);
        List<Answer> ans = new ArrayList<Answer>();
        for (int i = 0; i < n; i++) {
            if (got1[i] >= 0) {
                ans.add(new Answer(1 + got2[i], 1 + got1[i], dsu.got[i]));
            }
        }
        Collections.sort(ans);
        for (Answer e : ans) {
            out.println(e.a + " " + e.b + " " + e.c);
        }
    }

    static class Answer implements Comparable<Answer> {
        int a;
        int b;
        int c;

        Answer(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }


        public int compareTo(Answer o) {
            return a - o.a;
        }
    }
}
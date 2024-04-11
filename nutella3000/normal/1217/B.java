import sun.reflect.generics.tree.Tree;

import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = nextInt();
        while(t-- > 0) {
            int n = nextInt();
            int x = nextInt();
            int max_d = -123;
            int max_a = -123;
            for(int i = 0;i < n;i++) {
                int vd = nextInt();
                int vh = nextInt();
                if(vd > max_d) max_d = vd;
                if (vd - vh > max_a) max_a = vd - vh;
            }
            x -= max_d;
            if (max_a <= 0 && x > 0) pw.println(-1);
            else {
                if (x <= 0) pw.println(1);
                else pw.println(1 + (x + max_a - 1) / max_a);
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
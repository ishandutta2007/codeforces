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
            char h[] = next().toCharArray();
            int ans = 0;
            int l_zero[] = new int [h.length];
            for(int right = 0;right < h.length;right++) {
                if (h[right] == '0') {
                    if (right == 0) l_zero[right] = 1;
                    else l_zero[right] = 1 + l_zero[right - 1];
                }
                int v = right;
                int a = 0;
                while(v != -1 && right - v < 30) {
                    a += (1 << (right - v)) * (h[v] - '0');
                    if (a == right - v + 1) ans++;
                    v--;
                }
                if (v != -1 && l_zero[v] + right - v >= a && right - v < a) ans++;
            }
            pw.println(ans);
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
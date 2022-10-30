import sun.reflect.generics.tree.Tree;

import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        char h[] = next().toCharArray();
        int ans = 0;
        int min = 1;
        int max = 0;
        for(int i = 0;i < n;i++) {
            if (h[i] == '(') ans++;
            else ans--;
            min = Math.min(min, ans);
            max = Math.max(max, ans);
        }
        if (ans == 0 && min >= -1) pw.println("Yes");
        else pw.println("No");
        //pw.println(ans);
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
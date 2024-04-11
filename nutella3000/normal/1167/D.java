import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    static ArrayList<Integer> gr[];
    static int comp[];
    static void dfs(int v, int k) {
        if (comp[v] != 0) return;
        comp[v] = k;
        for(int i : gr[v]) dfs(i, k);
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        char h[] = next().toCharArray();
        int cnt1 = 0;
        int cnt2 = 0;
        int ans[] = new int [n];
        for(int i = 0;i < n;i++) {
            if (h[i] == '(') {
                if (cnt1 < cnt2) {
                    ans[i] = 1;
                    cnt1++;
                }else cnt2++;
            }else{
                if (cnt1 < cnt2) cnt2--;
                else{
                    cnt1--;
                    ans[i] = 1;
                }
            }
        }
        for(int i : ans) pw.print(i);
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
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, next[], ans[], max_id[];
    static int k;
    static int cnt_of_bred = 0;
    static boolean can = true;
    static void f(int v) {
        if (ans[v] != 0) return;
        cnt_of_bred++;
        if (cnt_of_bred > n) {
            can = false;
            return;
        }
        if (next[v] != -1 && next[v] != n) {
            f(next[v]);
        }
        if(max_id[v] != -1) {
            f(max_id[v]);
        }
        ans[v] = k;
        k--;
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = nextInt();
        while(t-- > 0) {
            cnt_of_bred = 0;
            can = true;
            n = nextInt();
            next = new int [n];
            ans = new int [n];
            max_id = new int [n];
            for(int i = 0;i < n;i++) max_id[i] = -1;
            k = n;
            for(int i = 0;i < n;i++) {
                next[i] = nextInt() - 1;
                if (next[i] == -2) next[i] = -1;
            }
            Deque<Integer> id = new ArrayDeque<>();
            id.add(0);
            for(int i = 1;i < n;i++) {
                while(!id.isEmpty()) {
                    if (next[id.getLast()] > i) break;
                    id.removeLast();
                }
                if (!id.isEmpty()) max_id[i] = id.getLast();
                while(!id.isEmpty()) {
                    if (next[id.getLast()] > next[i]) break;
                    id.removeLast();
                }
                id.add(i);
            }
            for(int i = 0;i < n;i++) f(i);
            if (!can) pw.println(-1);
            else {
                for (int i = 0; i < n; i++) pw.print(ans[i] + " ");
                pw.println();
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
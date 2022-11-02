import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int T = nextInt();
        while(T-- > 0) {
            int n = nextInt();
            int m = nextInt();
            ArrayList<Integer> ans1 = new ArrayList<>();
            boolean used[] = new boolean[n * 3];
            for(int i = 0;i < m;i++) {
                int v = nextInt() - 1;
                int u = nextInt() - 1;
                if (!used[v] && !used[u]) {
                    used[v] = true;
                    used[u] = true;
                    ans1.add(i + 1);
                }
            }
            if (ans1.size() >= n) {
                pw.println("Matching");
                int cnt = 0;
                for(int i : ans1) {
                    pw.print(i + " ");
                    cnt++;
                    if (cnt == n) break;
                }
                pw.println();
            }else{
                pw.println("IndSet");
                int cnt = 0;
                for(int i = 0;i < 3 * n;i++) {
                    if (!used[i]) {
                        cnt++;
                        pw.print(i + 1 + " ");
                    }
                    if (cnt == n) break;
                }
                pw.println();
            }
        }
        pw.close();
    }

    static BufferedReader br;

    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;
    /*static String next() throws IOException {
        int c = br.read();
        while (Character.isWhitespace(c)) c = br.read();
        StringBuilder sb = new StringBuilder();
        while (!Character.isWhitespace(c)) {
            sb.appendCodePoint(c);
            c = br.read();
        }
        return sb.toString();
    }*/

    static String next() throws IOException {
        if (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static Double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
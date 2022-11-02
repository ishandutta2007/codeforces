import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        int a[] = new int [k];
        for(int i = 0;i < k;i++) a[i] = nextInt();
        ArrayList<Integer> id[] = new ArrayList[n + 1];
        for(int i = 0;i <= n;i++) id[i] = new ArrayList<>();
        for(int i = 0;i < k;i++) {
            id[a[i]].add(i);
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            if (i > 1) {
                if (id[i].isEmpty() || id[i - 1].isEmpty() || id[i - 1].get(id[i - 1].size() - 1) < id[i].get(0)) ans++;
            }
            if (i < n) {
                if (id[i].isEmpty() || id[i + 1].isEmpty() || id[i + 1].get(id[i + 1].size() - 1) < id[i].get(0)) ans++;
            }
            if (id[i].isEmpty()) ans++;
        }
        pw.println(ans);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

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
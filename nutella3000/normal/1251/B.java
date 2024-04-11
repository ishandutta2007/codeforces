
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;



    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            char h[][] = new char[n][];
            int cnt[] = new int [2];
            for(int i = 0;i < n;i++) {
                h[i] = sc.next().toCharArray();
                for(int j = 0;j < h[i].length;j++) {
                    cnt[h[i][j] - '0']++;
                }
            }
            int ans = 0;
            int c = 0;
            for(int i = 0;i < n;i++) {
                if (h[i].length % 2 == 1) c++;
            }
            int c1 = (cnt[0] % 2) + cnt[1] % 2;
            if (c1 % 2 == c % 2 && c >= c1) pw.println(n);
            else pw.println(n - 1);
        }
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}

class dsu {
    int parent[];
    dsu(int n) {
        parent = new int [n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int get(int v) {
        if (v == parent[v]) return v;
        return parent[v] = get(parent[v]);
    }

    void union(int v1, int v2) {
        parent[get(v1)] = get(v2);
    }
}
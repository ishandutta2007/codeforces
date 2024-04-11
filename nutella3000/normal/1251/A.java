
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;



    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            char h[] = sc.next().toCharArray();
            boolean good[] = new boolean[26];
            for(int i = 1;i <= h.length;i++) {
                if (i == h.length || h[i] != h[i - 1]) good[h[i - 1] - 'a'] = true;
                else i++;
            }
            for(int i = 0;i < 26;i++) if (good[i]) pw.print((char)(i + 'a'));
            pw.println();
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
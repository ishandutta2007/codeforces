import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int m = nextInt();
        int n = nextInt();
        boolean can = true;
        int a[][] = new int [m][];
        for(int i = 0;i < m;i++) {
            int s = nextInt();
            a[i] = new int [s];
            for(int j = 0;j < s;j++) a[i][j] = nextInt();
            Arrays.sort(a[i]);
        }
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < m;j++) {
                int id1 = 0;
                int id2 = 0;
                boolean bad = true;
                while(id1 < a[i].length && id2 <a[j].length) {
                    if (a[i][id1] == a[j][id2]) bad = false;
                    if (a[i][id1] > a[j][id2]) {
                        id2++;
                    }else{
                        id1++;
                    }
                }
                if (bad) can = false;
            }
        }
        if (can) pw.println("possible");
        else pw.println("impossible");
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
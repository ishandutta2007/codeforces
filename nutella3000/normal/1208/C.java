import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    static void add(HashMap<Integer, Integer> one, int two) {
        if (!one.containsKey(two)) one.put(two, 0);
        one.put(two, one.get(two) + 1);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[][] = new int [n][n];
        int num = 0;
        for(int i = 0;i < n/ 4;i++) {
            for(int j = 0;j < n / 4;j++) {
                for(int i1 = 0;i1 < 4;i1++) {
                    for(int j1 = 0;j1 < 4;j1++) {
                        a[i * 4 + i1][j * 4 + j1] = num;
                        num++;
                    }
                }
            }
        }
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) pw.print(a[i][j] + " ");
            pw.println();
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
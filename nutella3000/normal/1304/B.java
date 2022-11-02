import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        char h[][] = new char[n][m];
        for(int i = 0;i < n;i++) h[i] = sc.next().toCharArray();
        int used[] = new int[n];
        for(int i = 0;i < n;i++) used[i] = -2;
        boolean centre = false;
        for(int i = 0;i < n;i++) {
            if (used[i] != -2) continue;
            for(int j = i + 1;j < n;j++) {
                if (used[j] != -2) continue;
                boolean bad = false;
                for(int q = 0;q < m;q++) if (h[i][q] != h[j][m - q - 1]) bad = true;
                if (!bad) {
                    used[i] = j;
                    used[j] = i;
                }
            }
            if (used[i] != -2 || centre) continue;
            boolean bad = false;
            for(int j = 0;j < m;j++) if (h[i][j] != h[i][m - j - 1]) bad = true;
            if (!bad) {
                used[i] = -1;
                centre = true;
            }
        }

        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if (used[i] != -2) cnt += m;
        }
        pw.println(cnt);
        ArrayList<Integer> one = new ArrayList<>();
        ArrayList<Integer> two = new ArrayList<>();
        for(int i = 0;i < n;i++) {
            if (used[i] >= 0) {
                one.add(i);
                two.add(used[i]);
                used[used[i]] = -2;
                used[i] = -2;
            }
        }
        for(int i = 0;i < n;i++) if (used[i] == -1) one.add(i);

        for(int i : one) {
            pw.print(h[i]);
        }
        for(int i = two.size() - 1;i >= 0;i--) {
            pw.print(h[two.get(i)]);
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
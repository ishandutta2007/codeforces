import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        char temptemp[] = next().toCharArray();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) {
            if (temptemp[i] == '[') a[i] = 1;
            else a[i] = -1;
        }
        int y = 0;
        int max = 0;
        for(int i = 0;i < n;i++) {
            y += a[i];
            if (max < y) max = y;
        }
        max = (max - 1) * 2 + 1 + 2;

        int sz = 0;
        for(int i = 0;i < n;i++) {
            sz += 2;
            if (i != n - 1 && (a[i] == a[i + 1])) {
                sz--;
            }
            if (i != n - 1 && a[i] == 1 && a[i + 1] == -1) sz++;
        }
        char ans[][] = new char[sz][max];
        for(int i = 0;i < sz;i++) {
            for(int j = 0;j < max;j++) ans[i][j] = ' ';
        }
        int left = 0;
        int l1 = 0;
        for(int i = 0;i < n;i++) {
            if (a[i] == 1) {
                ans[l1][left] = '+';
                ans[l1][max - left - 1] = '+';
                ans[l1 + 1][left] = '-';
                ans[l1 + 1][max - left - 1] = '-';
                for(int j = left + 1;j < max - left - 1;j++) ans[l1][j] = '|';

                left++;
                if (i != n - 1 && a[i + 1] == -1) l1 += 3;
                else l1++;
            }else{
                left--;

                ans[l1 + 1][left] = '+';
                ans[l1 + 1][max - left - 1] = '+';
                ans[l1][left] = '-';
                ans[l1][max - left - 1] = '-';
                for(int j = left + 1;j < max - left - 1;j++) ans[l1 + 1][j] = '|';

                if (i != n - 1 && a[i + 1] == -1) l1++;
                else l1 += 2;
            }
        }

        for(int i = 0;i < max;i++) {
            for(int j = 0;j < sz;j++) pw.print(ans[j][i]);
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
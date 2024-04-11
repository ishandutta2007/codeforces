import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        char s[] = next().toCharArray();
        int have[][] = new int[26][n];
        have[s[0] - 'a'][0] = 1;
        for(int i = 1;i < n;i++) {
            for(int j = 0;j < 26;j++) have[j][i] = have[j][i - 1];
            have[s[i] - 'a'][i]++;
        }
        int m = nextInt();
        while(m-- > 0) {
            char h[] = next().toCharArray();
            int k = h.length;
            int ha[] = new int[26];
            for(int i = 0;i < k;i++) {
                ha[h[i] - 'a']++;
            }
            int l = -1;
            int r = n;
            while(l != r - 1) {
                int mid = (l + r) / 2;
                boolean good = true;
                for(int i = 0;i < 26;i++) {
                    if (ha[i] > have[i][mid]) good = false;
                }
                if (good) r = mid;
                else l = mid;
            }
            pw.println(r + 1);
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}
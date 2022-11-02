import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int[] a = Arrays.stream(next().split(""))
                .map(String::trim).mapToInt(Integer::parseInt).toArray();
        int cnt[] = new int [10];
        String temp = next();
        for(int i = 0;i < temp.length();i++) {
            cnt[temp.charAt(i) - '0']++;
        }

        int v_cnt[] = new int [10];
        for(int i = 0;i < 10;i++) v_cnt[i] = cnt[i];

        Arrays.sort(a);
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0;i < a.length;i++) {
            int j = a[i];
            while(j < 10 && v_cnt[j] == 0) j++;
            if (j == 10) ans1++;
            else v_cnt[j]--;

            j = a[i] + 1;
            while(j < 10 && cnt[j] == 0) j++;
            if (j != 10) {
                cnt[j]--;
                ans2++;
            }
        }

        pw.println(ans1);
        pw.println(ans2);
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
import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, a[], sum;
    static int cnt = inf;
    static boolean ans[];

    static void zero() {
        if (cnt < n - 1) return;

        for(int i = 0;i < n;i++) {
            if (a[i] == 0) {
                for(int j = 0;j < n;j++) ans[j] = false;
                ans[i] = true;
                cnt = n - 1;
                break;
            }
        }
    }

    static void one() {
        int last_id = -1;
        int cnt_first = 0;
        boolean first = true;
        for(int i = 0;i < n;i++) {
            if (i != 0 && a[i] != 0) first = false;
            if (first) cnt_first++;
            if (a[i] % 3 == sum) last_id = i;
        }

        if (last_id == -1) return;
        if (last_id != 0) {
            for(int i = 0;i < n;i++) ans[i] = true;
            ans[last_id] = false;
            cnt = 1;
        }else{
            boolean new_ans[] = new boolean[n];
            int new_cnt = cnt_first;
            for(int i = 0;i < cnt_first;i++) new_ans[i] = false;
            for(int i = cnt_first;i < n;i++) new_ans[i] = true;
            if (new_cnt < cnt) {
                cnt = new_cnt;
                ans = new_ans;
            }
        }
    }

    static void two() {
        int first = -1;
        int second = -1;
        int pref = 0;
        int kill = 0;
        for(int i = 0;i < n;i++) {
            if (a[i] % 3 == 3 - sum) {
                second = first;
                first = i;
                kill++;
            }
            if (a[i] % 3 != 3 - sum && a[i] != 0) kill = inf;
            if (kill < 3) pref++;
        }


        boolean new_ans[] = new boolean[n];
        for(int i = 0;i < n;i++) new_ans[i] = true;

        if (second == -1) return;
        if (second == 0) {
            for(int i = 0;i < pref;i++) new_ans[i] = false;
        }

        new_ans[first] = false;
        new_ans[second] = false;
        int new_cnt = 0;
        for(int i = 0;i < n;i++) if (!new_ans[i]) new_cnt++;
        if (new_cnt < cnt) {
            cnt = new_cnt;
            ans = new_ans;
        }
    }


    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        char temp[] = next().toCharArray();
        n = temp.length;
        a = new int [n];
        for(int i = 0;i < n;i++) a[i] = temp[i] - '0';

        sum = 0;
        for(int i = 0;i < n;i++) sum += a[i];
        sum %= 3;
        if (sum == 0) {
            for(int i = 0;i < n;i++) pw.print(a[i]);
        }else{
            ans = new boolean[n];
            zero();
            one();
            two();
            if (cnt >= n) pw.println(-1);
            else{
                for(int i = 0;i < n;i++) if (ans[i]) pw.print(a[i]);
            }
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

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
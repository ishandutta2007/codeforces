import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int q = nextInt();
        while(q-- > 0) {
            char s[] = next().toCharArray();
            char t[] = next().toCharArray();
            char p[] = next().toCharArray();
            int cnt1[] = new int [26];
            for(char i : t) cnt1[i - 'a']++;
            for(char i : s) cnt1[i - 'a']--;
            for(char i : p) {
                if (cnt1[i - 'a'] > 0) cnt1[i - 'a']--;
            }
            boolean ans = true;
            int id = 0;
            for(int i = 0;i < t.length;i++) {
                if (id < s.length && s[id] == t[i]) id++;
            }
            if (id < s.length) ans = false;
            for(int i = 0;i < 26;i++) if (cnt1[i] != 0) ans = false;
            if (ans) pw.println("YES");
            else pw.println("NO");
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
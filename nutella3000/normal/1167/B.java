import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    static int ans1, ans2, ans3;
    static void q(int a, int b, int a1, int b1, int c1) {
        if (a1 != -1) {
            ans2 = a / a1;
            ans3 = b / ans2;
        }else if (b1 != -1) {
            ans1 = a / b1;
            ans3 = b / b1;
        }else if(c1 != -1) {
            ans2 = b / c1;
            ans1 = a / ans2;
        }
    }
    static void r(int a, int b, int good) {
        if (a % good == 0 && b % good == 0) {
            ans2 = good;
            q(a, b, -1, good, -1);
        }else if (a % good == 0) {
            ans1 = good;
            q(a, b, good, -1, -1);
        }else{
            ans3 = good;
            q(a, b, -1, -1, good);
        }
    }
    static void f(int a, int b) {
        int c = a * b;
        int good = -1;
        if (c % 23 == 0) good = 23;
        if (c % 42 == 0) good = 42;
        if (c % 15 == 0) good = 15;
        if (good != -1) r(a, b, good);
        else{
            int cnt = 0;
            while(c != 1) {
                cnt++;
                c/= 2;
            }
            ans2 = (1 << (cnt - 9));
            q(a, b, -1, ans2, -1);
        }
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        pw.println("? " + 1 + " " + 2);
        pw.println("? " + 2 + " " + 3);
        pw.flush();
        int a = nextInt();
        int b = nextInt();
        f(a, b);
        int ans[] = new int [6];
        ans[0] = ans1;
        ans[1] = ans2;
        ans[2] = ans3;

        pw.println("? " + 4 + " " + 5);
        pw.println("? " + 5 + " " + 6);
        pw.flush();
        a = nextInt();
        b = nextInt();
        f(a, b);
        ans[3] = ans1;
        ans[4] = ans2;
        ans[5] = ans3;
        pw.print("! ");
        for(int i : ans) pw.print(i + " ");
        pw.println();
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
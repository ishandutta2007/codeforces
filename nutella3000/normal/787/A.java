import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int a = nextInt();
        int b = nextInt();
        int c = nextInt();
        int d = nextInt();
        int ans = 0;
        int id1 = 0;
        int id2 = 0;
        while(true) {
            if (b + a * id1 < d + c * id2) {
                id1++;
            }else if (b + a * id1 > d + c * id2) {
                id2++;
            }else{
                ans = b + a * id1;
                break;
            }
            if (b + a * id1 > 1e6) {
                System.out.println(-1);
                return;
            }
        }
        pw.println(ans);
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
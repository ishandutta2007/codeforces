import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        pw.print("? ");
        for(int i = 1;i <= 100;i++) pw.print(i + " ");
        pw.println();
        pw.flush();
        int a = nextInt();


        pw.print("? ");
        for(int i = 1;i <= 100;i++) pw.print(i * 128 + " ");
        pw.println();
        pw.flush();

        int b = nextInt();


        pw.println("! " + ((a / 128 * 128) + (b % 128)));
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
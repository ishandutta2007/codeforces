import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int b[] = new int [2];
        b[0] = nextInt();
        b[1] = nextInt();
        int x = nextInt();
        int loc = 0;
        if (b[1] > b[0]) {
            loc = 1;
        }
        while (x != 0) {
            pw.print(loc);
            x--;
            b[loc]--;
            loc = (loc + 1) %2;
        }
        loc = (loc + 1) % 2;
        while (b[loc] != 0) {
            pw.print(loc);
            b[loc]--;
        }
        loc=  (loc +1) % 2;
        while (b[loc] != 0) {
            pw.print(loc);
            b[loc]--;
        }
        pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st= new StringTokenizer("");
    public static int nextInt() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }
    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}
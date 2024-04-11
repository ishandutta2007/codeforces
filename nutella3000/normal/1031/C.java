import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int a = nextInt();
        int b = nextInt();
        ArrayList<Integer> ansA = new ArrayList<>();
        ArrayList<Integer> ansB = new ArrayList<>();
        int k = 1;
        while (a >= k) {
            ansA.add(k);
            a-=k;
            k++;
        }
        int v = k;
        while (b >= k) {
            ansB.add(k);
            b-=k;
            k++;
        }
        if (a != 0) {
            if (ansB.size() == 0) {
                int y = ansA.get(ansA.size() - a);
                ansA.remove(ansA.size() - a);
                ansA.add(k);
                if (b >= y) {
                    ansB.add(y);
                }
            }else {
                int y = ansA.get(ansA.size() - a);
                ansB.add(y);
                ansA.remove(ansA.size() - a);
                ansA.add(ansB.get(0));
                ansB.remove(0);
                b += a;
                if (b >= k) {
                    ansB.add(k);
                }
            }
        }
        pw.println(ansA.size());
        for (int i = 0; i < ansA.size(); i++) {
            pw.print(ansA.get(i) + " ");
        }
        if (ansA.size() != 0)pw.println();
        pw.println(ansB.size());
        for (int i = 0; i < ansB.size(); i++) {
            pw.print(ansB.get(i) + " ");
        }
        pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    public static int nextInt() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }
    public static String next() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
    public static long nextLong() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Long.parseLong(st.nextToken());
    }
    public static double nextDouble() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }
}
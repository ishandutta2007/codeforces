import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int k = sc.nextInt();
        TreeMap<Integer, Integer> a = new TreeMap<>();
        for(int i = 0;i < k + 1;i++) {
            pw.print("? ");
            for(int j = 0;j < k + 1;j++) {
                if (i != j) pw.print(j + 1 + " ");
            }
            pw.flush();
            int pos = sc.nextInt();
            int v = sc.nextInt();
            if (!a.containsKey(v)) a.put(v, 0);
            a.put(v, a.get(v) + 1);
        }

        pw.println("! " + a.lastEntry().getValue());

        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}
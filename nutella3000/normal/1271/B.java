import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        char h[] = sc.next().toCharArray();
        ArrayList<Integer> ans = new ArrayList<>();
        int sum = 0;
        for(int i = 0;i < n;i++) {
            if (h[i] == 'B') sum++;
        }
        if (sum % 2 == 1 && n % 2 == 0) {
            System.out.println(-1);
            return;
        }

        for(int i = 0;i < n - 1;i++) {
            if (h[i] == 'W') {
                ans.add(i + 1);
                h[i] = 'B';
                if (h[i + 1] == 'B') h[i + 1] = 'W';
                else h[i + 1] = 'B';
            }
        }

        if (h[n - 1] == 'W') {
            for(int i = 0;i < n - 1;i++) {
                if (h[i] == 'B') {
                    ans.add(i + 1);
                    h[i] = 'W';
                    if (h[i + 1] == 'W') h[i + 1] = 'B';
                    else h[i + 1] = 'W';
                }
            }
        }




        pw.println(ans.size());
        for(int i : ans) pw.print(i + " ");

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
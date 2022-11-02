
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for (int test = sc.nextInt(); test > 0; test--) {
            char h[] = sc.next().toCharArray();
            ArrayList<Integer> a = new ArrayList<>();
            a.add(h[0] - 'a');
            int id = 0;
            boolean bad = false;
            boolean b[] = new boolean[26];
            b[h[0] - 'a'] = true;
            for(int i = 1;i < h.length;i++) {
                int next = h[i] - 'a';
                if (id + 1 < a.size() && a.get(id + 1) == next) id++;
                else if (id - 1 >= 0 && a.get(id - 1) == next) id--;
                else if (b[next] || (id != 0 && id != a.size() - 1)) bad = true;
                else {
                    b[next] = true;
                    if (id == 0) a.add(0, next);
                    else {
                        a.add(next);
                        id++;
                    }
                }
            }



            if (bad) pw.println("NO");
            else {
                pw.println("YES");
                for (int i : a) pw.print((char)(i + 'a'));
                for (int i = 0; i < 26; i++) if (!b[i]) pw.print((char)(i + 'a'));
                pw.println();
            }
        }
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
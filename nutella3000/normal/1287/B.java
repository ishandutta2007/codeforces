import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9;
    static char[] cal = new char[]{'S', 'E', 'T'};

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        TreeSet<char[]> a = new TreeSet<>(new Comparator<char[]>() {
            @Override
            public int compare(char[] o1, char[] o2) {
                for(int i = 0;i < o1.length;i++) {
                    if (o1[i] < o2[i]) return -1;
                    if (o1[i] > o2[i]) return 1;
                }
                return 0;
            }
        });

        for(int i = 0;i < n;i++) {
            char temp[] = sc.next().toCharArray();
            a.add(temp);
        }

        long ans = 0;

        for(char f[] : a) {
            for(char s[] : a) {
                boolean bad = true;
                for(int i = 0;i < m;i++) if (f[i] != s[i]) bad = false;
                if (bad) continue;
                char t[] = new char[m];
                for(int i = 0;i < m;i++) {
                    if (f[i] != s[i]) {
                        for (char j : cal) if (f[i] != j && s[i] != j) t[i] = j;
                    }else t[i] = f[i];
                }

                if (a.contains(t)) ans++;
            }
        }

        pw.println(ans / 6);


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
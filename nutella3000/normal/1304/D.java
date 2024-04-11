import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            char[] h = sc.next().toCharArray();
            int cnt[] = new int [n];
            for(int i = n - 2;i >= 0;i--) {
                cnt[i] = 1;
                if (i + 1 < n - 1 && h[i + 1] == h[i]) cnt[i] += cnt[i + 1];
            }

            int min[] = new int [n];
            int max[] = new int [n];
            int pref = n;
            int suf = 1;
            for(int i = 0;i < n;i++) {
                if (i == n - 1) {
                    min[i] = 1;
                    continue;
                }
                if (h[i] == '<') {
                    min[i] = pref - cnt[i];
                    for(int j = i + 1;j <= i + cnt[i];j++) {
                        min[j] = pref - cnt[i] + (j - i);
                    }
                    pref -= cnt[i] + 1;
                    i += cnt[i];
                }else{
                    min[i] = pref;
                    pref--;
                }
            }

            for(int i = 0;i < n;i++) {
                if (i == n - 1) {
                    max[i] = n;
                    continue;
                }
                if (h[i] == '>') {
                    max[i] = suf + cnt[i];
                    for(int j = i + 1;j <= i + cnt[i];j++) {
                        max[j] = suf + cnt[i] - (j - i);
                    }
                    suf += cnt[i] + 1;
                    i += cnt[i];
                }else{
                    max[i] = suf;
                    suf++;
                }
            }

            for(int i = 0;i < n;i++) pw.print(min[i] + " ");
            pw.println();
            for(int i = 0;i < n;i++) pw.print(max[i] + " ");
            pw.println();
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

class pair implements Comparator<pair>{
    int t, l, r;
    pair(int t, int l, int r) {
        this.t = t;
        this.l = l;
        this.r = r;
    }
    pair() {}
    @Override
    public int compare(pair pair, pair t1) {
        return Integer.compare(pair.t, t1.t);
    }
}
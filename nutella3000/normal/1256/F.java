import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            char o1[] = sc.next().toCharArray();
            char o2[] = sc.next().toCharArray();
            int cnt1[] = new int [26];
            int cnt2[] = new int [26];
            int inv1 = 0;
            int inv2 = 0;
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < o1[i] - 'a';j++) {
                    inv1 += cnt1[j];
                }
                for(int j = 0;j < o2[i] - 'a';j++) {
                    inv2 += cnt2[j];
                }

                cnt1[o1[i] - 'a']++;
                cnt2[o2[i] - 'a']++;
            }

            boolean bad = true;
            for(int i = 0;i < 26;i++) if (cnt1[i] >= 2) bad = false;
            boolean no = false;
            for(int i = 0;i < 26;i++) if (cnt1[i] != cnt2[i]) no = true;
            if (bad && inv1 % 2 != inv2 % 2) no = true;
            if (no) pw.println("NO");
            else pw.println("YES");
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

class pair implements Comparator<pair> {
    int x, id;
    pair(int x, int id) {
        this.x = x;
        this.id = id;
    }

    pair () {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.x, o2.x);
    }
}
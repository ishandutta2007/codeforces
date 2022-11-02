import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    /*static int not;
    static long a[][]; // max suf
    static long b[][][]; // max suf mask*/

    static int not = 16;
    static long a[][] = new long[not][not]; // max suf
    static long b[][][] = new long[not][5][(1 << not)]; // max suf mask

    static void build_b() {
        for (int i = 0; i < not; i++) {
            for (int mask = 0; mask < (1 << not); mask++) {
                int one = mask % 16;
                int two = (mask >> 4) % 16;
                int three = (mask >> 8) % 16;
                int four = (mask >> 12) % 16;
                int max = Math.max(one, Math.max(two, Math.max(three, Math.max(four, i))));

                if ((mask & (1 << max)) != 0) b[i][0][mask] = 1;
            }
        }

        for (int sec = 1; sec <= 4; sec++) {
            for (int i = 0; i < not; i++) {
                for (int mask = 0; mask < (1 << not); mask++) {
                    int var = ((mask >> (sec * 4)) << (sec * 4));
                    for (int v = 0; v < not; v++) {
                        b[i][sec][mask] += b[i][sec - 1][var + (v << (sec * 4 - 4))];
                    }
                }
            }
        }
    }

    static void build_a() {
        for (int i = 0; i < not; i++) {
            a[i][4] = b[i][4][0];
        }
        for (int j = 5; j < not; j++) {
            for (int i = 0; i < not; i++) {
                for (int v = 0; v < not; v++) {
                    a[i][j] += a[Math.max(i, v)][j - 1];
                }
            }
        }
    }

    static long solve(int l[], int r[]) {
        int n = l.length;
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (l[i] != r[i]) break;
            id = i + 1;
        }
        int mask = 0;
        for (int i = n - 4; i < n; i++) {
            mask = (mask << 4) + l[i];
        }

        int max[] = new int[n];
        max[0] = l[0];
        for (int i = 1; i < n; i++) max[i] = Math.max(max[i - 1], l[i]);

        long ans = 0;

        for (int i = n - 1; i > id; i--) {
            do {
                if (l[i] == 16) {
                    l[i] = 0;
                    break;
                }
                int v_max = Math.max(l[i], max[i - 1]);

                if (n - i <= 4) {
                    ans += b[v_max][n - i - 1][mask];
                } else {
                    ans += a[v_max][n - i - 1];
                }

                if (n - i - 1 <= 4) mask += (1 << (4 * (n - i - 1)));

                l[i]++;
                if (l[i] == 16) {
                    l[i] = 0;
                }
            } while (l[i] != 0);

            l[i - 1]++;
        }

        int v_max = 0;
        for (int i = 0; i < id; i++) v_max = Math.max(v_max, l[i]);

        mask = 0;
        for (int i = n - 4; i < n; i++) {
            mask = (mask << 4) + l[i];
        }

        for (int i = id; i < n; i++) {

            v_max = Math.max(v_max, l[i]);
            while (l[i] != r[i]) {

                if (n - i - 1 <= 4) {
                        ans += b[v_max][n - i - 1][mask];
                } else {
                    ans += a[v_max][n - i - 1];
                }

                if (n - i - 1 < 4) mask += (1 << (4 * (n - i - 1)));
                l[i]++;

                v_max = Math.max(v_max, l[i]);
            }
        }

        ans += b[v_max][0][mask];
        return ans;
    }

    static void print_b() {
        TreeMap<Integer, Character> not_16 = new TreeMap<>();
        for (int i = 0; i <= 9; i++) not_16.put(i, (char) (i + '0'));
        for (int i = 0; i < 6; i++) not_16.put(i + 10, (char) (i + 'a'));

        for (int i = 0; i < not; i++) {
            for (int j = 4; j < 5; j++) {
                for (int mask = 0; mask < (1 << not); mask += (1 << (4 * j))) {
                    int four = mask % 16;
                    int three = (mask >> 4) % 16;
                    int two = (mask >> 8) % 16;
                    int one = (mask >> 12) % 16;
                    pw.print(i + " " + j + " ");

                    if (j == 4) pw.print("-");
                    else pw.print(not_16.get(one));

                    if (j >= 3) pw.print("-");
                    else pw.print(not_16.get(two));

                    if (j >= 2) pw.print("-");
                    else pw.print(not_16.get(three));

                    if (j >= 1) pw.print("-");
                    else pw.print(not_16.get(four));

                    pw.println("   " + b[i][j][mask]);
                }
            }
        }
        pw.flush();
    }

    static void print_a() {
        for (int i = 0; i < not; i++) {
            for (int j = 0; j < not; j++) {
                pw.println("max: " + i + ",  " + "unknown suf: " + j + " - " + a[i][j]);
            }
        }
        pw.flush();
    }

    public static void main(String[] args) throws IOException {
        /*inf = (int) 1e9 + 7;
        not = 16;
        a = new long[not][not]; // max suf
        b = new long[not][5][(1 << not)]; // max suf mask*/
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        build_b();
        build_a();
        //print_a();

        for (int q = nextInt(); q > 0; q--) {
            char l1[] = next().toCharArray();
            char r1[] = next().toCharArray();
            int l[] = new int[l1.length];
            int r[] = new int[r1.length];
            for (int i = 0; i < l1.length; i++) {
                if (l1[i] >= 'a') l[i] = l1[i] - 'a' + 10;
                else l[i] = l1[i] - '0';
            }
            for (int i = 0; i < r1.length; i++) {
                if (r1[i] >= 'a') r[i] = r1[i] - 'a' + 10;
                else r[i] = r1[i] - '0';
            }

            int u[] = new int[not];
            for (int i = not - l.length; i < not; i++) u[i] = l[i - not + l.length];
            l = u.clone();
            for (int i = 0; i < not; i++) u[i] = 0;
            for (int i = not - r.length; i < not; i++) u[i] = r[i - not + r.length];
            r = u.clone();

            pw.println(solve(l, r));
        }
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
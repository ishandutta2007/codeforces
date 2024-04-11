import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            char h[] = sc.next().toCharArray();
            int n = h.length;
            int x[] = new int [n + 1];
            int y[] = new int [n + 1];
            int this_x = 0;
            int this_y = 0;
            int id1_min = 0, id1_max = 0, id2_min = 0, id2_max = 0, id3_min = 0, id3_max = 0, id4_min = 0, id4_max = 0;

            for(int i = 1;i <= n;i++) {
                if (h[i - 1] == 'D') this_x--;
                if (h[i - 1] == 'A') this_x++;
                if (h[i - 1] == 'W') this_y++;
                if (h[i - 1] == 'S') this_y--;
                x[i] = this_x;
                y[i] = this_y;

                if (x[i] <= x[id1_max]) id1_max = i;
                if (x[i] >= x[id2_max]) id2_max = i;
                if (y[i] <= y[id3_max]) id3_max = i;
                if (y[i] >= y[id4_max]) id4_max = i;

                if (x[i] < x[id1_min]) id1_min = i;
                if (x[i] > x[id2_min]) id2_min = i;
                if (y[i] < y[id3_min]) id3_min = i;
                if (y[i] > y[id4_min]) id4_min = i;
            }

            for(int i = id1_max + 1;i <= n;i++) {
                if (h[i - 1] == 'A') {
                    id1_max = i;
                    break;
                }
            }

            for(int i = id2_max + 1;i <= n;i++) {
                if (h[i - 1] == 'D') {
                    id2_max = i;
                    break;
                }
            }

            for(int i = id3_max + 1;i <= n;i++) {
                if (h[i - 1] == 'W') {
                    id3_max = i;
                    break;
                }
            }

            for(int i = id4_max + 1;i <= n;i++) {
                if (h[i - 1] == 'S') {
                    id4_max = i;
                    break;
                }
            }

            long ans1 = x[id2_min] - x[id1_min] + 1;
            long ans2 = y[id4_min] - y[id3_min] + 1;

            boolean one = id1_max < id2_min || id2_max < id1_min;
            boolean two = id3_max < id4_min || id4_max < id3_min;
            if (one && (!two || (ans1 - 1) * ans2 < ans1 * (ans2 - 1))) ans1--;
            else if (two) ans2--;
            pw.println(ans1 * ans2);
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
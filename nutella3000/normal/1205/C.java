import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;
    static int a[][];
    static void scan() throws IOException {
        n = nextInt();
        a = new int [n][n];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) a[i][j] = -1;
        }
        a[0][0] = 1;
        a[n - 1][n - 1] = 0;
    }
    static void f(int x1, int y1, int x2, int y2) {
        pw.println("? " + (x1 + 1) + " " + (y1 + 1) + " " + (x2 + 1) + " " + (y2 + 1));
        pw.flush();
    }

    static void build1() throws IOException {
        int last = 0;
        for(int i = 1;i < n;i++) {
            int sec = i % 2;
            f(last, 0, i, sec);
            int b = nextInt();
            if (a[last][0] == 0) a[i][sec] = 1 - b;
            else a[i][sec] = b;
            if (sec == 0) last = i;
        }
        for(int i = 0;i < n;i++) {
            for(int j = (i % 2);j + 2 < n;j += 2) {
                f(i, j, i, j + 2);
                int b = nextInt();
                if (a[i][j] == 0) a[i][j + 2] = 1 - b;
                else a[i][j + 2] = b;
            }
        }
    }
    static void build2() throws IOException {
        a[0][1] = 0;
        f(0, 1, 1, 2);
        f(1, 0, 1, 2);
        int b1 = nextInt();
        int b2 = nextInt();
        a[1][2] = 1 - b1;
        if (a[1][2] == 0) a[1][0] = 1 - b2;
        else a[1][0] = b2;

        int last = 1;
        for(int i = 2;i < n;i++) {
            int sec = 1 - i % 2;
            f(last, 0, i, sec);
            int b = nextInt();
            if (a[last][0] == 0) a[i][sec] = 1 - b;
            else a[i][sec] = b;
            if (sec == 0) last = i;
        }

        for(int i = 0;i < n;i++) {
            for(int j = 1 - (i % 2);j + 2 < n;j += 2) {
                f(i, j, i, j + 2);
                int b = nextInt();
                if (a[i][j] == 0) a[i][j + 2] = 1 - b;
                else a[i][j + 2] = b;
            }
        }
    }

    static boolean build3() throws IOException {
        for(int x1 = 0;x1 < n;x1++) {
            for(int y1 = 0;y1 < n;y1++) {
                int cor2[] = new int [2];
                for(int k1 = 0;k1 < 2;k1++) {
                    cor2[0] = x1;
                    cor2[1] = y1;
                    cor2[k1]++;
                    if (cor2[k1] == n) continue;

                    int cor3[] = new int [2];

                    for(int k2 = 0;k2 < 2;k2++) {
                        cor3[0] = cor2[0];
                        cor3[1] = cor2[1];
                        cor3[k2]++;
                        if (cor3[k2] == n) continue;

                        int cor4[] = new int [2];

                        for(int k3 = 0;k3 < 2;k3++) {
                            cor4[0] = cor3[0];
                            cor4[1] = cor3[1];
                            cor4[k3]++;
                            if (cor4[k3] == n) continue;

                            if ((a[x1][y1] == a[cor3[0]][cor3[1]]) == (a[cor2[0]][cor2[1]] == a[cor4[0]][cor4[1]])) {
                                f(x1, y1, cor4[0], cor4[1]);
                                int b1 = nextInt();
                                boolean b = false;
                                if (b1 == 1) b = true;
                                if ((a[x1][y1] == a[cor4[0]][cor4[1]]) == b) return false;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        while(true);
    }

    static void rev() {
        for(int i = 0;i < n;i++) {
            for(int j = 1 - i % 2;j < n; j += 2) {
                a[i][j] = 1 - a[i][j];
            }
        }
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        scan();
        build1();
        build2();
        if (build3()) {
            rev();
        }
        pw.println("!");
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) pw.print(a[i][j]);
            pw.println();
        }
        pw.println();
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
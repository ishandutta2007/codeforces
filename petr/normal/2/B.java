import java.io.*;
import java.util.*;

public class Path implements Runnable {
    static final int INF = 10000000;

    private void solve() throws IOException {
        int n = nextInt();
        int[][] p5 = new int[n][n];
        int[][] p2 = new int[n][n];
        boolean[][] isZero = new boolean[n][n];
        boolean haveZero = false;
        int zeroI = -1;
        int zeroJ = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0 ; j < n; ++j) {
                int a = nextInt();
                if (a == 0) {
                    isZero[i][j] = true;
                    haveZero = true;
                    zeroI = i;
                    zeroJ = j;
                } else {
                    while (a % 5 == 0) {
                        ++p5[i][j];
                        a /= 5;
                    }
                    while (a % 2 == 0) {
                        ++p2[i][j];
                        a /= 2;
                    }
                }
            }
        }
        int[][] best5 = new int[n][n];
        boolean[][] by5 = new boolean[n][n];
        int[][] best2 = new int[n][n];
        boolean[][] by2 = new boolean[n][n];
        OnePrime(n, p5, isZero, best5, by5);
        OnePrime(n, p2, isZero, best2, by2);
        int best = Math.min(haveZero ? 1 : INF, Math.min(best5[n - 1][n - 1], best2[n - 1][n - 1]));
        writer.println(best);
        if (best == 1 && haveZero) {
            for (int i = 0; i < zeroI; ++i)
                writer.print("D");
            for (int j = 0; j < zeroJ; ++j)
                writer.print("R");
            for (int i = 0; i < n - 1 - zeroI; ++i)
                writer.print("D");
            for (int j = 0; j < n - 1 - zeroJ; ++j)
                writer.print("R");
            writer.println();
        } else if (best == best5[n - 1][n - 1]) {
            printPath(n - 1, n - 1, by5);
            writer.println();
        } else {
            printPath(n - 1, n - 1, by2);
            writer.println();
        }
    }

    private void printPath(int i, int j, boolean[][] by5) {
        if (i == 0 && j == 0)
            return;
        if (by5[i][j]) {
            printPath(i, j - 1, by5);
            writer.print("R");
        } else {
            printPath(i - 1, j, by5);
            writer.print("D");
        }
    }

    private void OnePrime(int n, int[][] p5, boolean[][] zero, int[][] best5, boolean[][] by5) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                best5[i][j] = INF;
                if (i == 0 && j == 0) {
                    if (!zero[i][j])
                        best5[i][j] = p5[i][j];
                }
                if (i > 0) {
                    if (best5[i - 1][j] + p5[i][j] < best5[i][j]) {
                        best5[i][j] = best5[i - 1][j] + p5[i][j];
                    }
                }
                if (j > 0) {
                    if (best5[i][j - 1] + p5[i][j] < best5[i][j]) {
                        best5[i][j] = best5[i][j - 1] + p5[i][j];
                        by5[i][j] = true;
                    }
                }
            }
    }


    public static void main(String[] args) {
        new Path().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
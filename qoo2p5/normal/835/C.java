import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        new Solution().run();
    }
}

class Solution {
    final int MAX_CORD = 100;

    Scanner in;
    BufferedWriter out;
    int n, q, c;
    int cnt[][][];

    int get(int t, int x1, int y1, int x2, int y2) {
        int res = 0;
        for (int i = 0; i <= c; i++) {
            int brightness = (i + t) % (c + 1);
            int amount = cnt[i][x2][y2] - cnt[i][x1 - 1][y2] - cnt[i][x2][y1 - 1] + cnt[i][x1 - 1][y1 - 1];
            res += amount * brightness;
        }
        return res;
    }

    void run() throws IOException {
        in = new Scanner(System.in);
        out = new BufferedWriter(new OutputStreamWriter(System.out));
        n = in.nextInt();
        q = in.nextInt();
        c = in.nextInt();
        cnt = new int[c + 1][MAX_CORD + 1][MAX_CORD + 1];
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            int s = in.nextInt();
            cnt[s][x][y]++;
        }

        for (int p = 0; p <= c; p++) {
            for (int i = 1; i <= MAX_CORD; i++) {
                for (int j = 1; j <= MAX_CORD; j++) {
                    cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];
                }
            }
        }

        for (int i = 0; i < q; i++) {
            int t = in.nextInt();
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            out.write(get(t, x1, y1, x2, y2) + "\n");
        }

        out.flush();
    }
}
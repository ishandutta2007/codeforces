import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class HappyProb implements Runnable {
    private void solve() throws IOException {
        int pl = nextInt();
        int pr = nextInt();
        int vl = nextInt();
        int vr = nextInt();
        int k = nextInt();
        List<Integer> all = new ArrayList<Integer>();
        buildAll(0, Math.max(pr, vr), all);
        all.add(Math.max(pr, vr) + 2);
        Collections.sort(all);
        long res = 0;
        for (int i = 1; i < all.size(); ++i)
            for (int bi = 0; bi < 2; ++bi) {
                int mini;
                int maxi;
                if (bi == 0) {
                    mini = all.get(i - 1) + 1;
                    maxi = all.get(i) - 1;
                } else {
                    mini = all.get(i);
                    maxi = mini;
                }
                mini = Math.max(mini, pl);
                maxi = Math.min(maxi, pr);
                if (mini > maxi)
                    continue;
                for (int j = 1; j < all.size(); ++j)
                    for (int bj = 0; bj < 2; ++bj) {
                        int cnt = Math.max(i, j) - Math.min(i, j);
                        if ((i >= j && bi == 1) || (j >= i && bj == 1))
                            ++cnt;
                        if (cnt != k)
                            continue;
                        int minj;
                        int maxj;
                        if (bj == 0) {
                            minj = all.get(j - 1) + 1;
                            maxj = all.get(j) - 1;
                        } else {
                            minj = all.get(j);
                            maxj = minj;
                        }
                        minj = Math.max(minj, vl);
                        maxj = Math.min(maxj, vr);
                        if (minj > maxj)
                            continue;
                        res += (maxi - mini + 1) * (long) (maxj - minj + 1);
                    }
            }
        System.out.printf("%.15f", res / (double) ((pr - pl + 1) * (long) (vr - vl + 1)));
    }

    private void buildAll(long got, long max, List<Integer> all) {
        if (got > max)
            return;
        all.add((int) got);
        buildAll(got * 10 + 4, max, all);
        buildAll(got * 10 + 7, max, all);
    }

    public static void main(String[] args) {
        new HappyProb().run();
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
import java.io.*;
import java.util.*;

public class Template implements Runnable {
    static class Album implements Comparable<Album> {
        int cnt;
        int index;

        public int compareTo(Album album) {
            return album.cnt - cnt;
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        Album[] a = new Album[m];
        for (int i = 0; i < m; ++i) {
            a[i] = new Album();
            a[i].cnt = nextInt();
            a[i].index = i + 1;
        }
        Arrays.sort(a);
        int total = 0;
        for (int i = 0; i < m; ++i) total += a[i].cnt;
        while (total > n) {
            --total;
            --a[0].cnt;
            Arrays.sort(a);
        }
        if (total < n) {
            writer.println(-1);
            return;
        }
        int[] places = new int[n];
        int pos = 0;
        for (int i = 0; i < n; i += 2)
            places[pos++] = i;
        for (int i = 1; i < n; i += 2)
            places[pos++] = i;
        pos = 0;
        int[] res = new int[n];
        for (Album al : a)
            for (int j = 0; j < al.cnt; ++j)
                res[places[pos++]] = al.index;
        for (int i = 0; i < n; ++i)
            if (res[i] == res[(i + 1) % n]) {
                writer.println(-1);
                return;
            }
        for (int i = 0; i < n; ++i) {
            if (i > 0) writer.print(" ");
            writer.print(res[i]);
        }
        writer.println();
    }

    public static void main(String[] args) {
        new Template().run();
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
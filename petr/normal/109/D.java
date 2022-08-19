import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class HappySort implements Runnable {
    private void solve() throws IOException {
        Random random = new Random(471574315413L + System.currentTimeMillis());
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = nextInt();
        boolean ok = true;
        for (int i = 1; i < n; ++i)
            if (a[i] < a[i - 1])
                ok = false;
        if (ok) {
            System.out.println(0);
            return;
        }
        int luckyIndex = -1;
        for (int i = 0; i < n; ++i)
            if (isLucky(a[i])) {
                luckyIndex = i;
                break;
            }
        if (luckyIndex < 0) {
            System.out.println(-1);
            return;
        }
        Item[] allItems = new Item[n];
        for (int i = 0; i < n; ++i)
            allItems[i] = new Item(a[i], i);
        for (int i = 0; i < n; ++i) {
            int j = i + random.nextInt(n - i);
            Item tmp = allItems[j];
            allItems[j] = allItems[i];
            allItems[i] = tmp;
        }
        Arrays.sort(allItems);
        int[] src = new int[n];
        int[] dest = new int[n];
        for (int i = 0; i < n; ++i) {
            src[i] = allItems[i].index;
            dest[allItems[i].index] = i;
        }
        List<String> swaps = new ArrayList<String>();
        for (int i = 0; i < n; ++i) {
            if (src[i] != luckyIndex && src[i] != i) {
                if (i != luckyIndex) {
                    int p1 = i;
                    int p2 = luckyIndex;
                    swaps.add((p1 + 1) + " " + (p2 + 1));
                    int p1d = dest[p1];
                    int p2d = dest[p2];
                    dest[p1] = p2d;
                    dest[p2] = p1d;
                    src[dest[p1]] = p1;
                    src[dest[p2]] = p2;
                    luckyIndex = p1;
                }
                if (src[i] != i) {
                    int p1 = luckyIndex;
                    int p2 = src[i];
                    swaps.add((p1 + 1) + " " + (p2 + 1));
                    int p1d = dest[p1];
                    int p2d = dest[p2];
                    dest[p1] = p2d;
                    dest[p2] = p1d;
                    src[dest[p1]] = p1;
                    src[dest[p2]] = p2;
                    luckyIndex = p2;
                }
            }
        }
        for (int i = 0; i < n; ++i)
            if (src[i] != i || dest[i] != i) throw new RuntimeException();
        System.out.println(swaps.size());
        for (String x : swaps) System.out.println(x);
    }

    static class Item implements Comparable<Item> {
        int value;
        int index;

        Item(int value, int index) {
            this.value = value;
            this.index = index;
        }

        public int compareTo(Item item) {
            if (value < item.value)
                return -1;
            else if (value > item.value)
                return 1;
            else
                return 0;
        }
    }

    private boolean isLucky(long x) {
        while (x > 0) {
            long dig = x % 10;
            x /= 10;
            if (dig == 4 || dig == 7) continue;
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        new HappySort().run();
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
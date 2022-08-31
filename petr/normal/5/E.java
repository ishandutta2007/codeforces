import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;
import java.util.StringTokenizer;

public class Hills implements Runnable {
    static class Number implements Comparable<Number> {
        int what;
        int at;

        Number(int what, int at) {
            this.what = what;
            this.at = at;
        }

        public int compareTo(Number number) {
            return what - number.what;
        }
    }

    int[] parent;
    int[] rank;
    int[] maxElement;
    int[] maxCount;

    private void solve() throws IOException {
        int n = nextInt();
        final int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = nextInt();
        long res = doit(n, a);

        writer.println(res);
    }

    private long doit2(int n, int[] a) {
        long res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                if (i != j) {
                    boolean ok = true;
                    for (int k = (i + 1) % n; k != j; k = (k + 1) % n)
                        if (a[k] > a[i] || a[k] > a[j])
                            ok = false;
                    if (!ok) {
                        ok = true;
                        for (int k = (j + 1) % n; k != i; k = (k + 1) % n)
                            if (a[k] > a[i] || a[k] > a[j])
                                ok = false;
                    }
                    if (ok)
                        ++res;
                }
        }
        return res / 2;
    }

    private long doit(int n, int[] a) {
        int max = 0;
        for (int i = 0; i < n; ++i)
            max = Math.max(max, a[i]);
        long maxNum = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == max)
                ++maxNum;
        long res = maxNum * (maxNum - 1) / 2;
        int secondMax = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] != max)
                secondMax = Math.max(secondMax, a[i]);
        long secondMaxNum = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == secondMax)
                ++secondMaxNum;
        res += (n - maxNum - secondMaxNum) * 2 + secondMaxNum * (maxNum == 1 ? 1 : 2);
        Number[] sorted = new Number[n];
        for (int i = 0; i < n; ++i)
            sorted[i] = new Number(a[i], i);
        Arrays.sort(sorted);
        parent = new int[n];
        rank = new int[n];
        maxElement = new int[n];
        maxCount = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 1;
            maxElement[i] = 0;
            maxCount[i] = 0;
        }
        for (Number num : sorted) {
            if (num.what == max)
                break;
            int pos = num.at;
            int val = num.what;
            int c1 = getComponent(pos);
            int c2 = getComponent((pos + 1) % n);
            if (c1 != c2) {
                if (maxElement[c1] == val && maxElement[c2] == val)
                    res += (long) maxCount[c1] * maxCount[c2];
                c1 = mergeComponents(c1, c2);
            }
            updateMaxes(c1, val);
            res += maxCount[c1] - 1;
        }
        return res;
    }

    private void updateMaxes(int c1, int val) {
        if (val > maxElement[c1]) {
            maxElement[c1] = val;
            maxCount[c1] = 1;
        } else if (val == maxElement[c1])
            ++maxCount[c1];
    }

    private int mergeComponents(int c1, int c2) {
        if (rank[c1] <= rank[c2]) {
            parent[c1] = c2;
            if (rank[c1] == rank[c2])
                ++rank[c2];
            if (maxElement[c1] > maxElement[c2]) {
                maxElement[c2] = maxElement[c1];
                maxCount[c2] = maxCount[c1];
            } else if (maxElement[c1] == maxElement[c2]) {
                maxCount[c2] += maxCount[c1];
            }
            return c2;
        } else {
            parent[c2] = c1;
            if (maxElement[c2] > maxElement[c1]) {
                maxElement[c1] = maxElement[c2];
                maxCount[c1] = maxCount[c2];
            } else if (maxElement[c1] == maxElement[c2]) {
                maxCount[c1] += maxCount[c2];
            }
            return c1;
        }
    }

    private int getComponent(int x) {
        if (parent[x] == x)
            return x;
        else {
            parent[x] = getComponent(parent[x]);
            return parent[x];
        }
    }


    public static void main(String[] args) {
        /*Random random = new Random(401375431311L);
        while (true) {
            int n = 10;
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = random.nextInt(3) + 1;
            }
            if (new Hills().doit(n, a) != new Hills().doit2(n, a)) {
                System.out.println(new Hills().doit(n, a));
                System.out.println(new Hills().doit2(n, a));
                throw new RuntimeException();
            }
            System.out.print(".");
        }*/
        new Hills().run();
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
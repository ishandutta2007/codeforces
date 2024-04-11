import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class NeedForBrake implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        String[] name = new String[n];
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            name[i] = nextToken();
            a[i] = nextInt();
        }
        int m = nextInt();
        int[] b = new int[n];
        for (int i = 0; i < m; ++i)
            b[i] = nextInt();
        Arrays.sort(b);
        String we = nextToken();
        int wi;
        for (wi = 0; wi < n; ++wi)
            if (name[wi].equals(we)) break;
        if (wi >= n) throw new RuntimeException();
        int minRes;
        {
            int[] ams = new int[n - 1];
            int amsPos = 0;
            for (int i = 0; i < n; ++i) {
                if (i == wi) continue;
                int most = a[wi] + b[n - 1] - a[i];
                if (name[i].compareTo(name[wi]) < 0)
                    --most;
                int left = -1;
                int right = n - 1;
                while (right - left > 1) {
                    int middle = (left + right) / 2;
                    if (b[middle] <= most)
                        left = middle;
                    else
                        right = middle;
                }
                ams[amsPos++] = left;
            }
            Arrays.sort(ams);
            minRes = 1;
            int at = 0;
            for (int x : ams) {
                if (x >= at) {
                    ++at;
                } else {
                    ++minRes;
                }
            }
        }
        int maxRes;
        {
            int[] ams = new int[n - 1];
            int amsPos = 0;
            for (int i = 0; i < n; ++i) {
                if (i == wi) continue;
                int least = a[wi] + b[0] - a[i];
                if (name[i].compareTo(name[wi]) > 0)
                    ++least;
                int left = 0;
                int right = n;
                while (right - left > 1) {
                    int middle = (left + right) / 2;
                    if (b[middle] < least)
                        left = middle;
                    else
                        right = middle;
                }
                ams[amsPos++] = right;
            }
            Arrays.sort(ams);
            maxRes = n;
            int at = n - 1;
            for (int i = ams.length - 1; i >= 0; --i) {
                int x = ams[i];
                if (x <= at) {
                    --at;
                } else {
                    --maxRes;
                }
            }
        }
        writer.println(minRes + " " + maxRes);
    }

    public static void main(String[] args) {
        new NeedForBrake().run();
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
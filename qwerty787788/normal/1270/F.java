import java.io.*;
import java.util.StringTokenizer;

public class A {
    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) {
        new A().runIO();
    }

    void solve() {
        char[] s = in.next().toCharArray();
        int n = s.length;
        int[] prefSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + (s[i] == '1' ? 1 : 0);
        }
        int[] onesPos = new int[prefSum[n]];
        int it = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                onesPos[it++] = i;
            }
        }
        final int BUBEN = 200;
        long res = 0;
        int[] cnt = new int[(1 + BUBEN) * n + 1];
        int[] lastTime = new int[cnt.length];
        for (int weight = 1; weight <= BUBEN; weight++) {
            int curScore = n;
            lastTime[curScore] = weight;
            cnt[curScore] = 1;
            for (int i = 0; i < n; i++) {
                curScore--;
                if (s[i] == '1') {
                    curScore += weight;
                }
                if (lastTime[curScore] != weight) {
                    lastTime[curScore] = weight;
                    cnt[curScore] = 0;
                }
                res += cnt[curScore];
                cnt[curScore]++;
            }
        }
        for (int i = 0; i < onesPos.length; i++) {
            int firstPos = i == 0 ? 0 : (onesPos[i - 1] + 1);
            for (int j = i; j < onesPos.length; j++) {
                int lastPos = j == onesPos.length - 1 ? (n - 1) : (onesPos[j + 1] - 1);
                int cntOnes = j - i + 1;
                int minLength = cntOnes * (BUBEN + 1);
                int maxLength = lastPos - firstPos + 1;
                int alrLength = onesPos[j] - onesPos[i] + 1;
                if (minLength > n - firstPos) {
                    break;
                }
                for (int weight = BUBEN + 1; ; weight++) {
                    int needLen = cntOnes * weight;
                    if (needLen > maxLength) {
                        break;
                    }
                    if (needLen < alrLength) {
                        continue;
                    }
                    int realMin = Math.max(firstPos, onesPos[j] - needLen + 1);
                    int realMax = Math.min(onesPos[i], lastPos - needLen + 1);
                    res += realMax - realMin + 1;
//                    System.err.println("after weight = " + weight + ", res = " + res);
                }
//                System.err.println(i + " " + j + " " + res);
            }
        }
        out.println(res);
    }

    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
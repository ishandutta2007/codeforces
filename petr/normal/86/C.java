import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Genetic implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        Set<String> all = new HashSet<String>();
        Set<String> finish = new HashSet<String>();
        all.add("");
        int maxLength = 1;
        for (int i = 0; i < m; ++i) {
            String s = nextToken();
            maxLength = Math.max(maxLength, s.length());
            finish.add(s);
            for (int j = 0; j < s.length(); ++j)
                all.add(s.substring(0, j + 1));
        }
        Map<String, Integer> index = new HashMap<String, Integer>();
        int last = 0;
        for (String st : all) {
            index.put(st, last++);
        }
        int[] isFinish = new int[last];
        int[][] next = new int[last][4];
        for (String s : all)
            for (String t : finish)
                if (s.endsWith(t))
                    isFinish[index.get(s)] = Math.max(isFinish[index.get(s)], t.length());
        for (String s : all) {
            int start = index.get(s);
            for (int ch = 0; ch < 4; ++ch) {
                String t = s + "ACGT".charAt(ch);
                while (!all.contains(t))
                    t = t.substring(1);
                next[start][ch] = index.get(t);
            }
        }
        int[][] cnt = new int[last][maxLength];
        cnt[index.get("")][0] = 1;
        for (int len = 0; len < n; ++len) {
            cnt = oneStep(cnt, maxLength, last, isFinish, next);
        }
        int res = 0;
        for (int state = 0; state < last; ++state) {
            res += cnt[state][0];
            if (res >= MODULO)
                res -= MODULO;
        }
        writer.println(res);
    }

    static final int MODULO = 1000000009;

    private int[][] oneStep(int[][] cnt, int maxLength, int last, int[] finish, int[][] next) {
        int[][] newCnt = new int[last][maxLength];
        for (int oldState = 0; oldState < last; ++oldState)
            for (int oldNeed = 0; oldNeed < maxLength; ++oldNeed) {
                for (int ch = 0; ch < 4; ++ch) {
                    int newState = next[oldState][ch];
                    int newNeed = oldNeed + 1;
                    if (newNeed <= finish[newState])
                        newNeed = 0;
                    if (newNeed >= maxLength)
                        continue;
                    newCnt[newState][newNeed] += cnt[oldState][oldNeed];
                    if (newCnt[newState][newNeed] >= MODULO) {
                        newCnt[newState][newNeed] -= MODULO;
                    }
                }
            }
        return newCnt;
    }

    public static void main(String[] args) {
        new Genetic().run();
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
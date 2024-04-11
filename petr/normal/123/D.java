import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class AString implements Runnable {
    static final int INF = 1000000;

    static class IntervalTree {
        int[] subtreeMin;
        int n;

        public IntervalTree(int n) {
            this.n = n;
            subtreeMin = new int[4 * n + 10];
            Arrays.fill(subtreeMin, INF);
        }

        void update(int at, int by) {
            internalUpdate(0, 0, n - 1, at, by);
        }

        private void internalUpdate(int root, int rl, int rr, int at, int by) {
            if (rl == rr)
                subtreeMin[root] = by;
            else {
                int rm = (rl + rr) / 2;
                if (at <= rm)
                    internalUpdate(root * 2 + 1, rl, rm, at, by);
                else
                    internalUpdate(root * 2 + 2, rm + 1, rr, at, by);
                subtreeMin[root] = Math.min(subtreeMin[root * 2 + 1], subtreeMin[root * 2 + 2]);
            }
        }

        int get(int l, int r) {
            return internalGet(0, 0, n - 1, l, r);
        }

        private int internalGet(int root, int rl, int rr, int l, int r) {
            l = Math.max(l, rl);
            r = Math.min(r, rr);
            if (l > r) return INF;
            if (l == rl && r == rr)
                return subtreeMin[root];
            int rm = (rl + rr) / 2;
            return Math.min(internalGet(root * 2 + 1, rl, rm, l, r), internalGet(root * 2 + 2, rm + 1, rr, l, r));
        }
    }

    private void solve() throws IOException {
        String s = nextToken() + (char) ('a' - 1);
        int[] id = new int[s.length()];
        int[] cnt = new int[Math.max(27, s.length())];
        int[] perm = new int[s.length()];
        IntervalTree eqLen = new IntervalTree(s.length() - 1);
        for (int i = 0; i < s.length(); ++i) {
            id[i] = s.charAt(i) - 'a' + 1;
            ++cnt[id[i]];
        }
        int[] ptr = new int[cnt.length];
        ptr[0] = 0;
        for (int i = 0; i + 1 < cnt.length; ++i)
            ptr[i + 1] = ptr[i] + cnt[i];
        for (int i = 0; i < s.length(); ++i) {
            perm[ptr[id[i]]++] = i;
        }
        for (int i = 0; i + 1 < s.length(); ++i)
            if (id[perm[i]] != id[perm[i + 1]])
                eqLen.update(i, 0);
        int len = 1;
        int[] nperm = new int[s.length()];
        int[] nid = new int[s.length()];
        while (len < s.length()) {
            Arrays.fill(cnt, 0);
            for (int x : id) ++cnt[x];
            ptr[0] = 0;
            for (int i = 0; i + 1 < cnt.length; ++i)
                ptr[i + 1] = ptr[i] + cnt[i];
            for (int second = 0; second < s.length(); ++second) {
                int first = (perm[second] - len + s.length()) % s.length();
                nperm[ptr[id[first]]++] = first;
            }
            int lastId = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (i != 0) {
                    int p1 = nperm[i];
                    int p2 = nperm[i - 1];
                    if (id[p1] != id[p2]) {
                        ++lastId;
                    } else {
                        int n1 = (p1 + len) % s.length();
                        int n2 = (p2 + len) % s.length();
                        if (id[n1] != id[n2]) {
                            int pos1 = ptr[id[n1]] - 1;
                            int pos2 = ptr[id[n2]] - 1;
                            eqLen.update(i - 1, len + eqLen.get(Math.min(pos1, pos2), Math.max(pos1, pos2) - 1));
                            ++lastId;
                        }
                    }
                }
                nid[nperm[i]] = lastId;
            }
            {
                int[] tmp = perm;
                perm = nperm;
                nperm = tmp;
                tmp = id;
                id = nid;
                nid = tmp;
            }
            len *= 2;
        }
        int[] stackCnt = new int[s.length()];
        int[] stackLen = new int[s.length()];
        int stackPos = 0;
        int stackTotalLen = 0;
        long res = 0;
        for (int i = 1; i < s.length(); ++i) {
            int cur = perm[i];
            int commonLen = eqLen.get(i - 1, i - 1);
            //System.out.println(cur + " " + commonLen);
            int curLen = s.length() - cur - 1;
            while (stackTotalLen > commonLen) {
                int by = Math.min(stackLen[stackPos - 1], stackTotalLen - commonLen);
                int byCnt = stackCnt[stackPos - 1] + i;
                res += (long) byCnt * (byCnt + 1) / 2 * by;
                stackLen[stackPos - 1] -= by;
                if (stackLen[stackPos - 1] == 0) --stackPos;
                stackTotalLen -= by;
            }
            if (stackTotalLen != commonLen) throw new RuntimeException();
            if (curLen > commonLen) {
                stackCnt[stackPos] = -i;
                stackLen[stackPos] = curLen - commonLen;
                ++stackPos;
                stackTotalLen += curLen - commonLen;
            }
        }
        while (stackTotalLen > 0) {
            int by = stackLen[stackPos - 1];
            int byCnt = stackCnt[stackPos - 1] + s.length();
            res += (long) byCnt * (byCnt + 1) / 2 * by;
            stackLen[stackPos - 1] -= by;
            if (stackLen[stackPos - 1] == 0) --stackPos;
            stackTotalLen -= by;
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new AString().run();
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
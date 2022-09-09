import java.io.*;
import java.util.*;

public class G {
    FastScanner in;
    PrintWriter out;

    int getLenCost(int len, int k) {
        if (len <= 1) {
            return 0;
        }
        return (len - 1 + (k - 2)) / (k - 1);
    }

    void solve() {
        int n = in.nextInt();
        int k =in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        solve(a, k);
    }

    void solve123() {
        Random rnd = new Random(123);
        for (int it = 0; it < 123123; it++) {
            System.err.println("ITER = " + it);
            int n = 3 + rnd.nextInt(10);
            int sum = rnd.nextInt(5) * n;
            int[] a = new int[n];
            for (int i = 0; i < sum; i++) {
                a[rnd.nextInt(a.length)]++;
            }
            int k = 2 + rnd.nextInt(n - 2);
            solve(a, k);
        }
    }

    void solve(int[] a, int k) {
//        System.err.println(Arrays.toString(a) + " " + k);
        int n = a.length;
//        int k = in.nextInt();
//        int[] a = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
//            a[i] = in.nextInt();
            sum += a[i];
        }
        sum /= n;
        int[] balance = new int[n];
        for (int i = 0; i + 1 < n; i++) {
            balance[i + 1] = balance[i] + a[i] - sum;
        }
        List<Balance>[] balances = new List[k];
        for (int i = 0; i < balances.length; i++) {
            balances[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            balances[i % (k - 1)].add(new Balance(i, balance[i]));
        }
        for (int i = 0; i < balances.length; i++) {
            Collections.sort(balances[i]);
        }
        int[] lenOfSameBalance = new int[n];
        for (int i = 0; i < n; i++) {
            int curBalance = balance[i];
            List<Balance> where = balances[(i + 1) % (k - 1)];
            int firstPos = firstPosOfSameBalance(where, i + 1, curBalance);
            if (firstPos == -1) {
                lenOfSameBalance[i] = n;
            } else {
                if (firstPos > i) {
                    lenOfSameBalance[i] = firstPos - i;
                } else {
                    lenOfSameBalance[i] = (n - i) + firstPos;
                }
            }
        }
        final int MAX = 20;
        int[][] len = new int[MAX][n];
        int[][] cost = new int[MAX][n];
        for (int i = 0; i < n; i++) {
            len[0][i] = lenOfSameBalance[i];
            cost[0][i] = getLenCost(lenOfSameBalance[i], k);
//            System.err.println(i + " -> (len = " + len[0][i] + ", cost = " + cost[0][i] + ")");
        }
        for (int i = 1; i < MAX; i++) {
            for (int v = 0; v < n; v++) {
                int nextV = (v + len[i - 1][v]) % n;
                len[i][v] = len[i - 1][v] + len[i - 1][nextV];
                cost[i][v] = cost[i - 1][v] + cost[i - 1][nextV];
                len[i][v] = Math.min(len[i][v], n + 10);
                cost[i][v] = Math.min(cost[i][v], Integer.MAX_VALUE / 3);
            }
        }
        int bestCost = Integer.MAX_VALUE;
        int bestStart = -1;
        for (int start = 0; start < n; start++) {
            int curPos = start;
            int curCost = 0;
            int curLen = 0;
            for (int i = MAX - 1; i >= 0; i--) {
                if (curLen + len[i][curPos] <= n) {
                    int nowLen = len[i][curPos];
                    curCost += cost[i][curPos];
//                    System.err.println("ADD COST " + cost[i][curPos]);
                    curLen += nowLen;
                    curPos = (curPos + nowLen) % n;
                }
            }
            int moreLen = n - curLen;
            curCost += getLenCost(moreLen, k);
//            System.err.println("cost for " + start + " is " + curCost + ", moreLen = " + moreLen);
            if (curCost < bestCost) {
                bestCost = curCost;
                bestStart = start;
            }
        }
        List<int[]> answers = new ArrayList<>();
        int moreLen = n;
        int v = bestStart;
        while (moreLen > 0) {
            int useLen = Math.min(moreLen, len[0][v]);
            makeGood(answers, a, v, useLen, sum, k);
            v = (v + useLen) % n;
            moreLen -= useLen;
        }
        if (answers.size() != bestCost) {
//            System.err.println(answers.size() + ", cost= " + bestCost);
            for (int[] b : answers) {
                System.err.println(Arrays.toString(b));
            }
            throw new AssertionError();
        }
        for (int x : a) {
            if (x != sum) {
                throw new AssertionError(Arrays.toString(a));
            }
        }
        out.println(answers.size());
        for (int[] b : answers) {
            for (int x : b) {
                out.print(x + " ");
            }
            out.println();
        }
    }

    void makeGood(List<int[]> answers, int[] a, int from, int len, int sum, int k) {
        if (len <= 1) {
            return;
        }
//        System.err.println(from + " " + len);
        int curSum = a[from];
        for (int cnt = 1; ; cnt++) {
            int curStart = from + (cnt - 1) * (k - 1) + 1;
            int removeLast = 0;
            for (int i = 0; i < k - 1; i++) {
                if ((cnt - 1) * (k - 1) + 1 + i >= len) {
                    removeLast++;
                    continue;
                }
                int pos = (curStart + i) % a.length;
                curSum += a[pos];
            }
            int totalElems = cnt * (k - 1) + 1;
            totalElems -= removeLast;
            int needSum = totalElems * sum;

            if (needSum <= curSum) {
                int more = curSum - needSum;
                for (int curSeg = cnt - 1; curSeg >= 0; curSeg--) {
                    int segStart = from + curSeg * (k - 1);
                    int nowSum = 0;
                    for (int j = 0; j < k - removeLast; j++) {
                        nowSum += a[(segStart + j) % a.length];
                    }
                    int[] answerArray = new int[k + 1];
                    Arrays.fill(answerArray, sum);
                    answerArray[0] = segStart % a.length;
                    answerArray[answerArray.length - 1] += more;

                    for (int j = answerArray.length - removeLast - 1; j + 1 < answerArray.length; j++) {
                        answerArray[j + 1] = a[(answerArray[0] + j) % a.length];
                    }
                    for (int j = 1; j < answerArray.length - removeLast; j++) {
                        nowSum -= answerArray[j];
                    }
                    if (removeLast != 0 && more != 0) {
                        throw new AssertionError();
                    }
                    answerArray[1] += nowSum;
                    answers.add(answerArray);
                    for (int j = 0; j + 1 < answerArray.length; j++) {
                        a[(answerArray[0] + j) % a.length] = answerArray[j + 1];
                    }
                    more = 0;
                    removeLast = 0;
                }
                makeGood(answers, a, (curStart + k - 2) % a.length, len - cnt * (k - 1), sum, k);
                return;
            }
        }
    }

    int getFirstPosOfBalance(List<Balance> positions, int needBalance) {
        int l = -1, r = positions.size();
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (positions.get(mid).balance >= needBalance) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }

    int firstPosOfSameBalance(List<Balance> positions, int atleastPos, int needBalance) {
        int from = getFirstPosOfBalance(positions, needBalance);
        int to = getFirstPosOfBalance(positions, needBalance + 1);
        if (from == to) {
            return -1;
        }
        int l = from - 1, r = to;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (positions.get(m).pos >= atleastPos) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r != to) {
            return positions.get(r).pos;
        }
        return positions.get(from).pos;
    }

    class Balance implements Comparable<Balance> {
        int pos;
        int balance;

        public Balance(int pos, int balance) {
            this.pos = pos;
            this.balance = balance;
        }

        @Override
        public int compareTo(Balance o) {
            if (balance != o.balance) {
                return Integer.compare(balance, o.balance);
            }
            return Integer.compare(pos, o.pos);
        }


        @Override
        public String toString() {
            return "Balance{" +
                    "pos=" + pos +
                    ", balance=" + balance +
                    '}';
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("G.in"));
            out = new PrintWriter(new File("G.out"));

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

    public static void main(String[] args) {
        new G().runIO();
    }
}
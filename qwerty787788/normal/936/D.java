import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] cnt = new int[]{in.nextInt(), in.nextInt()};
        int t = in.nextInt();
        int[][] pos = new int[2][];
        for (int i = 0; i < pos.length; i++) {
            pos[i] = new int[cnt[i]];
            for (int j = 0; j < pos[i].length; j++) {
                pos[i][j] = in.nextInt();
            }
        }
        ArrayList<Integer> positions = new ArrayList<>();
        positions.add(0);
        for (int i = 0; i < 2; i++) {
            for (int x : pos[i]) {
                positions.add(x + 1);
            }
        }
        positions.add(n + 1);
        Collections.sort(positions);
        ArrayList<Integer> newPos = new ArrayList<>();
        for (int x : positions) {
            if (newPos.size() == 0 || newPos.get(newPos.size() - 1) - x != 0) {
                newPos.add(x);
            }
        }
        positions = newPos;
        int[][] dp = new int[2][positions.size()];
        boolean[][] needChange = new boolean[2][positions.size()];
        for (int i = 0; i < 2; i++) {
            Arrays.fill(dp[i], -1);
        }
        dp[0][0] = dp[1][0] = 0;
        needChange[1][0] = true;
        int[] iter = new int[2];
        for (int index = 0; index + 1 < positions.size(); index++) {
            int curPos = positions.get(index);
            for (int i = 0; i < 2; i++) {
                while (iter[i] < pos[i].length && pos[i][iter[i]] <= curPos) {
                    iter[i]++;
                }
            }
            for (int fr = 0; fr < 2; fr++) {
                int to = 1 - fr;
                if (iter[to] > 0 && pos[to][iter[to] - 1] == curPos) {
                    continue;
                }
                if (dp[fr][index] != -1) {
                    int next = Math.min(t, dp[fr][index]);
                    if (dp[to][index] < next) {
                        dp[to][index] = next;
                        needChange[to][index] = true;
                    }
                }
            }
            int nextPos = positions.get(index + 1);
            for (int i = 0; i < 2; i++) {
                int now = dp[i][index];
                if (now == -1) {
                    continue;
                }
                int nowPos = curPos;
                boolean ok = true;
                for (int it = iter[i]; it != pos[i].length && pos[i][it] <= nextPos; it++) {
                    int go = pos[i][it];
                    now += (go - 1 - nowPos);
                    nowPos = go - 1;
                    if (now >= t) {
                        now -= t;
                    } else {
                        ok = false;
                    }
                }
                if (ok) {
                    now += nextPos - nowPos;
                    dp[i][index + 1] = now;
                }
            }
        }
//        System.err.println(positions);
//        System.err.println(Arrays.deepToString(dp));
        for (int i = 0; i < 2; i++) {
            if (dp[i][dp[i].length - 1] != -1) {
                out.println("Yes");
                int side = i;
                ArrayList<Integer> changes = new ArrayList<>();
                for (int j = positions.size() - 1; j >= 0; j--) {
                    if (needChange[side][j]) {
                        side = 1 - side;
                        changes.add(positions.get(j));
                    }
                }
                out.println(changes.size());
                Collections.reverse(changes);
                for (int x : changes) {
                    out.print(x + " ");
                }
                out.println();
                int chIter = 0;
                Arrays.fill(iter, 0);
                int y = 0;
                int moreTime = t;
                ArrayList<Integer> fireX = new ArrayList<>();
                ArrayList<Integer> fireY = new ArrayList<>();
                while (y != n + 1) {
                    int nextChange = chIter == changes.size() ? (n + 1) : changes.get(chIter);
                    if (nextChange == y) {
                        side = 1 - side;
                        chIter++;
                        continue;
                    }
                    int nextEvent = nextChange;
                    while (iter[side] != pos[side].length && pos[side][iter[side]] < y) {
                        iter[side]++;
                    }
                    if (iter[side] != pos[side].length && pos[side][iter[side]] <= nextChange) {
                        if (y + moreTime >= nextChange) {
                            throw new AssertionError();
                        }
                        nextEvent = y + moreTime;
                        if (moreTime == 0) {
                            iter[side]++;
                            moreTime = t;
                            fireX.add(side + 1);
                            fireY.add(y);
                        }
                    }
                    moreTime = Math.max(0, moreTime - (nextEvent - y));
                    y = nextEvent;
                }
                out.println(fireX.size());
                for (int j = 0; j < fireX.size(); j++) {
                    out.println(fireY.get(j) + " " + fireX.get(j));
                }
                return;
            }
        }
        out.println("No");
    }

    void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

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
        new D().runIO();
    }
}
import java.io.*;
import java.util.*;

public class CF2 {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int r = in.nextInt();
        int c = in.nextInt();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = in.next();
        }
        int[] cntWords = new int[n];
        int[] sumLen = new int[n];
        for (int i = 0; i < n; i++) {
            sumLen[i] = (i == 0 ? 0 : sumLen[i - 1]) + words[i].length();
        }
        int right = 0;
        for (int i = 0; i < n; i++) {
            while (right != n
                    && (sumLen[right] - (i == 0 ? 0 : sumLen[i - 1]) + (right - i)) <= c)
                right++;
            cntWords[i] = right - i;
        }
        int[] answer = new int[n];
        if ((r & 1) == 1) {
            for (int i = 0; i < n; i++)
                answer[i] = cntWords[i];
        }
        for (int j = 1; j <= 30; j++) {
            for (int i = 0; i < n; i++) {
                int next = i + cntWords[i];
                if (next != n) {
                    cntWords[i] += cntWords[next];
                }
            }
            if ((r & (1 << j)) != 0) {
                for (int i = 0; i < n; i++) {
                    int next = i + cntWords[i];
                    answer[i] = cntWords[i] + (next == n ? 0 : answer[next]);
                }
            }
        }
        int bestFr = -1;
        int bestCnt = 0;
        for (int i = 0; i < n; i++) {
            if (answer[i] >= bestCnt) {
                bestFr = i;
                bestCnt = answer[i];
            }
        }
        int alr = 0;
        for (int i = bestFr; i < bestFr + bestCnt; i++) {
            if (alr + words[i].length() < c || (i == bestFr && words[i].length() <= c)) {
                if (i == bestFr) {
                    out.print(words[i]);
                    alr += words[i].length();
                } else {
                    out.print(" " + words[i]);
                    alr += words[i].length() + 1;
                }
            } else {
                out.println();
                out.print(words[i]);
                alr = words[i].length();
            }
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

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
    }

    public static void main(String[] args) {
        new CF2().runIO();
    }
}
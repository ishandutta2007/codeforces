import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int numCases = in.nextInt();
            for (int caseId = 0; caseId < numCases; ++caseId) {
                int n = in.nextInt();
                if (n < 0) return;
                boolean[] sameAsPrev = new boolean[n];
                for (int offset = 0; offset < 2; ++offset) {
                    StringBuilder query = new StringBuilder();
                    int querySize = 0;
                    for (int i = offset; i + 1 < n; i += 2) {
                        ++querySize;
                        query.append(" ");
                        query.append(i + 1);
                        query.append(" ");
                        query.append(i + 2);
                    }
                    if (querySize > 0) {
                        out.println("Q " + querySize + query.toString());
                        out.flush();
                        String ans = in.next();
                        if (ans.equals("-1")) return;
                        for (int i = offset; i + 1 < n; i += 2) {
                            if (ans.charAt(i / 2) == '1') {
                                sameAsPrev[i + 1] = true;
                            }
                        }
                    }
                }
                int[] groupFirst = new int[n + 1];
                int numGroups = 0;
                for (int i = 0; i < n; ++i)
                    if (!sameAsPrev[i]) {
                        groupFirst[numGroups++] = i;
                    }
                groupFirst[numGroups] = n;
                boolean[] sameAsPrev2 = new boolean[numGroups];
                for (int offset = 0; offset < 4; ++offset) {
                    StringBuilder query = new StringBuilder();
                    int querySize = 0;
                    for (int i = offset; i + 2 < numGroups; i += 4) {
                        ++querySize;
                        query.append(" ");
                        query.append(groupFirst[i] + 1);
                        query.append(" ");
                        query.append(groupFirst[i + 2] + 1);
                    }
                    if (querySize > 0) {
                        out.println("Q " + querySize + query.toString());
                        out.flush();
                        String ans = in.next();
                        if (ans.equals("-1")) return;
                        for (int i = offset; i + 2 < numGroups; i += 4) {
                            if (ans.charAt(i / 4) == '1') {
                                sameAsPrev2[i + 2] = true;
                            }
                        }
                    }
                }
                int[] what = new int[numGroups];
                if (numGroups > 0)
                    what[0] = 0;
                if (numGroups > 1)
                    what[1] = 1;
                for (int i = 2; i < numGroups; ++i) {
                    if (sameAsPrev2[i]) what[i] = what[i - 2];
                    else {
                        what[i] = 3 - what[i - 1] - what[i - 2];
                    }
                }
                int[] count = new int[3];
                for (int i = 0; i < numGroups; ++i) {
                    int size = groupFirst[i + 1] - groupFirst[i];
                    count[what[i]] += size;
                }
                out.print("A");
                for (int x : count) out.print(" " + x);
                out.println();
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < numGroups; ++j)
                        if (what[j] == i) {
                            for (int k = groupFirst[j]; k < groupFirst[j + 1]; ++k) {
                                out.print(k + 1 + " ");
                            }
                        }
                    out.println();
                }
                out.flush();
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
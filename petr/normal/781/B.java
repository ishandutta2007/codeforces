import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Set;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.util.Collections;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String[] a = new String[n];
            String[] b = new String[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.next();
                b[i] = in.next();
            }
            List<String> varA = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                varA.add(a[i].substring(0, 3));
            }
            Collections.sort(varA);
            Set<String> badA = new HashSet<>();
            for (int i = 0; i + 1 < n; ++i) {
                if (varA.get(i).equals(varA.get(i + 1))) badA.add(varA.get(i));
            }
            int[] queue = new int[n];
            boolean[] bad = new boolean[n];
            int qt = 0;
            int qh = 0;
            Map<String, Integer> goodA = new HashMap<>();
            for (int i = 0; i < n; ++i) {
                if (badA.contains(a[i].substring(0, 3))) {
                    queue[qh++] = i;
                    bad[i] = true;
                } else {
                    goodA.put(a[i].substring(0, 3), i);
                }
            }
            String[] res = new String[n];
            Set<String> seen = new HashSet<>();
            while (qt < qh) {
                int i = queue[qt++];
                res[i] = a[i].substring(0, 2) + b[i].substring(0, 1);
                if (!seen.add(res[i])) {
                    out.println("NO");
                    return;
                }
                Integer conv = goodA.get(res[i]);
                if (conv != null) {
                    if (bad[conv]) throw new RuntimeException();
                    bad[conv] = true;
                    queue[qh++] = conv;
                }
            }
            for (int i = 0; i < n; ++i)
                if (!bad[i]) {
                    res[i] = a[i].substring(0, 3);
                    if (!seen.add(res[i])) {
                        throw new RuntimeException();
                    }
                }
            out.println("YES");
            for (String x : res) {
                out.println(x);
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
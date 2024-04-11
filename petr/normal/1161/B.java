import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Set;
import java.io.IOException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        static Random random = new Random(573453151L + System.currentTimeMillis());
        static int BUBEN = random.nextInt() * 2 + 1;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            Set<TaskB.Chord> chords = new HashSet<>();
            for (int i = 0; i < m; ++i) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                int first = a;
                int len = b - a;
                if (len < 0) len += n;
                if (len > n - len) {
                    first = b;
                    len = n - len;
                }
                chords.add(new TaskB.Chord(first, len));
                if (len == n - len) {
                    chords.add(new TaskB.Chord(b, len));
                }
            }
            boolean[] prime = new boolean[n + 1];
            Arrays.fill(prime, true);
            TaskB.Chord tmp = new TaskB.Chord(0, 0);
            outer:
            for (int g = 2; g <= n; ++g)
                if (prime[g]) {
                    if (n % g != 0) continue;
                    for (int i = g * 2; i <= n; i += g) prime[i] = false;
                    int delta = n / g;
                    for (TaskB.Chord c : chords) {
                        tmp.len = c.len;
                        tmp.first = c.first + delta;
                        if (tmp.first >= n) tmp.first -= n;
                        if (!chords.contains(tmp)) continue outer;
                    }
                    out.println("Yes");
                    return;
                }
            out.println("No");
        }

        static class Chord {
            int first;
            int len;

            public Chord(int first, int len) {
                this.first = first;
                this.len = len;
            }

            public boolean equals(Object o) {
                TaskB.Chord chord = (TaskB.Chord) o;
                return first == chord.first &&
                        len == chord.len;
            }

            public int hashCode() {
                return first * BUBEN + len;
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
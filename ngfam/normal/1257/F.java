import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.TreeMap;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ngfam
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        FMakeThemSimilar solver = new FMakeThemSimilar();
        solver.solve(1, in, out);
        out.close();
    }

    static class FMakeThemSimilar {
        static int MaxVal = (1 << 15) - 1;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int a[] = in.nextIntArray(n);

            Map<State, Integer> mymap = new TreeMap<State, Integer>(new MyStateComp());

            for (int mask = 0; mask <= MaxVal; ++mask) {
                State now = new State();
                now.a = new ArrayList<>();
                for (int i = 1; i < n; ++i) {
                    now.a.add(Integer.bitCount((a[i] & MaxVal) ^ mask) - Integer.bitCount((a[i - 1] & MaxVal) ^ mask));
                }
                if (mymap.containsKey(now)) continue;
                mymap.put(now, mask);
            }

            for (int mask = 0; mask <= MaxVal; ++mask) {
                State now = new State();
                now.a = new ArrayList<>();
                for (int i = 0; i < n - 1; ++i) {
                    now.a.add(Integer.bitCount((a[i] >> 15) ^ (mask)) - Integer.bitCount((a[i + 1] >> 15) ^ (mask)));
                }
                if (mymap.containsKey(now)) {
                    int ans = (mask << 15) ^ mymap.get(now);
                    out.println(ans);
                    return;
                }
            }
            out.println(-1);
        }

        class State implements Comparable<State> {
            ArrayList<Integer> a;

            public int compareTo(State rhs) {
                for (int i = 0; i < a.size(); ++i) {
                    if (a.get(i) < rhs.a.get(i)) return -1;
                    if (a.get(i) > rhs.a.get(i)) return 1;
                }
                return 0;
            }

        }

        class MyStateComp implements Comparator<State> {
            public int compare(State lhs, State rhs) {
                return lhs.compareTo(rhs);
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int[] pos = new int[10];

        void move(int subset, InputReader in, PrintWriter out) {
            out.print("next");
            for (int i = 0; i < pos.length; ++i)
                if ((subset & (1 << i)) != 0) {
                    out.print(" ");
                    out.print(i);
                }
            out.println();
            out.flush();
            int groups = in.nextInt();
            for (int g = 0; g < groups; ++g) {
                String desc = in.next();
                for (int i = 0; i < desc.length(); ++i) pos[desc.charAt(i) - '0'] = g;
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            while (true) {
                move(3, in, out);
                move(1, in, out);
                if (pos[0] == pos[1]) {
                    break;
                }
            }
            while (true) {
                move((1 << 10) - 1, in, out);
                if (pos[0] == pos[2]) {
                    break;
                }
            }
            out.println("done");
            out.flush();

        /*for (int s = 1; s <= 1000; ++s) {
            for (t = 1; t < s; ++t) {
                c = s - t;
                System.out.println(t + " " + c);
                remaining = 3 * s;
                Arrays.fill(pos, 0);
                int period = 0;
                while (true) {
                    ++period;
                    move(3);
                    move(1);
                    if (pos[0] == pos[1]) {
                        break;
                    }
                }
                while (true) {
                    move((1 << 10) - 1);
                    if (pos[0] == pos[2]) {
                        break;
                    }
                }

                for (int i = 0; i < pos.length; ++i) {
                    if (pos[i] != t) throw new RuntimeException();
                }
            }
        }*/
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
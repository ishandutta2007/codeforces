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
        static final int AND = 1;
        static final int OR = 2;
        static final int XOR = 3;
        static final int NOT = 4;
        static final int IN = 5;
        int[] kind;
        int[] arg1;
        int[] arg2;
        int[] value;
        int[] res;
        int[] seq;
        int[] rseq;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            kind = new int[n];
            arg1 = new int[n];
            arg2 = new int[n];
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                if (s.equals("AND")) kind[i] = AND;
                else if (s.equals("OR")) kind[i] = OR;
                else if (s.equals("XOR")) kind[i] = XOR;
                else if (s.equals("NOT")) kind[i] = NOT;
                else if (s.equals("IN")) kind[i] = IN;
                else throw new RuntimeException();
                arg1[i] = in.nextInt();
                arg2[i] = -1;
                if (kind[i] != IN) {
                    --arg1[i];
                    if (kind[i] != NOT) {
                        arg2[i] = in.nextInt() - 1;
                    }
                }
            }
            seq = new int[n];
            int tail = 0;
            int head = 1;
            seq[0] = 0;
            while (tail < head) {
                int cur = seq[tail++];
                if (kind[cur] == IN) continue;
                seq[head++] = arg1[cur];
                if (arg2[cur] >= 0) seq[head++] = arg2[cur];
            }
            if (tail != n) throw new RuntimeException();

            rseq = new int[n];
            for (int i = 0; i < n; ++i) {
                rseq[i] = seq[n - 1 - i];
            }
            value = new int[n];

            for (int i : rseq) {
                switch (kind[i]) {
                    case IN:
                        value[i] = arg1[i];
                        break;
                    case NOT:
                        value[i] = 1 - value[arg1[i]];
                        break;
                    case AND:
                        value[i] = value[arg1[i]] & value[arg2[i]];
                        break;
                    case OR:
                        value[i] = value[arg1[i]] | value[arg2[i]];
                        break;
                    case XOR:
                        value[i] = value[arg1[i]] ^ value[arg2[i]];
                        break;
                    default:
                        throw new RuntimeException();
                }
            }

            res = new int[n];
            res[0] = 1 - value[0];
            for (int i : seq) {
                if (kind[i] == IN) continue;
                if (res[i] == value[0]) {
                    res[arg1[i]] = value[0];
                    if (arg2[i] >= 0) res[arg2[i]] = value[0];
                    continue;
                }
                switch (kind[i]) {
                    case NOT:
                        res[arg1[i]] = res[i];
                        break;
                    case AND:
                        if (((1 - value[arg1[i]]) & value[arg2[i]]) != value[i]) {
                            res[arg1[i]] = res[i];
                        } else {
                            res[arg1[i]] = value[0];
                        }
                        if (((1 - value[arg2[i]]) & value[arg1[i]]) != value[i]) {
                            res[arg2[i]] = res[i];
                        } else {
                            res[arg2[i]] = value[0];
                        }
                        break;
                    case OR:
                        if (((1 - value[arg1[i]]) | value[arg2[i]]) != value[i]) {
                            res[arg1[i]] = res[i];
                        } else {
                            res[arg1[i]] = value[0];
                        }
                        if (((1 - value[arg2[i]]) | value[arg1[i]]) != value[i]) {
                            res[arg2[i]] = res[i];
                        } else {
                            res[arg2[i]] = value[0];
                        }
                        break;
                    case XOR:
                        if (((1 - value[arg1[i]]) ^ value[arg2[i]]) != value[i]) {
                            res[arg1[i]] = res[i];
                        } else {
                            res[arg1[i]] = value[0];
                        }
                        if (((1 - value[arg2[i]]) ^ value[arg1[i]]) != value[i]) {
                            res[arg2[i]] = res[i];
                        } else {
                            res[arg2[i]] = value[0];
                        }
                        break;
                    default:
                        throw new RuntimeException();
                }
            }

            for (int i = 0; i < n; ++i) if (kind[i] == IN) out.print(res[i]);
            out.println();
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
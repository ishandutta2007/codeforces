import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Agostinho Junior (junior94)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    OutputWriter out;
    InputReader in;
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        this.in = in; this.out = out;
        int N = in.readInt();
        int M = in.readInt();
        Integer[] a = new Integer[N];
        Integer[] b = new Integer[M];
        for (int i = 0; i < N; i++) {
            a[i] = in.readInt();
        }
        for (int i = 0; i < M; i++) {
            b[i] = in.readInt();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        final int INF = (int)1e9;
        long ans = 0;
        int ai = 0;
        int bi = M - 1;
        while (a[ai] < b[bi]) {
            int nextA = Math.min(b[bi], ai < N - 1 ? a[ai + 1] : INF);
            int nextB = Math.max(a[ai], bi > 0 ? b[bi - 1] : -1);
            if ((ai + 1) < (M - bi)) {
                ans += 1L * (nextA - a[ai]) * (ai + 1);
                if (ai == N - 1) {
                    break;
                }
                ai++;
            } else {
                ans += 1L * (b[bi] - nextB) * (M - bi);
                if (bi == 0) {
                    break;
                }
                bi--;
            }
        }
        out.print(ans);
    }
}

class OutputWriter {
    private PrintWriter output;
    public OutputWriter() {
        this(System.out);
    }
    public OutputWriter(OutputStream out) {
        output = new PrintWriter(out);
    }
    public OutputWriter(Writer writer) {
        output = new PrintWriter(writer);
    }
    public void print(Object o) {
        output.print(o);
    }

    public void close() {
        output.close();
    }
}

class InputReader {
    private BufferedReader input;
    private StringTokenizer line = new StringTokenizer("");
    public InputReader() {
        this(System.in);
    }
    public InputReader(InputStream in) {
        input = new BufferedReader(new InputStreamReader(in));
    }
    public InputReader(String s) {
        try {
            input = new BufferedReader(new FileReader(s));
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }
    public void fill() {
        try {
            if(!line.hasMoreTokens()) line = new StringTokenizer(input.readLine());
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public int readInt() {
        fill();
        return Integer.parseInt(line.nextToken());
    }
}
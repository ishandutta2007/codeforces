import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int sa = 0;
        int sb = 0;
        int[] seq = new int[n];
        int nseq = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = in.nextInt();
            int[] a = new int[cnt];
            for (int j = 0; j < cnt; ++j) a[j] = in.nextInt();
            int half = cnt / 2;
            for (int j = 0; j < half; ++j) {
                sa += a[j];
                sb += a[cnt - 1 - j];
            }
            if (cnt % 2 != 0) {
                seq[nseq++] = a[half];
            }
        }
        seq = Arrays.copyOf(seq, nseq);
        Arrays.sort(seq);
        for (int i = 0; i < seq.length; ++i)
            if (i % 2 == 0) {
                sa += seq[seq.length - 1 - i];
            } else {
                sb += seq[seq.length - 1 - i];
            }
        out.println(sa + " " + sb);
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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
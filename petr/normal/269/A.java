import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    static class MagicBox {
        int k;
        int a;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        MagicBox[] b = new MagicBox[n];
        for (int i = 0; i < n; ++i) {
            b[i] = new MagicBox();
            b[i].k = in.nextInt();
            b[i].a = in.nextInt();
        }
        Random r = new Random(System.currentTimeMillis() + 594735943);
        for (int i = 0; i < n; ++i) {
            int j = i + r.nextInt(n - i);
            MagicBox tmp = b[i];
            b[i] = b[j];
            b[j] = tmp;
        }
        Arrays.sort(b, new Comparator<MagicBox>() {
            @Override
            public int compare(MagicBox o1, MagicBox o2) {
                return o1.k - o2.k;
            }
        });
        int k = 0;
        int need = 0;
        for (MagicBox m : b) {
            int delta = m.k - k;
            while (delta > 0 && need > 1) {
                --delta;
                need = (need + 3) / 4;
            }
            k = m.k;
            need = Math.max(need, m.a);
        }
        ++k;
        need = (need + 3) / 4;
        while (need > 1) {
            ++k;
            need = (need + 3) / 4;
        }
        out.println(k);
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

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
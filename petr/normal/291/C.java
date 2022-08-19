import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] ips = new int[n];
        for (int i = 0; i < n; ++i) {
            String ip = in.next() + ".";
            int start = 0;
            int block = 0;
            for (int j = 0; j < ip.length(); ++j)
                if (ip.charAt(j) == '.') {
                    ++block;
                    ips[i] += Integer.parseInt(ip.substring(start, j)) << (8 * (4 - block));
                    start = j + 1;
                }
        }
        Random random = new Random(System.currentTimeMillis() + 4971543153L);
        for (int i = 0; i < n; ++i) {
            int j = i + random.nextInt(n - i);
            int tmp = ips[i];
            ips[i] = ips[j];
            ips[j] = tmp;
        }
        Arrays.sort(ips);
        int mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            int count = 1;
            for (int j = 1; j < n; ++j) {
                if ((ips[j] & mask) != (ips[j - 1] & mask))
                    ++count;
            }
            if (count == k) {
                for (int block = 3; block >= 0; --block) {
                    out.print((mask >> (8 * block)) & 255);
                    if (block > 0) out.print(".");
                }
                out.println();
                return;
            }
        }
        out.println(-1);
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
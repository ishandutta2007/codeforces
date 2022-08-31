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
		TaskG1 solver = new TaskG1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG1 {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int a1 = 3621;
        int a2 = 4631;
        int p1 = 1328463329;
        int p2 = 1274368201;
        String s = in.next();
        int n = in.nextInt();
        long[] allHashes = new long[s.length() * (s.length() + 1) / 2];
        int cntAll = 0;
        {
            int ptr = 0;
            for (int left = 0; left < s.length(); ++left) {
                long h1 = 0;
                long h2 = 0;
                for (int right = left; right < s.length(); ++right) {
                    h1 = (h1 * a1 + s.charAt(right)) % p1;
                    h2 = (h2 * a2 + s.charAt(right)) % p2;
                    allHashes[ptr++] = (h1 << 32) + h2;
                }
            }
            if (ptr != allHashes.length) throw new RuntimeException();
            Arrays.sort(allHashes);
            for (int i = 0; i < allHashes.length; ++i)
                if (i == 0 || allHashes[i] != allHashes[i - 1])
                    allHashes[cntAll++] = allHashes[i];
        }
        for (int i = 0; i < n; ++i) {
            String p = in.next();
            int l = in.nextInt();
            int r = in.nextInt();
            long[] hashes = new long[p.length() * (p.length() + 1) / 2];
            int ptr = 0;
            for (int left = 0; left < p.length(); ++left) {
                long h1 = 0;
                long h2 = 0;
                for (int right = left; right < p.length(); ++right) {
                    h1 = (h1 * a1 + p.charAt(right)) % p1;
                    h2 = (h2 * a2 + p.charAt(right)) % p2;
                    hashes[ptr++] = (h1 << 32) + h2;
                }
            }
            if (ptr != hashes.length) throw new RuntimeException();
            Arrays.sort(hashes);
            ptr = 0;
            int newCntAll = 0;
            for (int j = 0; j < cntAll; ++j) {
                long h = allHashes[j];
                while (ptr < hashes.length && hashes[ptr] < h) ++ptr;
                int times = 0;
                while (ptr < hashes.length && hashes[ptr] == h) {
                    ++ptr;
                    ++times;
                }
                if (times >= l && times <= r) {
                    allHashes[newCntAll++] = h;
                }
            }
            cntAll = newCntAll;
        }
        out.println(cntAll);
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
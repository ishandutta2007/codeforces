import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
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
    static class Candidate {
        boolean bribed = false;
        boolean forced = false;
        int a;
        int b;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Candidate[] candidates = new Candidate[n];
        for (int i = 0; i < n; ++i) {
            candidates[i] = new Candidate();
            candidates[i].a = in.nextInt();
            candidates[i].b = in.nextInt();
        }
        int maxCand = 1;
        for (Candidate c : candidates) maxCand = Math.max(maxCand, c.a + 1);
        int[] cntCand = new int[maxCand];
        for (int i = 0; i < n; ++i) ++cntCand[candidates[i].a];
        Candidate[][] perCand = new Candidate[maxCand][];
        for (int i = 0; i < maxCand; ++i) perCand[i] = new Candidate[cntCand[i]];
        Arrays.fill(cntCand, 0);
        for (int i = 0; i < n; ++i) {
            perCand[candidates[i].a][cntCand[candidates[i].a]++] = candidates[i];
        }
        for (int i = 0; i < maxCand; ++i) sortArr(perCand[i]);
        Arrays.sort(perCand, 1, perCand.length, new Comparator<Candidate[]>() {
            @Override
            public int compare(Candidate[] o1, Candidate[] o2) {
                return o2.length - o1.length;
            }
        });
        Candidate[] nonzero = new Candidate[n - perCand[0].length];
        int ptr = 0;
        long totalCost = 0;
        for (int i = 0; i < candidates.length; ++i) if (candidates[i].a != 0) {
            nonzero[ptr++] = candidates[i];
            candidates[i].bribed = true;
            totalCost += candidates[i].b;
        }
        long res = Long.MAX_VALUE;
        sortArr(nonzero);
        int upto = 0;
        for (int votesForUs = n; votesForUs >= Math.max(1, perCand[0].length); --votesForUs) {
            if (votesForUs < n) {
                while (ptr > 0 && nonzero[ptr - 1].forced) {
                    --ptr;
                }
                if (ptr > 0) {
                    nonzero[ptr - 1].bribed = false;
                    totalCost -= nonzero[ptr - 1].b;
                    --ptr;
                }
            }
            while (upto + 1 < perCand.length && perCand[upto + 1].length >= votesForUs) {
                ++upto;
            }
            for (int i = 1; i <= upto; ++i) {
                Candidate[] tmp = perCand[i];
                Candidate need = tmp[tmp.length - votesForUs];
                need.forced = true;
                if (!need.bribed) {
                    need.bribed = true;
                    totalCost += need.b;
                    while (ptr > 0 && nonzero[ptr - 1].forced) {
                        --ptr;
                    }
                    if (ptr > 0) {
                        nonzero[ptr - 1].bribed = false;
                        totalCost -= nonzero[ptr - 1].b;
                        --ptr;
                    }
                }
            }
            res = Math.min(res, totalCost);
        }
        out.println(res);
    }

    static final Comparator<Candidate> COMPARATOR = new Comparator<Candidate>() {
        @Override
        public int compare(Candidate o1, Candidate o2) {
            return o1.b - o2.b;
        }
    };

    private void sortArr(Candidate[] candidates) {
        Arrays.sort(candidates, COMPARATOR);
    }
}

class InputReader {
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
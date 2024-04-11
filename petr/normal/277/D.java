import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final long PROB_DENOM = (long) 1e6;

    static class Problem implements Comparable<Problem> {
        int scoreSmall;
        int scoreLarge;
        int timeSmall;
        int timeLarge;
        int probFail;

        public int compareTo(Problem o) {
            long zLast = (PROB_DENOM - probFail) * PROB_DENOM * (timeLarge + o.timeLarge) + (probFail * (PROB_DENOM - o.probFail)) * o.timeLarge;
            long zFirst = (PROB_DENOM - o.probFail) * PROB_DENOM * (timeLarge + o.timeLarge) + (o.probFail * (PROB_DENOM - probFail)) * timeLarge;
            return Long.signum(zFirst - zLast);
        }
    }

    static class Sol {
        long bestScore;
        double bestPenalty;
    }



    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int t = in.nextInt();
        Problem[] problems = new Problem[n];
        for (int i = 0; i < n; ++i) {
            problems[i] = new Problem();
            problems[i].scoreSmall = in.nextInt();
            problems[i].scoreLarge = in.nextInt();
            problems[i].timeSmall = in.nextInt();
            problems[i].timeLarge = in.nextInt();
            problems[i].probFail = (int) Math.round(PROB_DENOM * in.nextDouble());
        }
        Arrays.sort(problems);
        Sol[] sols = new Sol[t + 1];
        sols[0] = new Sol();
        for (int i = 1; i <= t; ++i) {
            sols[i] = new Sol();
            sols[i].bestScore = -1;
            sols[i].bestPenalty = 0;
        }
        for (Problem p : problems) {
            for (int spent = t; spent >= 0; --spent) if (sols[spent].bestScore >= 0) {
                if (spent + p.timeSmall <= t) {
                    long nScore = sols[spent].bestScore + p.scoreSmall * PROB_DENOM;
                    double nPenalty = sols[spent].bestPenalty + p.timeSmall;
                    int nSpent = spent + p.timeSmall;
                    if (nScore > sols[nSpent].bestScore || (nScore == sols[nSpent].bestScore && nPenalty < sols[nSpent].bestPenalty)) {
                        sols[nSpent].bestScore = nScore;
                        sols[nSpent].bestPenalty = nPenalty;
                    }
                }
                if (spent + p.timeSmall + p.timeLarge <= t) {
                    long nScore = sols[spent].bestScore + p.scoreSmall * PROB_DENOM + p.scoreLarge * (PROB_DENOM - p.probFail);
                    int nSpent = spent + p.timeSmall + p.timeLarge;
                    double nPenalty = (sols[spent].bestPenalty + p.timeSmall) * p.probFail / (double) PROB_DENOM + nSpent * (PROB_DENOM - p.probFail) / (double) PROB_DENOM;
                    if (nScore > sols[nSpent].bestScore || (nScore == sols[nSpent].bestScore && nPenalty < sols[nSpent].bestPenalty)) {
                        sols[nSpent].bestScore = nScore;
                        sols[nSpent].bestPenalty = nPenalty;
                    }
                }
            }
        }
        long resScore = -1;
        double resPenalty = 0;
        for (Sol sol : sols) {
            if (sol.bestScore > resScore || (sol.bestScore == resScore && sol.bestPenalty < resPenalty)) {
                resScore = sol.bestScore;
                resPenalty = sol.bestPenalty;
            }
        }
        out.printf("%.10f %.10f\n", resScore / (double) PROB_DENOM, resPenalty);
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

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}
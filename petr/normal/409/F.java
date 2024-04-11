import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = "1 1\n" +
                "2 1\n" +
                "3 1\n" +
                "4 2\n" +
                "5 1\n" +
                "6 2\n" +
                "7 1\n" +
                "8 5\n" +
                "9 2\n" +
                "10 2\n" +
                "11 1\n" +
                "12 5\n" +
                "13 1\n" +
                "14 2\n" +
                "15 1\n" +
                "16 14\n" +
                "17 1\n" +
                "18 5\n" +
                "19 1\n" +
                "20 5\n" +
                "21 2\n" +
                "22 2\n" +
                "23 1\n" +
                "24 15\n" +
                "25 2\n" +
                "26 2\n" +
                "27 5\n" +
                "28 4\n" +
                "29 1\n" +
                "30 4\n" +
                "31 1\n" +
                "32 51\n" +
                "33 1\n" +
                "34 2\n" +
                "35 1\n" +
                "36 14\n" +
                "37 1\n" +
                "38 2\n" +
                "39 2\n" +
                "40 14\n" +
                "41 1\n" +
                "42 6\n" +
                "43 1\n" +
                "44 4\n" +
                "45 2\n" +
                "46 2\n" +
                "47 1\n" +
                "48 52\n" +
                "49 2\n" +
                "50 5\n" +
                "51 1\n" +
                "52 5\n" +
                "53 1\n" +
                "54 15\n" +
                "55 2\n" +
                "56 13\n" +
                "57 2\n" +
                "58 2\n" +
                "59 1\n" +
                "60 13\n" +
                "61 1\n" +
                "62 2\n" +
                "63 4\n" +
                "64 267";
        int n = in.nextInt();
        out.println(s.split("\n")[n - 1].split(" ")[1]);
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
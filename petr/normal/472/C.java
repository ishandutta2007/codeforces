import java.io.InputStreamReader;
import java.io.IOException;
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
    static class Person {
        String word;
        int index;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Person[] persons = new Person[2 * n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 2; ++j) {
                persons[i * 2 + j] = new Person();
                persons[i * 2 + j].word = in.next();
                persons[i * 2 + j].index = i + 1;
            }
        Arrays.sort(persons, new Comparator<Person>() {
            @Override
            public int compare(Person o1, Person o2) {
                return o1.word.compareTo(o2.word);
            }
        });
        int[] perm = new int[n];
        for (int i = 0; i < n; ++i) {
            perm[i] = in.nextInt();
        }
        int pos = 0;
        for (Person p : persons) {
            if (pos < n && perm[pos] == p.index) ++pos;
        }
        if (pos == n) out.println("YES"); else out.println("NO");
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}
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
    static class Student implements Comparable<Student> {
        int when;
        int who;

        Student(int when, int who) {
            this.when = when;
            this.who = who;
        }

        public int compareTo(Student student) {
            return when - student.when;
        }
    }
    
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Student[] students = new Student[m];
        int[] answers = new int[n];
        int ptr = 0;
        int carTime = 0;
        for (int i = 0; i < n; ++i) {
            carTime = Math.max(carTime, in.nextInt());
            int exitTime = in.nextInt();
            students[ptr++] = new Student(exitTime, i); 
            if (ptr == m || i + 1 == n) {
                Arrays.sort(students, 0, ptr);
                int carAt = 0;
                for (int j = 0; j < ptr;) {
                    int jj = j;
                    while (jj < ptr && students[jj].when == students[j].when) ++jj;
                    int distance = students[j].when - carAt;
                    carTime += distance;
                    carAt += distance;
                    for (int k = j; k < jj; ++k)
                        answers[students[k].who] = carTime;
                    carTime += 1 + (jj - j) / 2;
                    j = jj;
                }
                carTime += carAt;
                ptr = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(answers[i]);
        }
        out.println();
	}
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

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
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    static class Creature implements Comparable<Creature> {
        int mass;
        int velocity;
        int id;

        Creature(int mass, int velocity, int id) {
            this.mass = mass;
            this.velocity = velocity;
            this.id = id;
        }

        public int compareTo(Creature o) {
            if (mass != o.mass) {
                return o.mass - mass;
            }
            return o.velocity - velocity;
        }
    }

	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int h = in.nextInt();
        Creature[] c = new Creature[n];
        int[] mass = new int[n];
        int[] velocity = new int[n];
        for (int i = 0; i < n; i++) {
            mass[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            velocity[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            c[i] = new Creature(mass[i], velocity[i], i);
        }
        Arrays.sort(c);
        double left = 0;
        double right = 2e9;
        for (int it = 0; it < 100; it++) {
            double mid = (left + right) * .5;
            int current = k;
            for (int i = 0; i < n && current > 0; i++) {
                if (current * h < mid * c[i].velocity) {
                    --current;
                }
            }
            if (current == 0) {
                right = mid;
            } else {
                left = mid;
            }
        }
        List<Integer> answer = new ArrayList<Integer>();
        int current = k;
        for (int i = 0; i < n && current > 0; i++) {
            if (current * h < right * c[i].velocity) {
                --current;
                answer.add(c[i].id + 1);
            }
        }
        Collections.reverse(answer);
        out.printArray(ArrayUtils.toPrimitiveArray(answer));
	}
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }

    public void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                print(' ');
            }
            print(a[i]);
        }
        println();
    }


}

class ArrayUtils {

    static public int[] toPrimitiveArray(List<Integer> list) {
        int[] ret = new int[list.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = list.get(i);
        }
        return ret;
    }

    static public long[] toPrimitiveArray(List<Long> list) {
        long[] ret = new long[list.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = list.get(i);
        }
        return ret;
    }

    static public double[] toPrimitiveArray(List<Double> list) {
        double[] ret = new double[list.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = list.get(i);
        }
        return ret;
    }

    }
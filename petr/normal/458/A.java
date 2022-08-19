import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
    static class Desc {
        BigInteger ones;
        BigInteger qs;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        Desc a1 = parseNumber(in);
        Desc a2 = parseNumber(in);
        if (a1.ones.equals(a2.ones) && a1.qs.equals(a2.qs)) {
            out.println("=");
            return;
        }
        if (a1.ones.compareTo(a2.ones) <= 0 && a1.qs.compareTo(a2.qs) <= 0) {
            out.println("<");
            return;
        }
        if (a1.ones.compareTo(a2.ones) >= 0 && a1.qs.compareTo(a2.qs) >= 0) {
            out.println(">");
            return;
        }
        boolean inv = false;
        if (a1.ones.compareTo(a2.ones) > 0) {
            inv = true;
            Desc tmp = a1;
            a1 = a2;
            a2 = tmp;
        }
        BigInteger p = a2.ones.subtract(a1.ones);
        BigInteger q = a1.qs.subtract(a2.qs);
        BigInteger num = p.add(p).subtract(q);
        BigInteger den = q;
        if (num.compareTo(BigInteger.ZERO) <= 0) {
            out.println(inv ? "<" : ">");
            return;
        }
        num = num.multiply(num);
        den = den.multiply(den);
        int res = den.multiply(BigInteger.valueOf(5)).compareTo(num);
        if (res > 0) {
            out.println(inv ? "<" : ">");
        } else if (res < 0) {
            out.println(inv ? ">" : "<");
        } else {
            out.println("=");
        }
    }

    private Desc parseNumber(InputReader in) {
        String s = in.next();
        while (s.length() < 2) s = "0" + s;
        BigInteger first = new BigInteger(s.substring(0, 1));
        BigInteger second = new BigInteger(s.substring(1, 2));
        for (int i = 2; i < s.length(); i += 20) {
            long nfmf = 1;
            long nfms = 0;
            long nsmf = 0;
            long nsms = 1;
            long ef = 0;
            long es = 0;
            for (int j = i; j < s.length() && j < i + 20; ++j) {
                long et = ef;
                long emf = nfmf;
                long ems = nfms;
                if (s.charAt(j) == '1') ++et;
                nfmf += nsmf;
                nfms += nsms;
                ef += es;
                nsmf = emf;
                nsms = ems;
                es = et;
            }
            BigInteger nfirst = first.multiply(BigInteger.valueOf(nfmf)).add(second.multiply(BigInteger.valueOf(nfms))).add(BigInteger.valueOf(ef));
            BigInteger nsecond = first.multiply(BigInteger.valueOf(nsmf)).add(second.multiply(BigInteger.valueOf(nsms))).add(BigInteger.valueOf(es));
            first = nfirst;
            second = nsecond;
        }
        Desc res = new Desc();
        res.ones = second;
        res.qs = first;
        return res;
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

}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Coffin implements Runnable {
    private void solve() throws IOException {
        int a = nextInt();
        int b = nextInt();
        int l = nextInt();
        if (l <= a || l <= b) {
            writer.println(Math.min(l, Math.min(a, b)));
            return;
        }
        double[] koef = new double[5];
        koef[4] = -a - l;
        koef[3] = -2 * b;
        koef[2] = 6 * l;
        koef[1] = -2 * b;
        koef[0] = a - l;
        List<Double> zeroes = findZeroes(koef);
        zeroes.add(0.0);
        zeroes.add(1.0);
        double res = l;
        for (double u : zeroes) {
            double cur = b * (1 - u * u) / (1 + u * u) + a * 2 * u / (1 + u * u) - l * 2 * u * (1 - u * u) / (1 + u * u) / (1 + u * u);
            res = Math.min(res, cur);
        }
        if (res < 0.5e-7) {
            writer.println("My poor head =(");
        } else {
            writer.println(res);
        }
    }

    private double eval(double[] koef, double x) {
        double res = 0.0;
        for (int i = koef.length - 1; i >= 0; --i) {
            res = res * x + koef[i];
        }
        return res;
    }

    private List<Double> findZeroes(double[] koef) {
        List<Double> res = new ArrayList<Double>();
        if (koef.length == 3) {
            double a = koef[2];
            double b = koef[1];
            double c = koef[0];
            double d = b * b - 4 * a * c;
            if (d < 0) {
                return res;
            }
            d = Math.sqrt(d);
            double sol = (-b + d) / (2 * a);
            if (sol > 0.0 && sol < 1.0) res.add(sol);
            sol = (-b - d) / (2 * a);
            if (sol > 0.0 && sol < 1.0) res.add(sol);
            Collections.sort(res);
            return res;
        }
        double[] deriv = new double[koef.length - 1];
        for (int i = 1; i < koef.length; ++i)
            deriv[i - 1] = i * koef[i];
        List<Double> derivZeroes = findZeroes(deriv);
        derivZeroes.add(0.0);
        derivZeroes.add(1.0);
        Collections.sort(derivZeroes);
        double[] val = new double[derivZeroes.size()];
        for (int i = 0; i < derivZeroes.size(); ++i) {
            double x = derivZeroes.get(i);
            val[i] = eval(koef, x);
            if (val[i] == 0) res.add(x);
        }
        for (int i = 0; i + 1 < val.length; ++i) {
            if (val[i] * val[i + 1] < 0) {
                double left = derivZeroes.get(i);
                double right = derivZeroes.get(i + 1);
                int j;
                for (j = 0; j < 200; ++j) {
                    double middle = (left + right) / 2;
                    double v = eval(koef, middle);
                    if (v == 0) {
                        res.add(middle);
                        break;
                    }
                    if (v * val[i] < 0)
                        right = middle;
                    else
                        left = middle;
                }
                if (j == 200) {
                    res.add((left + right) / 2);
                }
            }
        }
        Collections.sort(res);
        return res;
    }

    public static void main(String[] args) {
        new Coffin().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
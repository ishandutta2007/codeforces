import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int x = in.nextInt();
        boolean[] less = new boolean[n];
        for (int i = 0; i < n; i++) {
            less[i] = in.nextInt() < x;
        }
        int first = -1;
        for (int i = 0; i < n; i++) {
            if (less[i]) {
                first = i;
                break;
            }
        }
        List<Integer> lengths = new ArrayList<>();
        if (first == -1) {
            lengths.add(n);
        } else {
            lengths.add(first + 1);
            for (int i = first; i < n; ) {
                int j = i + 1;
                while (j != n && !less[j]) {
                    j++;
                }
                lengths.add(j - i);
                i = j;
            }
        }
        long ans0 = 0;
        if (lengths.size() == 1) {
            ans0 = n * 1L * (n + 1) / 2;
        } else {
            for (int l : lengths) {
                l--;
                ans0 += l * 1L * (l + 1) / 2;
            }
        }
        out.print(ans0);
        long[] xx = new long[lengths.size()];
        long[] yy = new long[lengths.size()];
        for (int i = 0; i < xx.length; i++) {
            xx[i] = lengths.get(i);
            yy[i] = lengths.get(lengths.size() - i - 1);
        }
        long[] mult = mulFast(xx, yy);
        for (int i = 0; i < n; i++) {
            int pos = lengths.size() - 2 - i;
            long res = pos < 0 ? 0 : mult[pos];
            out.print(" " + res);
        }
        out.println();
    }

    void FFT(double[] re, double[] im, boolean invert) {
        int n = re.length;
        if (im.length != n) {
            throw new AssertionError("Sizes of arrays differ");
        }
        if (Integer.bitCount(n) != 1) {
            throw new AssertionError("N is not power of 2");
        }
        int shift = 32 - Integer.numberOfTrailingZeros(n);
        for (int i = 1; i < n; i++) {
            int j = Integer.reverse(i << shift);
            if (i < j) {
                double temp = re[i];
                re[i] = re[j];
                re[j] = temp;
                temp = im[i];
                im[i] = im[j];
                im[j] = temp;
            }
        }
        for (int len = 2; len <= n; len *= 2) {
            int half = len / 2;
            double alpha = 2 * Math.PI / len;
            double cosAlpha = Math.cos(alpha);
            double sinAlpha = (invert ? -1 : 1) * Math.sin(alpha);
            for (int start = 0; start < n; start += len) {
                double curRe = 1;
                double curIm = 0;
                for (int j = 0; j < half; j++) {
                    double uRe = re[start + j];
                    double uIm = im[start + j];
                    double vRe = re[start + j + half] * curRe
                            - im[start + j + half] * curIm;
                    double vIm = re[start + j + half] * curIm
                            + im[start + j + half] * curRe;
                    re[start + j] = uRe + vRe;
                    im[start + j] = uIm + vIm;
                    re[start + j + half] = uRe - vRe;
                    im[start + j + half] = uIm - vIm;
                    double newRe = curRe * cosAlpha - curIm * sinAlpha;
                    curIm = curRe * sinAlpha + curIm * cosAlpha;
                    curRe = newRe;
                }
            }
        }
        if (invert) {
            for (int i = 0; i < n; i++) {
                re[i] /= n;
                im[i] /= n;
            }
        }
    }

    long[] mul(long[] a, long[] b) {
        int len = Math.max(a.length, b.length) * 2;
        int mLen = 1;
        while (mLen < len)
            mLen *= 2;
        double[] r1 = new double[mLen];
        double[] i1 = new double[mLen];
        for (int i = 0; i < a.length; i++)
            r1[i] = a[i];
        double[] r2 = new double[mLen];
        double[] i2 = new double[mLen];
        for (int i = 0; i < b.length; i++)
            r2[i] = b[i];
        FFT(r1, i1, false);
        FFT(r2, i2, false);
        double[] rNew = new double[mLen];
        double[] iNew = new double[mLen];
        for (int i = 0; i < mLen; i++) {
            rNew[i] = r1[i] * r2[i] - i1[i] * i2[i];
            iNew[i] = r1[i] * i2[i] + r2[i] * i1[i];
        }
        FFT(rNew, iNew, true);
        long[] res = new long[mLen];
        for (int i = 0; i < mLen; i++)
            res[i] = (long) Math.round(rNew[i]);
        return res;
    }

    long[] mulFast(long[] a, long[] b) {
        int len = Math.max(a.length, b.length) * 2;
        int mLen = 1;
        while (mLen < len)
            mLen *= 2;
        double[] r1 = new double[mLen];
        double[] i1 = new double[mLen];
        for (int i = 0; i < a.length; i++) {
            r1[i] = a[i];
            i1[i] = b[i];
        }
        FFT(r1, i1, false);
        double[] rNew = new double[mLen];
        double[] iNew = new double[mLen];
        for (int i = 0; i < mLen; i++) {
            rNew[i] = r1[i] * r1[i] - i1[i] * i1[i];
            iNew[i] = r1[i] * i1[i] + r1[i] * i1[i];
        }
        FFT(rNew, iNew, true);
        long[] res = new long[mLen];
        for (int i = 0; i < mLen; i++)
            res[i] = (long) Math.round(iNew[i] / 2);
        return res;
    }

    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new A().runIO();
    }
}
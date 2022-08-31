import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class HappyTransformation implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        String number = nextToken();
        char[] digits = number.toCharArray();
        int pos = 0;
        while (k > 0) {
            --k;
            while (pos + 1 < digits.length && (digits[pos] != '4' || digits[pos + 1] != '7'))
                ++pos;
            if (pos + 1 >= number.length()) break;
            if (pos % 2 == 0) {
                digits[pos + 1] = '4';
                if (pos + 2 < digits.length && digits[pos + 2] == '7') {
                    if (k % 2 != 0)
                        digits[pos + 1] = '7';
                    break;
                }
            } else {
                digits[pos] = '7';
                if (pos > 0) --pos;
            }
        }
        System.out.println(new String(digits));
    }

    public static void main(String[] args) {
        new HappyTransformation().run();
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
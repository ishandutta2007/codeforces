import com.sun.imageio.plugins.common.BitFile;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;


/**
 * Created with IntelliJ IDEA.
 * User: Pavel Kunyavskiy
 * Date: 12/06/13
 * Time: 17:03
 */
public class Main {

    long cnk(int n,int k){
        long ans = 1;
        for (int i = n-k+1; i <= n; i++)
            ans *= i;
        return ans;
    }

    void solve() throws IOException {
        String s = in.readLine();
        int n = s.length();
        BigInteger ans = BigInteger.ONE;
        for (int i = 0; i < n; i++)
            if (s.charAt(i) == '?') {
                if (i != 0)
                    ans = ans.multiply(BigInteger.TEN);
                else
                    ans = ans.multiply(BigInteger.valueOf(9));
            }
        boolean used[] = new boolean[10];
        for (int i = 0; i < n; i++)
            if ('A' <= s.charAt(i) && s.charAt(i) <= 'J')
                used[s.charAt(i)-'A'] = true;

        int cnt = 0;
        for (int i = 0; i < 10; i++)
            if (used[i])
                cnt++;
        //System.err.println(cnt);
        long coef = cnk(10,cnt);
        if ('A' <= s.charAt(0) && s.charAt(0) <= 'J')
             coef -= cnk(9,cnt-1);
        ans = ans.multiply(BigInteger.valueOf(coef));
        out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    BufferedReader in;
    StringTokenizer tokenizer;
    PrintWriter out;

    public void run() throws IOException {
        try {

            Reader reader = new InputStreamReader(System.in);
            Writer writer = new OutputStreamWriter(System.out);
            in = new BufferedReader(reader);
            tokenizer = null;
            out = new PrintWriter(writer);
            solve();
            out.close();
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
            tokenizer = new StringTokenizer(in.readLine());
        }
        return tokenizer.nextToken();
    }
}
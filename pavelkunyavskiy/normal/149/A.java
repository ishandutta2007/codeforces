import java.io.*;
import java.lang.*;
import java.util.*;

public class A
{


    void solve() throws IOException{
        int n = 12,k = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        Arrays.sort(a);
        int cnt = 0;
        for (int i = n-1; i >= 0; i--){
            if (k > 0){
                k -= a[i];
                cnt++;
            }
        }

        if (k > 0)
            out.println(-1);
        else
            out.println(cnt);

    }

    public static void main(String[] args) throws IOException{
        new A().run();
    }

    BufferedReader in;
    StringTokenizer tokenizer;
    PrintWriter out;

    public void run() throws IOException
    {
        try {                               
            boolean oj = System.getProperty("ONLINE_JUDGE") != null;
            Reader reader = oj ? new InputStreamReader(System.in) : new FileReader("input.txt");
            Writer writer = oj ? new OutputStreamWriter(System.out) : new FileWriter("output.txt");
            in = new BufferedReader(reader);
            tokenizer = null;
            out = new PrintWriter(writer);
            solve();
            in.close();
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
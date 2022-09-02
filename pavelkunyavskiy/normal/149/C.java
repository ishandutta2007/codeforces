import java.io.*;
import java.lang.*;
import java.util.*;

public class C
{


    void solve() throws IOException{
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt()*200000+i+1;

        Arrays.sort(a);
        int[] b = new int[n/2+n%2];
        int[] c = new int[n/2];

        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                b[i/2] = a[i] % 200000;
            else
                c[i/2] = a[i] % 200000;

        out.println(n/2+n%2);
        for (int i = 0; i < n/2+n%2; i++)
            out.print(b[i]+" ");
        out.println();
        out.println(n/2);
        for (int i = 0; i < n/2; i++)
            out.print(c[i]+" ");
        out.println();
    }

    public static void main(String[] args) throws IOException{
        new C().run();
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
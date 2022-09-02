
import java.io.*;
import java.lang.*;
import java.util.*;

public class Main
{

    void solve() throws IOException{
        int n=nextInt(),m=nextInt();

        if (n == 0 && m != 0){
            out.println("Impossible\n");
            return;
        }

        if (n == 0){
            out.println(0+" "+0);
            return ;
        }

        out.println(Math.max(n,m)+" "+(n+Math.max(0,m-1)));

    }

    public static void main(String[] args) throws IOException{
        new Main().run();
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
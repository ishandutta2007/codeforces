import java.io.*;
import java.lang.*;
import java.util.*;

public class Main
{

    void solve() throws IOException{
        int x1= nextInt(),y1 = nextInt(), r1 = nextInt();
        int x2 = nextInt(), y2 = nextInt(),r2 = nextInt();

        int d = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

        if (d > (r1+r2)*(r1+r2))
            out.println((-r1-r2+Math.sqrt(d))/2);
        else if (d < (r1-r2)*(r1-r2))
            out.println((Math.abs(r1-r2) - Math.sqrt(d))/2.0);
        else
            out.println(0);
        return;
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
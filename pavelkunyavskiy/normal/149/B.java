import java.io.*;
import java.lang.*;
import java.util.*;

public class B
{


    int calc(String _s,int a){
        char[] s = _s.toCharArray();
        if (a < 10){
            for (int i = 0; i < _s.length(); i++)
                 if ('0'<= s[i]  && s[i] <= '9'){
                   if (s[i] - '0' >= a)
                     return -1;
                 }
                 else
                   return -1;

        }
        else {
            for (int i = 0; i < _s.length(); i++)
                 if ('0'<= s[i]  && s[i] <= '9')
                    continue;
                 else if (s[i] - 'A' >= a-10)
                     return -1;
        }

        int x = 0;
        for (int i = 0; i < _s.length(); i++)
            if ('0'<= s[i]  && s[i] <= '9')
                x = x * a + s[i] - '0';
            else
                x = x * a + s[i] - 'A'+10;
        return x;
    }

    void solve() throws IOException{
        String[] a = nextToken().split(":");

        ArrayList<Integer> b = new ArrayList<Integer>();

        for (int i = 2; i < 100; i++){
            int h = calc(a[0],i);
            int m = calc(a[1],i);
            if (0 <= h && h <= 23 && 0 <= m && m < 60)
                b.add(i);            
        }

        if (b.size() >= 60){
            out.println("-1");
            return;
        }
        if (b.size() == 0){
            out.println("0");
            return;
        }

        for (Integer x: b){
            out.print(x+" ");
        }
        out.println();
    }

    public static void main(String[] args) throws IOException{
        new B().run();
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
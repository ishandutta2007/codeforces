import java.io.*;
import java.lang.*;
import java.util.*;

public class Main
{
    StringBuilder ans;

    void calc() throws IOException{
        String s = nextToken();

        if (s.equals("pair")){
            ans.append("pair<");
            calc();
            ans.append(",");
            calc();
            ans.append(">");
            return;
        }
        if (s.equals("int")){
            ans.append("int");
            return;
        }
        assert false;
    }

    void solve() throws IOException{
        nextInt();
        ans = new StringBuilder();
        try{
            calc();
        } catch (Exception e){              
            out.println("Error occurred\n");
            return;            
        }
        try{
            nextToken();
        } catch(Exception e){         
            out.println(ans.toString());        
            return;
        }                                   
        out.println("Error occurred\n");
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
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(in.readLine());       
        }
        return tokenizer.nextToken();
    }

}
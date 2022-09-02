import java.io.*;
import java.lang.*;
import java.util.*;

public class E
{
    int[] reverse(int[] a){
        for (int i = 0, j = a.length-1; i < j; i++,j--){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        } 
        return a;
    }

    String reverse(String s){
        char[] a = s.toCharArray();
        for (int i = 0, j = a.length-1; i < j; i++,j--){
            char t = a[i];
            a[i] = a[j];
            a[j] = t;
        } 
        return new String(a);
    }

    int[] pfunk(String _t,String _s){
        String s = _t + "$"+_s;
        int[] p = new int[s.length()];

        p[0] = 0;
        for (int i = 1,sz=s.length(); i < sz; i++){
            int j = p[i-1];
            while (j > 0 && s.charAt(j) != s.charAt(i))
                j = p[j-1];

            if (s.charAt(j) == s.charAt(i))
                j++;
            p[i] = j;
        }

/*        System.out.print(s+ " : ");
        for (int i : p)
            System.err.print(i+" ");
        System.err.println();*/

        int[] ret = new int[_s.length()];
        System.arraycopy(p,_t.length()+1,ret,0,_s.length());
        return ret;
    }

    int find(String t,String s){
        int n = t.length();
        if (n == 1)
            return 0;
        int m = s.length();
        int[] p = pfunk(t,s);
        int[] p2 = reverse(pfunk(reverse(t),reverse(s)));
/*        for (int i : p)
            System.err.print(i+" ");
        System.err.println();
        for (int i : p2)
            System.err.print(i+" ");
        System.err.println();*/

        for (int i = 1; i < m; i++)
            p[i] = Math.max(p[i],p[i-1]);

        for (int i = m-2; i >= 0; i--)
            p2[i] = Math.max(p2[i],p2[i+1]);

        for (int i = 0; i+1 < m; i++)
            if (p[i] + p2[i+1] >= n)
                return 1;
        return 0;
    }

    void solve() throws IOException{
        String s = nextToken();
        int ans = 0;
        int n = nextInt();
        for (int i = 0; i < n; i++){
            String t = nextToken();
            ans += find(t,s);
        }            
        out.println(ans);
        return;
    }

    public static void main(String[] args) throws IOException{
        new E().run();
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
import java.io.*;
import java.lang.*;
import java.util.*;

public class D
{
    long dp[][][][];
    int oth[];
    long MOD = 1000000007;

    long calc(int l,int r,int c1,int c2){
        if (l == r+1){
            if (c1 == c2 && c1 != 0)
                return 0;
            return 1;
        }
        if (dp[l][r][c1][c2] != -1)
            return dp[l][r][c1][c2];
        long ans = 0;
        ans = (calc(l+1,oth[l]-1,0,1)*calc(oth[l]+1,r,1,c2))%MOD;
        ans = (ans + calc(l+1,oth[l]-1,0,2)*calc(oth[l]+1,r,2,c2))%MOD;
        if (c1 != 1)
            ans = (ans + calc(l+1,oth[l]-1,1,0)*calc(oth[l]+1,r,0,c2))%MOD;            
        if (c1 != 2)
            ans = (ans + calc(l+1,oth[l]-1,2,0)*calc(oth[l]+1,r,0,c2))%MOD;            
        dp[l][r][c1][c2] = ans;
//        System.err.println(l+" "+r+" "+c1+" "+c2+" "+ans);
        return ans;
    }

    void solve() throws IOException{
        String _s = nextToken();
        int n = _s.length();
        char[] s = _s.toCharArray();
        dp = new long[n][n][3][3];
        int temp[] = new int[n];
        int ptr = 0;
        oth = new int[n];
        for (int i = 0; i < n; i++){
            if (s[i] == '(')
                temp[ptr++] = i;
            else{
                --ptr;
                oth[temp[ptr]] = i;
                oth[i] = temp[ptr];
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0;j  < n; j++)
                for (int k = 0; k < 3; k++)
                    for (int l = 0; l < 3; l++)
                        dp[i][j][k][l] = -1;

        out.println(calc(0,n-1,0,0));
    }

    public static void main(String[] args) throws IOException{
        new D().run();
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
import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws Exception {
        MScanner sc=new MScanner(System.in);
        //MScanner sc=new MScanner("portals.in");
        PrintWriter pw=new PrintWriter(System.out);
        int n=sc.nextInt();
        int m=sc.nextInt();
        boolean[][]canreach=new boolean[n+1][m+1];
        boolean[][]canbereached=new boolean[n][m];
        for(int i=0;i<n;i++) {
            char[]in=sc.nextLine().toCharArray();
            for(int j=0;j<m;j++) {
                if(in[j]=='.') {
                    canreach[i][j]=true;
                    canbereached[i][j]=true;
                }
            }
        }

        for(int i=1;i<n;i++) {
            canbereached[i][0]&=canbereached[i-1][0];
        }
        for(int i=1;i<m;i++) {
            canbereached[0][i]&=canbereached[0][i-1];
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                canbereached[i][j]&=(canbereached[i][j-1]|canbereached[i-1][j]);
            }
        }
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(i==n-1 && j==m-1) {continue;}
                canreach[i][j]&=(canreach[i][j+1]|canreach[i+1][j]);

            }
        }
        if((m-2>=0 && !canbereached[n-1][m-2]) && (n-2>=0 && !canbereached[n-2][m-1])) {
            pw.println(0);pw.flush();return;
        }
        if(!canreach[0][0]) {
            pw.println(0);
        }
        else {
            int[]dist=new int[n+m+7];
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(!(i==0 && j==0) && !(i==n-1 && j==m-1)) {
                        if(canreach[i][j] && canbereached[i][j]) {
                            dist[i+j]++;
                        }
                    }
                }
            }
            for(int i:dist) {
                if(i==1) {
                    pw.println(1);pw.flush();return;
                }
            }
            pw.println(2);
        }
        pw.flush();
    }
    static class MScanner {
        StringTokenizer st;
        BufferedReader br;

        public MScanner(InputStream system) {
            br = new BufferedReader(new InputStreamReader(system));
        }

        public MScanner(String file) throws Exception {
            br = new BufferedReader(new FileReader(file));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public char nextChar() throws IOException {
            return next().charAt(0);
        }

        public Long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }

        public void waitForInput() throws InterruptedException {
            Thread.sleep(3000);
        }
    }
}
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
		Scanner in;
		PrintWriter pw;
		
		int n;
		int res[][];
		boolean u[][];
		
		public int solve(int a,int b){
			if(u[a][b]) return res[a][b];
			u[a][b] = true;
			
			long val = 1;
			for(int i=0;i<b;i++) val*=a;
			if(val>=n) return res[a][b]=1;
			
			if(a==1 && b==30){
				return res[a][b]=0;
			}
			if(b==1 && a==35000){
				return res[a][b]=((n-a)%2==1?-1:1);
			}
			int v1 = solve(a,b+1);
			int v2 = solve(a+1,b);
			
			if(v1==-1 || v2==-1) return res[a][b]=1;
			if(v1==0 || v2==0) return res[a][b]=0;
			return res[a][b] = -1;
		}
			
		public void run () throws Exception {
            in = new Scanner(System.in);
            pw = new PrintWriter(System.out);
            

        	int a = in.nextInt();
        	int b = in.nextInt();
        	n = in.nextInt();
            
        	res = new int[35001][31];
        	u = new boolean[35001][31];
        	
        	int res = solve(a,b);
        	if(res==1) pw.println("Masha");
        	else if(res==-1) pw.println("Stas");
        	else pw.println("Missing");
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}
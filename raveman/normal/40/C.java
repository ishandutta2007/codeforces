import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
		Scanner in;
		PrintWriter pw;
		
		public void run () throws Exception {
            in = new Scanner(System.in);
            pw = new PrintWriter(System.out);

            int n = in.nextInt();
            int x = in.nextInt();
            int m = in.nextInt();
            int y = in.nextInt();
            
            int r = Math.abs(x-y);
            if(n<m){
            	int t = n;
            	n = m;
            	m = t; 
            }
            long res = 1 + n;
            
            if(r<=m) res++;
            
            for(int i=1;i<=m;i++) if(r+i>n) res++;
            for(int i=2;i<=n;i++){
            	int num = 1;
            	
            	int from = 1;
            	int to = m;
            	
            	from = Math.max(from, r-i+1);
            	from = Math.max(from, i-r);
            	
            	to = Math.min(to, r+i-1);
            	
            	if(from==to) num = 2;
            	else if(from<=to){
            		num=2;
            		num+=2*(to-from);
            	}
            	
            	res += (num - 1);
            }

            

            pw.println(res);
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}
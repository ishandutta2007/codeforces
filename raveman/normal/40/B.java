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
            int m = in.nextInt();
            int x = in.nextInt();
            
            while(x>1){
            	n-=2;
            	m-=2;
            	x--;
            	if(n<1 || m<1) break;
            }
            if(n>0 && m>0){
            	if(m==1) pw.print((n+1)/2);
            	else if(n==1) pw.print((m+1)/2);
            	else pw.print((n+n+m+m-3)/2);
            }
            else pw.println(0);
            
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}
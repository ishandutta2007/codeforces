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
            
            String s1 = in.next();
            String s2 = in.next();
            
            int n = s2.length();
            int p1 = 0;
            int p2 = 0;
            while(p1<n && s1.charAt(p1)==s2.charAt(p1)) p1++;
            while(p2<n && s1.charAt(n-p2)==s2.charAt(n-1-p2)) p2++;
            
            if(p1+p2>=n){
            	pw.println(p1+p2-n+1);
            	for(int i=0;i<p1+p2-n+1;i++){
            		if(i>0) pw.print(" ");
            		pw.print(n-p2+i+1);	
            	}
            	pw.println();
            }else{
            	pw.println("0");
            }

            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}
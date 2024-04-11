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
            
            int x = in.nextInt();
            int y = in.nextInt();
            
            
            int t = x*x + y*y;
            int v = (int)(0.1 + Math.sqrt((double)t));
            if(v*v>t) v--;
            if(v*v==t) pw.println("black");
            else{
            	x*=y;
            	boolean bl = true;
            	if(v%2==1)  bl = false;
            	if(x<0) bl=!bl;
            	pw.println(bl?"black":"white");
            }

            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}
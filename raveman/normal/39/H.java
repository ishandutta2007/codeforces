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
            for(int i=1;i<n;i++){
            	for(int j=1;j<n;j++){
            		if(j>1) pw.print(" ");
            		int val = i * j;
            		if(val>=n) pw.print(val/n);
            		pw.print(val%n);
            	}
            	pw.println();
            }

            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}
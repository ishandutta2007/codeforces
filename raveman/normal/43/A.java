import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
		Scanner in;
		PrintWriter pw;
		
		public void run () throws Exception {
            in = new Scanner(System.in);
            pw = new PrintWriter(System.out);

            int n = in.nextInt();
            String s1="",s2="",s;
            int c1=0,c2=0;
            for(int i=0;i<n;i++){
            	s = in.next();
            	if(s1=="" || s1.equals(s)){
            		s1 = s;
            		c1++;
            	}else{
            		s2=s;
            		c2++;
            	}
            }
            pw.println(c1>c2?s1:s2);
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main().run();
        }
}
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

            String s1 = in.nextLine();
            String s2 = in.nextLine();
            
            boolean good = true;
            for(int i=0;i<s2.length();i++)if(s2.charAt(i)!=' '){
            	char c = s2.charAt(i);
            	good = false;
            	for(int j=0;j<s1.length();j++)
            		if(s1.charAt(j)==c){
            			s1= s1.substring(0,j)+s1.substring(j+1);
            			good = true;
            			break;
            		}
            	if(!good) break;
            }
            pw.println(good?"YES":"NO");
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main().run();
        }
}
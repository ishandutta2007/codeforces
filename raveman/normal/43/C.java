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
            int a[] = new int[3];
            a[0]=a[1]=a[2]=0;
            for(int i=0;i<n;i++)
            	a[in.nextInt()%3]++;
            
            int res = a[0] / 2 + Math.min(a[1],a[2]);
            
            pw.println(res);
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main().run();
        }
}
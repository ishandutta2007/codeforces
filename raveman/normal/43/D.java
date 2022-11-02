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
            int m = in.nextInt();
            if(n==1){
            	if(m==2){
            		pw.println("0\n1 1\n1 2\n1 1");
            	}else{
            		pw.println("1");
            		pw.println(n+" "+m+" "+"1 1");
            		
            		for(int i=1;i<=m;i++)
            			pw.println(n+" "+i);
            		pw.println("1 1");
            	}
            }else if(m==1){
            	if(n==2){
            		pw.println("0\n1 1\n2 1\n1 1");
            	}else{
            		pw.println("1");
            		pw.println(n+" "+m+" "+"1 1");
            		
            		for(int i=1;i<=n;i++)
            			pw.println(i+" "+m);
            		pw.println("1 1");
            	}
            }
            else if(n%2==0){
            	pw.println(0);
            	int x = 1;
            	int y = 1;
            	int dx=1;
            	while(true)
            	{
            		pw.println(x+" "+y);
            		if(x==n && y==1) break;
            		y+=dx;
            		if(y>m){
            			x++;
            			y=m;
            			dx=-1;            			
            		}else if(y<2 && x<n){
            			x++;
            			y=2;
            			dx=1;
            		}
            	}
            	for(int i=n-1;i>=1;i--)
            		pw.println(i+" 1");
            }else if(m%2==0){
            	pw.println(0);
            	int x = 1;
            	int y = 1;
            	int dx=1;
            	while(true)
            	{
            		pw.println(x+" "+y);
            		if(y==m && x==1) break;
            		x+=dx;
            		if(x>n){
            			y++;
            			x=n;
            			dx=-1;            			
            		}else if(x<2 && y<m){
            			y++;
            			x=2;
            			dx=1;
            		}
            	}
            	for(int i=m-1;i>=1;i--)
            		pw.println("1 "+i);
            }else{
            	pw.println(1);
            	pw.println(n+" "+m+" 1 1");
            	int x = 1;
            	int y = 1;
            	int dx=1;
            	while(true)
            	{
            		pw.println(x+" "+y);
            		if(y==m && x==n) break;
            		y+=dx;
            		if(y>m){
            			x++;
            			y=m;
            			dx=-1;            			
            		}else if(y<1){
            			x++;
            			y=1;
            			dx=1;
            		}
            	}
            	pw.println("1 1");
            }
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main().run();
        }
}
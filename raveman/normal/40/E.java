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
            int k = in.nextInt();
            
            boolean swap = false;
            if(n>m){
            	int t =n;
            	n =m;
            	m=t;
            	swap = true;
            }
            
            int[][] a = new int[n][m];
            for(int i=0;i<k;i++){
            	int x = in.nextInt();
            	int y = in.nextInt();
            	int c = in.nextInt();
            	
            	if(swap){
            		int t = x;
            		x = y;
            		y = t;
            	}
            	a[x-1][y-1]=c;
            }
            int p = in.nextInt();
            
            int res=0;
            
            int pow = 0;
            
            boolean shit = false;
            for(int j=0;j<m;j++){
            	int d = 1;
            	int num =0;
            	for(int i=0;i<n;i++){
            		if(a[i][j]==0) num++;
            		else d*=a[i][j];
            	}
            	if(num==0 && d==1) shit=true;
            	if(num!=0){
            		pow += num-1;
            	}
            }

            if(n%2 != m%2) shit = true;
            if(!shit){
            	pow -= (n-1);
        		res = 1;
        		while(pow>0){
        			pow--;
        			res+=res;
        			if(res>=p) res-=p;
        		}
            }
            pw.println(res);
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}
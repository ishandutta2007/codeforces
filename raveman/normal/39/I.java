import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Main {
		Scanner in;
		PrintWriter pw;
		
		int n,m,g=-1;
		List<List<Integer>> v = new ArrayList<List<Integer>>();
		int[] c;
		
		int gcd(int a,int b){
			while(a>0 && b>0)
				if(a>b) a%=b;
				else b%=a;
			return a+b;
		}
		void dfs(int ver,int pos){
			if(c[ver]!=-1){
				int diff = Math.abs(c[ver]-pos);
				if(g==-1) g = diff;
				g = gcd(g, diff);
				return;
			}
			c[ver] = pos;
			for(int i=0;i<v.get(ver).size();i++)
				dfs(v.get(ver).get(i), pos+1);
		}
        
		public void run () throws Exception {
            in = new Scanner(System.in);//new File("input.txt"));
            pw = new PrintWriter(System.out);//;//new  File("output.txt"));
       
            n = in.nextInt();
            m = in.nextInt();
            
            c = new int[n];
            
            for(int i=0;i<n;i++){
            	c[i]=-1;
            	v.add(new ArrayList<Integer>());
            }
            	
            
            for(int i=0;i<m;i++){
            	int x = in.nextInt();
            	int y = in.nextInt();
            	x--;y--;
            	v.get(x).add(y);
            }
            
            dfs(0,0);
            
            List<Integer> res = new ArrayList<Integer>();
            for(int i=0;i<n;i++) if(c[i]!=-1 && c[i]%g==0)
            	res.add(i+1);
            pw.println(g);
            pw.println(res.size());
            for(int i=0;i<res.size();i++){
            	if(i>0)pw.print(" ");
            	pw.print(res.get(i));
            }
            pw.println();
                       
       
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }

}
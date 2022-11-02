import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;


public class Main {
		public Scanner in;
		public PrintWriter pw;
		
		public int[] c;
		public int[] r;
		public int[] a;
		public int[] b;
		public int n;
		public ArrayList<Integer> x;
		public ArrayList<Integer>[] start;
		public int[][] res;
		
		public int solve(int par,int from){
			if(from >= x.size() || par!=n && b[par]<=from) return 0;
			if(res[par][from]!=-1) return res[par][from];
			int val = solve(par, from+1);
			for(int i=0;i<start[from].size();i++){
				int ver = start[from].get(i);
				if(ver == par) continue;
				if(par!=n && b[ver] > b[par]) break;
				
				int t1 = solve(ver, from);
				t1 ++;
				t1 += solve(par, b[ver]);
				
				if(t1>val) val = t1;
			}
			return res[par][from]=val;
		}
		
		public void print(int par,int from){
			if(from >= x.size() || par!=n && b[par]<=from) return;
			if(solve(par,from) == solve(par, from+1)){
				print(par,from+1);
				return;
			}
			for(int i=0;i<start[from].size();i++){
				int ver = start[from].get(i);
				if(ver == par) continue;
				if(par!=n && b[ver] > b[par]) break;
				
				int t1 = solve(ver, from);
				t1 ++;
				t1 += solve(par, b[ver]);
				
				if(t1 == solve(par,from)){
					print(ver,from);
					print(par,b[ver]);
					pw.print((ver+1)+" ");
					break;
				}
			}
		}
		
        public void run () throws Exception {
            in = new Scanner(System.in);//new File("input.txt"));
            pw = new PrintWriter(System.out);//;//new  File("output.txt"));
            
            n = in.nextInt();
            c = new int[n];
            r = new int[n];
            a = new int[n];
            b = new int[n];
            
            x = new ArrayList<Integer>();
            for(int i=0;i<n;i++){
            	c[i] = in.nextInt();
            	r[i] = in.nextInt();
            	
            	x.add(c[i]-r[i]);
            	x.add(c[i]+r[i]);
            }
            
            Collections.sort(x);
            for(int i=x.size()-2;i>=0;i--)
            	if(x.get(i)==x.get(i+1))
            		x.remove(i+1);
            res = new int[n+1][];
            for(int i=0;i<=n;i++){
            	res[i] = new int[x.size()+1];
            	for(int j=0;j<=x.size();j++)
            		res[i][j]=-1;
            }
            
            start = new ArrayList[x.size()+1];
            for(int i=0;i<=x.size();i++)
            	start[i] = new ArrayList<Integer>();
            for(int i=0;i<n;i++){
            	a[i] = Collections.binarySearch(x, c[i]-r[i]);
            	b[i] = Collections.binarySearch(x, c[i]+r[i]);
            	start[a[i]].add(i);
            }
            for(int i=0;i<=x.size();i++)
            	for(int i1=0;i1<start[i].size();i1++)
            		for(int i2=0;i2<i1;i2++)
            			if(r[start[i].get(i2)] > r[start[i].get(i1)]){
            				int t = start[i].get(i1);
            				start[i].set(i1, start[i].get(i2));
            				start[i].set(i2, t);
            			}
            
            int res = solve(n, 0);
            pw.println(res);
            print(n,0);
      
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }

}
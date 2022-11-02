import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
		Scanner in;
		PrintWriter pw;
		
		int n,m,k;
		boolean u[][];

		int b[],e[],lx[],ly[];
		
		public class Segm{
			int x;
			int y;
			int sum;
			Segm(int a,int b,int type){
				x=a;
				y=b;
				sum = type;				
			}
		}
		
		public void run () throws Exception {
            in = new Scanner(System.in);
            pw = new PrintWriter(System.out);
       
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            
            b = new int[k];
            e = new int[k];
            lx = new int[k];
            ly = new int[k];
            k=0;
            
            u = new boolean[n][m];
            
            for(int i=0;i<n;i++){
            	String s = in.next();
            	for(int j=0;j<m;j++)
            		u[i][j] = (s.charAt(j) == '*');
            }
            
            boolean v[] = new boolean[n+1];
            
            for(int j=0;j<m;j++)
            	for(int i=0;i<n;i++) if(u[i][j]){
            		int x = i;
            		int y = j;
            		while(y+1<m && u[i][y+1]) y++;
            		while(x+1<n && u[x+1][j]) x++;
            		
            		b[k] = i;
            		e[k] = j;
            		lx[k] = x-i+1;
            		ly[k] = y-j+1;
            		
            		v[i] = true;
            		v[i+1] = true;
            		v[x+1] = true;
            		if(x+2<=n) v[x+2] = true;
            		
            		k++;
            		
            		for(int dx=i;dx<=x;dx++)
        				for(int dy=j;dy<=y;dy++)
            				u[dx][dy] = false;
            	}
            long res = 0;
            
            
            v[0]=true;
            for(int i=0;i<n;i++)if(v[i]){
            	for(int j=i+1;j<=n;j++)if(v[j]){
            		int num = 1;
            		int i1 = i+1;
            		while(i1<n && !v[i1]) i1++;
            		num *= (i1-i);
            		
            		int j1 = j+1;
            		while(j1<=n && !v[j1]) j1++;
            		num *= (j1-j);
            		
            		//pw.println(i+" "+j+" "+num);
            		
            		ArrayList<Segm> s = new ArrayList<Segm>();
            		for(int w=0;w<k;w++){
            			if(b[w]>=j || b[w]+lx[w]<=i) continue;
            			Segm temp = new Segm(e[w], e[w]+ly[w], 1);
            			if(b[w]<i || b[w]+lx[w]>j) temp.sum = -1;
            			
            			if(s.size()==0 || s.get(s.size()-1).y <= temp.x){
            				s.add(new Segm(s.size()==0 ? 0 : s.get(s.size()-1).y, temp.x, 0));
            			}
            			if(s.size() > 0 && s.get(s.size()-1).y > temp.x){
            				s.get(s.size()-1).y = Math.max(s.get(s.size()-1).y, temp.y);
            				if(s.get(s.size()-1).sum == -1 || temp.sum == -1)
            					s.get(s.size()-1).sum = -1;
            				else s.get(s.size()-1).sum ++;
            			}else s.add(temp);
            		}
            		if(s.size() == 0) continue;
            		s.add(new Segm(s.get(s.size()-1).y,m,0));
            		
            		for(int w=0;w<s.size();w++)if(s.get(w).sum==0){
            			int t = 0;
            			for(int e=w+1;e<s.size();e++){
            				if(s.get(e).sum==-1) break;
            				t += s.get(e).sum;
            				if(t>3) break;
            				if(t>0 && s.get(e).sum==0){
            					res += ((long)num) * (s.get(w).y - s.get(w).x + 1) * (s.get(e).y - s.get(e).x + 1);
            				}
            			}
            		}
            		
            	}
            }
            
            pw.println(res);       
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }

}
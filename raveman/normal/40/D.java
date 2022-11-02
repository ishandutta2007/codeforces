import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
		Scanner in;
		PrintWriter pw;
		
		BigInteger a,b12,b13,b47;
		boolean u[];
		List<BigInteger> r;
		Set<BigInteger> s[];
		void go(BigInteger f1, BigInteger f2, int pos){
			if(s[pos].contains(f1.add(f2.multiply(b47)))) return;
			s[pos].add(f1.add(f2));
			//pw.println(f1+" "+f2+" "+pos);
			if(f2.compareTo(a) >= 0){
				if(f2.equals(a))
					u[pos] = true;
				return;
			}
			if(pos==0){
				go(f2, new BigInteger("2"), 1);
			}else if(pos==1){
				go(f2, new BigInteger("13"), 2);
			}else{
				go(f2, f1.multiply(b12), pos+1);
				go(f2, f2.multiply(b13).subtract(f1.multiply(b12)), pos+1);
			}
		}
		void solve(BigInteger f1, BigInteger f2, int pos){
			if(s[pos].contains(f1.add(f2.multiply(b47)))) return;
			s[pos].add(f1.add(f2));
			if(u[pos] && !f2.equals(a)){
				boolean contains = false;
				for(int i=0;i<r.size();i++)
					if(r.get(i).equals(f2)){
						contains = true;
						break;
					}
				if(!contains)
					r.add(f2);
				return;
			}
			if(u[pos]) return;
			if(pos==0){
				solve(f2, new BigInteger("2"), 1);
			}else if(pos==1){
				solve(f2, new BigInteger("13"), 2);
			}else{
				solve(f2, f1.multiply(b12), pos+1);
				solve(f2, f2.multiply(b13).subtract(f1.multiply(b12)), pos+1);
			}
		}
		public void run () throws Exception {
            in = new Scanner(System.in);
            pw = new PrintWriter(System.out);
            
            a = in.nextBigInteger();
            b12 = new BigInteger("12");
            b13 = new BigInteger("13");
            b47 = new BigInteger("1");
            u = new boolean[1000];
            r = new ArrayList<BigInteger>();
            s = new HashSet[1000];
            for(int i=0;i<1000;i++)
            	s[i] = new HashSet<BigInteger>();
            go(BigInteger.ZERO, BigInteger.ZERO, 0);
            
            int num = 0;
            for(int i=0;i<1000;i++)if(u[i]) num++;
            if(num==0){
            	pw.println("NO");
            }else{
            	for(int i=0;i<1000;i++)
                	s[i].clear();
                solve(BigInteger.ZERO, BigInteger.ZERO, 0);
                
                pw.println("YES");
            	pw.println(num);
            	for(int i=0;i<1000;i++)if(u[i]){
            		pw.print(i+" ");
            	}
            	pw.println();
            	Collections.sort(r);
            	int w = Math.min(1000, r.size());
            	pw.println(w);
            	for(int i=0;i<w;i++){
            		if(i>0) pw.print(" ");
            		pw.print(r.get(i));
            	}
            	pw.println();
            }
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}
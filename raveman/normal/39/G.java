import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
		Scanner in;
		PrintWriter pw;

		String s;
		int pos;
		int n;
		
		int numb(){
			if(s.charAt(pos)=='f'){
				pos+=2;
				int t = expr();
				pos++;
				return res[t];
			}
			if(s.charAt(pos)=='n'){
				pos++;
				return n;
			}
			int r = 0;
			while(Character.isDigit(s.charAt(pos))){
				r = 10 * r+ s.charAt(pos)-'0';
				pos++;
			}
			return r;
		}
		
		int term(){
			int res = numb();
			while(s.charAt(pos)=='*' || s.charAt(pos)=='/'){
				char c = s.charAt(pos);
				pos++;
				int t = numb();
				if(c=='*') res *= t;
				else res /= t;
				res%=32768;
				if(res<0) res += 32768;
			}
			return res;
		}
		
		int expr(){
			int res = term();
			while(s.charAt(pos)=='+' || s.charAt(pos)=='-'){
				char c = s.charAt(pos);
				pos++;
				int t = term();
				if(c=='+') res += t;
				else res -= t;
				res%=32768;
				if(res<0) res += 32768;
			}
			return res;
		}
		
		boolean logic_expr(){
			int v1 = expr();
			char c = s.charAt(pos);
			if(c=='<'){
				pos++;
				return v1 < expr();
			}
			if(c=='>'){
				pos++;
				return v1 > expr();
			}
			pos++;pos++;
			return v1 == expr();
		}
		
		int calc(){
			while(s.charAt(pos)!='}'){
				if(s.charAt(pos)=='r'){
					pos += 6;
					return expr();
				}else{
					pos += 3;
					boolean e = logic_expr();
					pos ++;
					if(e){
						pos += 6;
						return expr();
					}else{
						while(s.charAt(pos)!=';') pos++;
						pos++;
					}
				}
			}
			return 0;
		}
		
		int res[];
		boolean u[];
		int getRes(int _n){
			if(u[_n]) return res[_n];
			n=_n;
			u[n]=true;
			pos = 11;
			return res[n]=calc();
		}
		public void run () throws Exception {
            in = new Scanner(System.in);
            pw = new PrintWriter(System.out);
            
            int n = in.nextInt();
            
            s="";
            while(in.hasNext())
            	s+=in.next();
            boolean found = false;
            res = new int[32768];
            u = new boolean[32768];
            for(int i=0;i<=32767;i++){
            	getRes(i);
            }
            for(int i=32767;i>=0;i--){
        	   if(res[i] == n){
        		   pw.println(i);
        		   found = true;
        		   break;
        	   }
            }
            if(!found) pw.println("-1");
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public int[] mx;
	public int n;
	
	public void add(int pos,int val){
		pos += n;
		while(pos>0){
			mx[pos] = Math.max(mx[pos], val);
			pos >>=1;
		}
	}
	public int[] p;
	public void setVal(int pos,int val){
		p[pos] = val;
		pos+=n;
		mx[pos] = val;
		pos >>= 1;
		while(pos>0){
			mx[pos] = 0;
			if(2*pos < 2*n) mx[pos] = Math.max(mx[pos], mx[2*pos]);
			if(2*pos+1<2*n) mx[pos] = Math.max(mx[pos], mx[2*pos+1]);
			pos>>=1;
		}
	}
	
	public int fnd(int pos){
		if(pos>=n) return pos - n;
		if(mx[2*pos]==mx[pos]) return fnd(2*pos);
		return fnd(2*pos+1);
	}
	
	public int getMax(int p1,int p2){
		p1+=n;
		p2+=n;
		int val = 0;
		int t1 = p1 , t2 = p2;
		while(t1<=t2){
			val = Math.max(val, mx[t1]);
			val = Math.max(val, mx[t2]);
			t1 = (t1+1)/2;
			t2 = (t2-1)/2;
		}
		t1 = p1 ; t2 = p2;
		while(t1<=t2){
			if(mx[t1] == val){
				return fnd(t1);
			}else if(mx[t2]==val){
				return fnd(t2);
			}
			t1 = (t1+1)/2;
			t2 = (t2-1)/2;
		}
		return 0;
	}

	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);
		
		String s = in.next();
		n = s.length();
		mx = new int[2*n];
		p = new int[n];
		int beg = -1, end = -1;
		
		int total = 0;
		ArrayList<Integer> res =new ArrayList<Integer>();
		ArrayList<Integer> res1 =new ArrayList<Integer>();
		
		for(int i=0;i<n;i++){
			int curr = 1;
			if(end >= i)
				curr = Math.min(end - i + 1, p[beg + end - i]);
			
			while(i+curr<n && i-curr>=0 && s.charAt(i+curr)==s.charAt(i-curr))
				curr ++;
			p[i] = curr;
			if(i+curr-1 > end){
				end = i + curr - 1;
				beg = i - curr + 1;
			}

			add(i, p[i]);
			
			if(total < p[i]*2 -1){
				total = p[i]*2 -1 ;
				res.clear();res1.clear();
				res.add(i-p[i]+2);
				res1.add(2*p[i]-1);
			}
		}
		
		
		String t = new StringBuffer(s).reverse().toString();
		
		int[] pr = new int[n];
		
		int curr = -1;
		pr[0] = curr;
		for(int i=1;i<n;i++){
			while(curr>=0 && t.charAt(curr+1) != t.charAt(i)) curr = pr[curr];
			if(t.charAt(curr+1)==t.charAt(i)) curr++;
			pr[i] = curr;
		}
		
		boolean[] u = new boolean[n];
		
		curr = -1;
		for(int i=0;i<n;i++){
			while(curr>=0 && t.charAt(curr+1)!=s.charAt(i))
				curr = pr[curr];
			if(t.charAt(curr+1) == s.charAt(i))
				curr ++;
			if(i  + curr + 2 >= n )
				break;
			if(curr>=0 && !u[curr]){
				u[curr]=true;
				
				int from = i + 1;
				int to   = n - curr -2;
				
				int pos = -1;
				while(true){
					pos = getMax(from, to);
					if(pos + p[pos] -1 <= to && pos -p[pos]+1 >= from) break;
					else setVal(pos, Math.min(pos-from+1, to-pos+1));
				}
				
				if(total < curr  * 2 + 2 + p[pos]*2 - 1){
					total = curr  * 2 + 2 + p[pos]*2 - 1;
					res.clear();res1.clear();
					
					res.add(i-curr+1);res1.add(curr+1);
					res.add(pos-p[pos]+2);res1.add(p[pos]*2-1);
					res.add(n-curr);res1.add(curr+1);
				}
			}
			
		}

		pw.println(res.size());
		for(int i=0;i<res.size();i++)
			pw.println(res.get(i) + " " + res1.get(i));
		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {

	public ArrayList<ArrayList<Integer>> s;
	public int n;
	public boolean[] u;
	public ArrayList<Integer> r;
	
	public boolean dfs(int v1,int v2){
		if(v1==v2) return true;
		if(u[v1]) return false;
		u[v1]=true;
		for(int i=0;i<s.get(v1).size();i++)
			if(dfs(s.get(v1).get(i),v2)){
				r.add(v1);
				return true;
			}
		return false;
	}
	
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		n=in.nextInt();

		s = new ArrayList<ArrayList<Integer>>();
		for(int i=0;i<n;i++)
			s.add(new ArrayList<Integer>());
		
		for(int i=1;i<n;i++){
			int x=in.nextInt();
			int y=in.nextInt();
			x--;
			y--;
			s.get(x).add(y);
			s.get(y).add(x);
		}
		
		r = new ArrayList<Integer>();
		
		ArrayList<Integer> x = new ArrayList<Integer>();
		x.add(0);
		while(in.hasNextInt()){
			x.add(in.nextInt()-1);
		}
		x.add(0);

		r.add(0);
		for(int i=x.size()-1;i>=1;i--){
			u = new boolean[n];
			dfs(x.get(i-1),x.get(i));
		}
		Collections.reverse(r);
		if(r.size()==2*n-1){
			for(int i=0;i<2*n-1;i++){
				if(i>0) pw.print(" ");
				pw.print(r.get(i)+1);
			}
			pw.println();
		}else pw.println("-1");

		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}
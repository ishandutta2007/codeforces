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

	public int n,m;
	public ArrayList<Integer> s[];
	
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		n=in.nextInt();
		m=in.nextInt();
		s = new ArrayList[n];
		for(int i=0;i<n;i++)
			s[i] = new ArrayList<Integer>();
		
		for(int i=0;i<m;i++){
			int x = in.nextInt();
			int y = in.nextInt();
			x--;y--;
			s[x].add(y);
			s[y].add(x);
		}
		boolean[][][] u = new boolean[n][n][2];
		int[][][] f = new int[n][n][2];
		int q[] = new int[n*n*2];
		int head=0,tail=1;
		q[0] = 2*n-2;
		u[0][n-1][0]=true;
		while(head < tail){
			int curr = q[head];head++;
			int a = curr/2 / n;
			int b = (curr/2) % n;
			int c = curr % 2;
			int d = (c==1 ? b : a);
			for(int i=0;i<s[d].size();i++){
				int v1 = (c==0? s[d].get(i) : a);
				int v2 = (c==1? s[d].get(i) : b);
				if((c==0 || v1!=v2) && !u[v1][v2][1-c]){
					u[v1][v2][1-c]=true;
					f[v1][v2][1-c]=curr;
					q[tail]=(v1*n+v2)*2+1-c;
					tail++;
				}
			}
			if(u[n-1][0][0]) break;
		}
		if(u[n-1][0][0]){
			ArrayList<Integer> r1 = new ArrayList<Integer>();
			ArrayList<Integer> r2 = new ArrayList<Integer>();
			
			int a = n-1;
			int b = 0;
			int c = 0;
			while(a!=0 || b!=n-1 || c!=0){
				if(c==0) r2.add(b);
				else r1.add(a);
				int t = f[a][b][c];
				a = t / 2 / n;
				b = (t/2) % n;
				c = t % 2;
			}
			r1.add(a);
			r2.add(b);
			
			Collections.reverse(r1);			
			Collections.reverse(r2);
			pw.println(r1.size()-1);
			for(int i=0;i<r1.size();i++){
				if(i>0) pw.print(" ");
				pw.print(r1.get(i)+1);
			}
			pw.println();
			for(int i=0;i<r2.size();i++){
				if(i>0) pw.print(" ");
				pw.print(r2.get(i)+1);
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
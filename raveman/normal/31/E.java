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

	public int n;
	public String s;
	public boolean[][][] u;
	public long[][][] d;
	public String[][][] r;
	public long[] st;
	
	public long go(int pos,int l1,int l2){
		if(l1>n || l2>n) return -1;
		if(pos==2*n) return 0;
		if(u[pos][l1][l2]) return d[pos][l1][l2];
		long val = -1;
		String ss="";
		
		int dd = s.charAt(pos)-'0';
		
		long v1 = go(pos+1,l1+1,l2);
		long v2 = go(pos+1,l1,l2+1);
		
		if(v1!=-1){
			long c1 = v1 + dd * st[n-1-l1];
			if(val < c1){
				ss = "H" + (r[pos+1][l1+1][l2]==null ? "" : r[pos+1][l1+1][l2]);
				val = c1;
			}
		}
		if(v2!=-1){
			long c2 = v2 + dd * st[n-1-l2];
			if(val < c2){
				ss = "M" + (r[pos+1][l1][l2+1]==null? "" : r[pos+1][l1][l2+1]);
				val = c2;
			}
		}
		
		r[pos][l1][l2]=ss;
		u[pos][l1][l2]=true;
		return d[pos][l1][l2]=val;
	}
	
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		st = new long[19];
		st[0]=1;
		for(int i=1;i<19;i++)
			st[i]= st[i-1]*10;
		
		n = in.nextInt();
		s = in.next();
	
		u = new boolean[2*n][n+1][n+1];
		d = new long[2*n][n+1][n+1];
		r= new String[2*n+1][n+1][n+1];
		go(0,0,0);
		pw.println(r[0][0][0]);
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}
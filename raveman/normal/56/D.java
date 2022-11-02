import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.text.html.MinimalHTMLWriter;


public class Main {

	public String s1,s2;
	public int[][] res;

	public int go(int n,int m){
		if(n==s1.length() && m==s2.length()) return 0;
		if(res[n][m]!=-1) return res[n][m];
		res[n][m] = 1111;
		if(n<s1.length() && m<s2.length())
			res[n][m] = Math.min(res[n][m], (s1.charAt(n)!=s2.charAt(m)?1:0)+go(n+1,m+1));
		if(m<s2.length())
			res[n][m] = Math.min(res[n][m], 1+go(n,m+1));
		if(n<s1.length())
			res[n][m] = Math.min(res[n][m], 1+go(n+1,m));
		return res[n][m];
	}
	public void find(PrintWriter pw, int n,int m,int pos){
		if(n==s1.length() && m==s2.length()) return;
		if(m<s2.length() && res[n][m] == 1 + go(n,m+1)){
			pw.println("INSERT "+pos+" "+s2.charAt(m));
			find(pw, n, m+1,pos+1);
			return;
		}
		if(n<s1.length() && res[n][m]==1+go(n+1,m)){
			pw.println("DELETE "+pos);
			find(pw, n+1,m, pos);
			return;
		}
		
		if(s1.charAt(n)!=s2.charAt(m)){
			pw.println("REPLACE "+pos+" "+s2.charAt(m));
		}
		find(pw,n+1,m+1,pos+1);
	}
	
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		s1 = in.next();
		s2 = in.next();

		res = new int[s1.length()+1][s2.length()+1];
		for(int i=0;i<=s1.length();i++)
			for(int j=0;j<=s2.length();j++)
				res[i][j]=-1;
		
		pw.println(go(0,0));
		find(pw, 0,0 ,1);
	
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}
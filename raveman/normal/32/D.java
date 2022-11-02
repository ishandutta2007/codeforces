import java.io.File;
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
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);

		int n,m,k;
		n=in.nextInt();
		m=in.nextInt();
		k=in.nextInt();
		
		String[] s= new String[n];
		for(int i=0;i<n;i++)
			s[i] = in.next();
		
		for(int r=1;r<=n;r++)
			for(int x=r;x<n-r;x++)
				for(int y=r;y<m-r;y++) if(s[x].charAt(y) == '*' && s[x-r].charAt(y)=='*' && s[x+r].charAt(y)=='*' && s[x].charAt(y+r)=='*' && s[x].charAt(y-r)=='*'){
					k--;
					if(k==0){
						pw.println(x+1+ " "+(y+1));
						pw.println(x-r+1+ " "+(y+1));
						pw.println(x+r+1+ " "+(y+1));
						pw.println(x+1+ " "+(y-r+1));
						pw.println(x+1+ " "+(y+r+1));
						pw.close();
						return;
					}
				}
		pw.println(-1);
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}
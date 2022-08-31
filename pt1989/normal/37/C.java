import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;
import static java.lang.Math.*;
import static java.lang.Character.*;
import static java.lang.System.*;
import static java.math.BigInteger.*;
import static java.lang.Integer.*;



public class C {
	
	static class node {
	node left, right;
	boolean leaf = false;
	}
	
	static String tmp;
	static boolean add(node v, int rem) {
		
		if (rem==0) {
			if (v.leaf)
				return false;
			
			return v.leaf = true;
		}
		
		
		if (v.left==null || ( v.left != null && !v.left.leaf ) ) {
			//System.out.println(rem + " going left  " );
			if (v.left == null) v.left = new node();
			if( add(v.left, rem-1) ) {
				tmp = "0" + tmp;
				return true;
			}
		}
		if (v.right==null || ( v.right != null && !v.right.leaf ) ) {
			//System.out.println(rem + " going right  " );
			if (v.right == null) v.right = new node();
			if (add(v.right, rem-1)) {
				tmp = "1" + tmp;
				return true;
			}
		}
		
		return false;
	}
	public static void main(String args[]) throws Exception	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		
		ArrayList<Integer> lens = new ArrayList();
		
		for (int i=0; i < n; i++) {
			lens.add(in.nextInt());
		}
		
		ArrayList<Integer> sorted = (ArrayList)lens.clone();
		
		Collections.sort(sorted);
		LinkedList<String> sols[] = new LinkedList[1024];
		for (int i=0; i < 1024; i++) sols[i] = new LinkedList();
		boolean ok = true;
		node root = new node();
		for (int i=0; i < n; i++) {
			int v = sorted.get(i);
			tmp = "";
			ok &= add(root, v);
			sols[ v ].add( tmp );
			//System.out.println(v+ " " + tmp);
		}
		
		if (!ok) {
			System.out.println("NO");
			System.exit(0);
		}
		
		System.out.println("YES");
		for (int i=0; i < n; i++) {
			int x = lens.get(i);
			System.out.println( sols[x].removeFirst() );
		}
		
		
	}
}
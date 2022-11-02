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
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int k = in.nextInt();
		
		int[] x = new int[n];
		
		for(int i=0;i<n;i++)
			x[i] = in.nextInt();
		int X = in.nextInt();
		int Y = in.nextInt();
		
		double res = 0;
		
		if(k == n+1){
			Arrays.sort(x);
			res = x[n-1] - x[0] + Math.hypot(X - x[n-1], Y);
			res = Math.min(res, x[n-1] - x[0] + Math.hypot(X - x[0], Y));
			
		}else{
			int startX = x[k-1];
			Arrays.sort(x);
			
			res = startX - x[0] + x[n-1] - x[0] + Math.hypot(X - x[n-1], Y);
			res = Math.min(res, x[n-1] - startX + x[n-1] - x[0] + Math.hypot(X - x[0], Y));
			
			for(int i=0;i<n;i++){
				double d1 = 0, d2=0;
				
				d1 = Math.hypot(X - x[0], Y) + x[i] - x[0];
				d2 = Math.hypot(X - x[i], Y) + x[i] - x[0];
				
				double d = 0;
				
				if(i==n-1) d = Math.hypot(X - startX, Y);
				else {
					double v1 = Math.abs(x[i+1] - startX) + x[n-1] - x[i+1] + Math.hypot(x[n-1] - X, Y);
					double v2 = Math.abs(x[n-1] - startX) + x[n-1] - x[i+1] + Math.hypot(x[i+1] - X, Y);
					d = Math.min(v1, v2);
				}
				
				
				res = Math.min(res, Math.min(d1,d2) + d);
			}
			
			for(int i=0;i<n;i++){
				double d1 = 0, d2=0;
				
				d1 = Math.hypot(X - x[n-1], Y) + x[n-1] - x[i];
				d2 = Math.hypot(X - x[i], Y) + x[n-1] - x[i];
				
				double d = 0;
				
				if(i==0) d = Math.hypot(X - startX, Y);
				else {
					double v1 = Math.abs(x[0] - startX) + x[i-1] - x[0] + Math.hypot(x[i-1] - X, Y);
					double v2 = Math.abs(x[i-1] - startX) + x[i-1] - x[0] + Math.hypot(x[0] - X, Y);
					d = Math.min(v1, v2);
				}
				
				
				res = Math.min(res, Math.min(d1,d2) + d);
			}
			
		}
		pw.println(String.format("%.10f", res));
		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}
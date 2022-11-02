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
		int[] x = new int[n+1];
		int[] y = new int[n+1];
		int[] t = new int[n+1];
		double[] p = new double[n+1];
		for(int i=1;i<=n;i++){
			x[i] = in.nextInt();
			y[i] = in.nextInt();
			t[i] = in.nextInt();
			p[i] = in.nextDouble();
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(t[i] > t[j]){
					int q = t[i];
					t[i] = t[j];
					t[j] = q;
					
					q = x[i];
					x[i] = x[j];
					x[j] = q;
					
					q = y[i];
					y[i] = y[j];
					y[j] = q;
					
					double w = p[i];
					p[i] = p[j];
					p[j] = w;					
				}
		double r[] = new double[n+1];
		
		double res = 0;
		
		for(int i=1;i<=n;i++){
			r[i] = p[i];
			for(int j=0;j<i;j++) if(r[j] > -0.5)
				if((x[j]-x[i])*(x[j]-x[i])+(y[i]-y[j])*(y[i]-y[j])<=((long)(t[i]-t[j]))*(t[i]-t[j])){
					r[i] = Math.max(r[i], r[j] + p[i]);
			}
			res = Math.max(res, r[i]);
		}
		
		pw.println(String.format("%.10f", res));

		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}
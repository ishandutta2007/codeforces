import java.util.*;
import java.io.*;

public class MyFirstProgram {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		int s = in.nextInt();
		int[] d = new int[n];
		int[] c = new int[n];
		
		for (int i = 0; i < n; i++) {
			d[i] = in.nextInt();
			c[i] = in.nextInt();
			
		}
		int res = 0;
		boolean good = false;
		for (int i = 0; i < n; i++) {
			int tmpd = 0;
			int tmpc = 0;
			if ((tmpd * 100 + tmpc + d[i] * 100 + c[i]) <= s * 100) {
				tmpd += d[i];
				tmpc += c[i];
				tmpd += tmpc / 100;
				tmpc %= 100;
				good = true;
				//System.out.println(tmpd+" "+tmpc);
				if (tmpc != 0) {
					res = Math.max(res, 100 - tmpc);
				}
			}
				
		}
		if (!good) {
			System.out.println(-1);
		} else {	
			System.out.println(res);
		}
 		in.close();
		out.close();
	}

}
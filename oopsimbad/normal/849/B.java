import java.io.*;
import java.text.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int pn = Integer.parseInt(f.readLine());
		int[] y = new int[pn];
		StringTokenizer st = new StringTokenizer(f.readLine());
		for(int i = 0; i < pn; i++) 
			y[i] = Integer.parseInt(st.nextToken());
		boolean out = false;
		for(int o = 1; !out && o < pn; o++) {
			double slope = (double) (y[o] - y[0]) / o;
			double const1 = y[0] - slope;
			double const2 = 0;
			boolean use2 = false;
			boolean allworks = true;
			for(int j = 1; allworks && j < pn; j++) {
				double val = (j+1) * slope;
				if(y[j] == val + const1) continue;
				else if(!use2) {
					use2 = true;
					const2 = y[j] - val;
					continue;
				} else if(use2 && y[j] == val + const2) continue;
				allworks = false;
			}
			if(allworks && use2) out = true;
		}
		if(!out) {
			double slope = (double) (y[2] - y[1]);
			double const1 = y[1] - 2*slope;
			double const2 = 0;
			boolean use2 = false;
			boolean allworks = true;
			for(int j = 0; allworks && j < pn; j++) {
				double val = (j+1) * slope;
				if(y[j] == val + const1) continue;
				else if(!use2) {
					use2 = true;
					const2 = y[j] - val;
					continue;
				} else if(use2 && y[j] == val + const2) continue;
				allworks = false;
			}
			if(allworks && use2) out = true;
		}
		System.out.println(out ? "Yes" : "No");
	}
}
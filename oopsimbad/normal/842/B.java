import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(f.readLine());
		int r = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(f.readLine());
		int times = Integer.parseInt(st.nextToken());
		double mid = (double) (2*r-d) / 2;
		int count = 0;
		while(times-->0) {
			st = new StringTokenizer(f.readLine());
			int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()), rad = Integer.parseInt(st.nextToken());
			double dist = Math.hypot(Math.abs(x), Math.abs(y));
			if(Math.abs(dist-mid) <= d/2. - rad) count++;
		}	
		System.out.println(count);
	}
}
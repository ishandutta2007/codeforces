import java.io.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws Exception {
		new A().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(f.readLine());
		int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
		int times = Integer.parseInt(f.readLine());
		double best = -1;
		while(times-->0) {
			st = new StringTokenizer(f.readLine());
			int tx = Integer.parseInt(st.nextToken()), ty = Integer.parseInt(st.nextToken()), s = Integer.parseInt(st.nextToken());
			double time = Math.hypot(tx-x, ty-y)/s;
			if(time < best || best == -1) best = time;
		}
		System.out.println(best);
	}
}
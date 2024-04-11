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
		int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken()), t = Integer.parseInt(st.nextToken());
		if(t <= k) System.out.println(t);
		else if(t <= n) System.out.println(k);
		else System.out.println(n + k - t);
				
	}
}
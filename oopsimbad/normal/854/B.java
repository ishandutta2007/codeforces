import java.io.*;
import java.text.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(f.readLine());
		int n = Integer.parseInt(st.nextToken()), in = Integer.parseInt(st.nextToken());
		if(in == n || in == 0) System.out.println("0 0");
		else {
			System.out.print("1 ");
			if(in >= Math.ceil(n/3.))
				System.out.println(n - in);
			else System.out.println(in * 2);
		}
	}
}
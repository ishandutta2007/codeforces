import java.io.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws Exception {
		new A().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(f.readLine());
		int i1 = n/2, i2 = (n+1)/2;
		for(int i = 0; i < n/2; i++) {
			if(gcd(i1,i2) == 1) {
				System.out.println(i1 + " " + i2);
				return;
			}
			i1--; i2++;
		}
		System.out.println(i1 + " " + i2);
	}
	public int gcd(int i1, int i2) {
		for(int i = 2; i <= Math.min(i1,i2); i++) if(i1 % i == 0 && i2 % i == 0) return 2;
		return 1;
	} 
}
import java.io.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws Exception {
		new A().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int tot = Integer.parseInt(f.readLine());
		StringTokenizer st = new StringTokenizer(f.readLine());
		int[] sums = new int[tot+1];
		for(int i = 0; i < tot; i++) {
			int v = Integer.parseInt(st.nextToken());
			for(int j = i; j >= 0; j--) sums[j] += v;
		}
		int max = sums[0];
		for(int i = 1; i <= tot; i++) {
			int amt = sums[i] + (i - sums[0] + sums[i]);
			max = Math.max(max, amt);
		}
		System.out.println(max);
	}
}
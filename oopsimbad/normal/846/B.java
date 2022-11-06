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
		int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
		long m = Long.parseLong(st.nextToken());
		long[] arr = new long[k];
		st = new StringTokenizer(f.readLine());
		long sum = 0;
		for(int i = 0; i < k; i++) sum += arr[i] = Long.parseLong(st.nextToken());
		if(sum * n <= m) {
			System.out.println(n * (k+1));
			return;
		}
		Arrays.sort(arr);
		long best = 0;
		for(long i = 0; i <= m/sum; i++) {
			long cur = (k + 1) * i;
			long time = m - i*sum;
			int tind = 0;
			while(tind < k && time > (n-i) * arr[tind]) {
				cur += (n-i);
				time -= (n-i) * arr[tind];
				tind++;
			}
			if(tind < k) cur += time / arr[tind];
			best = Math.max(best, cur);
		}
		System.out.println(best);
	}
}
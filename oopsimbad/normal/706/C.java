import java.io.*;
import java.text.*;
import java.util.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	int[] arr;
	String[] sarr;
	String[] rarr;
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int times = Integer.parseInt(f.readLine());
		arr = new int[times];
		StringTokenizer st = new StringTokenizer(f.readLine());
		for(int i = 0; i < times; i++) arr[i] = Integer.parseInt(st.nextToken());
		sarr = new String[times];
		rarr = new String[times];
		for(int i = 0; i < times; i++) {
			rarr[i] = new StringBuilder(sarr[i] = f.readLine()).reverse().toString();
		}
		long[][] dp = new long[times][2];
		dp[0][0] = 0;
		dp[0][1] = arr[0];
		for(int i = 1; i < times; i++) {
			dp[i][0] = -1;
			if(sarr[i].compareTo(sarr[i-1]) >= 0 && dp[i-1][0] != -1) dp[i][0] = dp[i-1][0];
			if(sarr[i].compareTo(rarr[i-1]) >= 0 && dp[i-1][1] != -1) dp[i][0] = min(dp[i-1][1], dp[i][0]);
			dp[i][1] = -1;
			if(rarr[i].compareTo(sarr[i-1]) >= 0 && dp[i-1][0] != -1) dp[i][1] = dp[i-1][0] + arr[i];
			if(rarr[i].compareTo(rarr[i-1]) >= 0 && dp[i-1][1] != -1) dp[i][1] = min(dp[i-1][1] + arr[i], dp[i][1]);
		}
		//for(long[] arr : dp) System.out.println(Arrays.toString(arr));
		System.out.println(min(dp[times-1][0],dp[times-1][1]));
	}
	public long min(long i1, long i2) {
		if(i1 == -1) return i2;
		if(i2 == -1) return i1;
		return Math.min(i1,i2);
	}
}
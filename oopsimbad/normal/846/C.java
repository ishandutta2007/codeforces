import java.io.*;
import java.text.*;
import java.util.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(f.readLine());
		StringTokenizer st = new StringTokenizer(f.readLine());
		long[] arr = new long[n];
		long[][] sums = new long[n+1][n+1];
		for(int i = 0; i < n; i++) sums[i][i+1] = arr[i] = Long.parseLong(st.nextToken());
		for(int d = 1; d <= n; d++)
			for(int i = 0; i <= n-d; i++) sums[i][i+d] = sums[i][i+d-1] + arr[i+d-1];
		//for(int[] a : sums) System.out.println(Arrays.toString(a));
		long[] dp1 = new long[n+1], dp2 = new long[n+1];
		int[] ind1 = new int[n+1], ind2 = new int[n+1];
		for(int i = 0; i <= n; i++) {
			dp1[i] = sums[0][i];
			ind1[i] = i;
			for(int j = 0; j < i; j++) {
				long sum1 = sums[0][j] - sums[j][i];
				if(sum1 > dp1[i]) {
					ind1[i] = j;
					dp1[i] = sum1;
				}
			}
			dp2[i] = sums[i][n];
			ind2[i] = n;
			for(int j = i; j < n; j++) {
				long sum2 = sums[i][j] - sums[j][n];
				if(sum2 > dp2[i]) {
					ind2[i] = j;
					dp2[i] = sum2;
				}
			}
		}
		//System.out.println(Arrays.toString(dp1));
		//System.out.println(Arrays.toString(dp2));
		//System.out.println(Arrays.toString(ind1));
		//System.out.println(Arrays.toString(ind2));
		long best = -dp1[n-1];
		int[] indexes = new int[3];
		for(int i = 0; i <= n; i++) {
			//System.out.println(i + " " + (dp1[i] + dp2[n-i]));
			if(best < dp1[i] + dp2[i]) {
				best = dp1[i] + dp2[i];
				indexes[0] = ind1[i];
				indexes[1] = i;
				indexes[2] = ind2[i];
			}
		}
		System.out.println(Arrays.toString(indexes).replaceAll("[\\[\\],]", ""));
	}
}
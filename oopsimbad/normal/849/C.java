import java.io.*;
import java.text.*;
import java.util.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	int[][] dp;
	int[] arr;
	int[] vals;
	int index;
	boolean stop;
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int cost = Integer.parseInt(f.readLine());
		if(cost == 0) {
			System.out.println("a");
			return;
		}
		vals = new int[450];
		for(int i = 0; i < vals.length; i++)
			vals[i] = i*(i+1)/2;
		dp = new int[vals.length][cost+1];
		dp[0][0] = 0;
		for(int i = 0; i < vals.length; i++) {
			dp[i][0] = 0;
			for(int j = 1; j <= cost; j++) {
				dp[i][j] = 27;
				if(j >= vals[i] && dp[i][j-vals[i]] != 27) dp[i][j] = dp[i][j-vals[i]] + 1;
				if(i != 0) dp[i][j] = Math.min(dp[i-1][j], dp[i][j]);
			}
		}
		arr = new int[26];
		recur(vals.length-1, cost);
		int i = 0;
		while(arr[i] != 0) {
			while(arr[i]-->0) System.out.print((char) ('a'+i));
			i++;
		}
		System.out.println();
	}
	public void recur(int r, int c) {
		if(c == 0) {
			stop = true;
			return;
		}
		if(r == -1 || dp[r][c] == 27 || stop) return;
		if(vals[r] <= c) {
			arr[index++] = r+1;
			recur(r,c-vals[r]);
			if(stop) return;
			arr[--index] = 0;
		}
		recur(r-1,c);
	}
}
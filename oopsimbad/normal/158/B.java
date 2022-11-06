import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(f.readLine());
		StringTokenizer st = new StringTokenizer(f.readLine());
		int[] cnt = new int[4];
		for(int i = 0; i < n; i++) cnt[Integer.parseInt(st.nextToken())-1]++;
		int m = Math.min(cnt[2], cnt[0]);
		cnt[2] -= m;
		cnt[0] -= m;
		cnt[3] += m;
		
		cnt[1] += cnt[0]/2;
		cnt[0] %= 2;
		
		cnt[3] += cnt[1]/2;
		cnt[1] %= 2;
		
		System.out.println(cnt[3] + cnt[2] + Math.max(cnt[1], cnt[0]));
	}
}
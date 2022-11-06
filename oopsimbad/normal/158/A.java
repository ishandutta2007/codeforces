import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(f.readLine());
		int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
		int[] arr = Arrays.stream(f.readLine().split(" ")).mapToInt(x -> Integer.parseInt(x)).toArray();
		int max = Math.max(arr[k-1], 1);
		int i;
		for(i = 0; i < arr.length; i++) if(arr[i] < max) break;
		System.out.println(i);
	}
}
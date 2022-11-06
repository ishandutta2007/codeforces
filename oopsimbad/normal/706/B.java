import java.io.*;
import java.text.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int times = Integer.parseInt(f.readLine());
		int[] arr = new int[times];
		StringTokenizer st = new StringTokenizer(f.readLine());
		for(int i = 0; i < times; i++) arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);
		times = Integer.parseInt(f.readLine());
		while(times-->0) {
			int v = Integer.parseInt(f.readLine());
			int ind = binSearch(arr, v);
			while(ind < arr.length && v == arr[ind]) ind++;
			System.out.println(ind);
		}
	}
	public int binSearch(int[] arr, int v) {
		int l = 0, h = arr.length;
		while(l < h) {
			int m = (l+h)/2;
			if(arr[m] > v) h = m;
			else if(arr[m] <= v) l = m+1;
		}
		return l;
	}
}
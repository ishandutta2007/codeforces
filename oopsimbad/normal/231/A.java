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
		int cnt = 0;
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(f.readLine());
			if(Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken()) > 1) cnt++;
		}
		System.out.println(cnt);
	}
}
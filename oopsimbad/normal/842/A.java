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
		long l = Long.parseLong(st.nextToken()),
				r = Long.parseLong(st.nextToken()),
						x = Long.parseLong(st.nextToken()),
								y = Long.parseLong(st.nextToken());
		double k = Double.parseDouble(st.nextToken());
		long i;
		boolean printed = false;
		for(i = x; i <= y; i++) {
			double d = k*i;
			if(d != (int) d) continue;
			if(d <= r && d >= l) {
				System.out.println("YES");
				printed = true;
				break;
			}
		}
		if(!printed) System.out.println("NO");
	}
}
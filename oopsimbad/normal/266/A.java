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
		int count = 0;
		int prev = f.read();
		while(n-->1) {
			int i = f.read();
			if(prev == i) count++;
			else prev = i;
		}
		System.out.println(count);
	}
}
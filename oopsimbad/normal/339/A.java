import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		String[] s = f.readLine().split("\\+");
		Arrays.sort(s);
		System.out.println(Arrays.toString(s).replaceAll("[\\[\\],]", "").replaceAll(" ", "+"));
	}
}
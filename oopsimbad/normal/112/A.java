import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int i = f.readLine().toLowerCase().compareTo(f.readLine().toLowerCase());
		System.out.println(i < 0 ? -1 : i > 0 ? 1 : 0);
	}
}
import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		Comparable c = "hi";
		System.out.println(f.readLine().toLowerCase().replaceAll("[aeiouy]", "").replaceAll("(.)", ".$1"));
	}
}
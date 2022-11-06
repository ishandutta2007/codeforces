import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		int times = Integer.parseInt(f.readLine());
		for(int i = 0; i < times; i++) System.out.println(Arrays.toString(Arrays.stream(new String[]{ f.readLine()}).map(x -> x.length() > 10 ? x.charAt(0) + "" + (x.length()-2) + x.charAt(x.length()-1) : x).toArray()).replaceAll("[\\[\\]]",""));
	}
}
import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(Arrays.toString(Arrays.stream(Arrays.toString(Arrays.stream(f.readLine().trim().replaceAll("(\\d+) (\\d+) (\\d+)","$1a$3 $2a$3").split(" ")).mapToInt(x -> (int) Math.ceil(Double.parseDouble(x.substring(0, x.indexOf('a')))/Double.parseDouble(x.substring(1+x.indexOf('a'))))).toArray()).replaceAll("[\\[\\],]", "").split("asdasfwegew")).mapToLong(x -> Long.parseLong(x.substring(0, x.indexOf(' '))) * Long.parseLong(x.substring(1+x.indexOf(' ')))).toArray()).replaceAll("[\\[\\], ]", ""));
	}
}
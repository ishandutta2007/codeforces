import java.io.*;
import java.util.*;
public class A
{
	public static void main (String[] args) throws IOException
	{
		BufferedReader stdin;
		stdin=new BufferedReader (new InputStreamReader(System.in));
		int n;
		String s;
		StringTokenizer st;
		st=new StringTokenizer(stdin.readLine());
		s=st.nextToken();
		n=Integer.parseInt(s);
		System.out.println((n/2)*3);
	}
	
}
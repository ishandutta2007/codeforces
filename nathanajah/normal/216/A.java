import java.io.*;
import java.util.*;

public class A
{
	public static void main(String[] args) throws IOException
	{
		Reader stdin = new Reader(System.in);
		int a,b,c;
		int sisa;
		int i,j;
		int luas=0;
		a= stdin.nextInt();
		b= stdin.nextInt();
		c= stdin.nextInt();
		for (i=0;i<Math.min(b,c);++i)
			luas+=a+i;
		luas*=2;
		sisa=b-c;
		if (sisa<0)
			sisa=-sisa;
		sisa--;
		luas+=sisa*(a+Math.min(b,c)-1);
		System.out.println(luas);
	}
}
class Reader
{
	private BufferedReader x;
	private StringTokenizer st;
	public Reader(InputStream in)
	{
		x = new BufferedReader (new InputStreamReader(in));
		st = null;
	}
	public String nextString() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st=new StringTokenizer(x.readLine());
		return st.nextToken();
	}
	public int nextInt() throws IOException
	{
		return Integer.parseInt(nextString());
	}
	public double nextDouble() throws IOException
	{
		return Double.parseDouble(nextString());
	}
}
import java.io.*;
import java.util.*;

public class A
{
	public static void main(String[] args) throws IOException
	{
		Reader in = new Reader(System.in);
		int n,k;
		n=in.nextInt();
		k=in.nextInt();
		int i;
		int arr[];
		arr = new int[100005];
		for (i=0;i<n;++i)
			arr[i]=in.nextInt();
		boolean bisa=true;
		for (i=k;i<n;++i)
		{
			if (arr[i]!=arr[i-1])
				bisa=false;
		}
		if (!bisa)
			System.out.printf("-1\n");
		else
		{
			int angka=arr[k-1];
			i=k-1;
			while (i>0)
			{
				if (arr[i]!=angka)
					break;
				--i;
			}
			if (arr[i]!=angka)
				++i;
			System.out.printf("%d\n",i);
		}
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
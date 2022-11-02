import java.io.*;
import java.util.*;

public class B
{
	public static void main(String[] args) throws IOException
	{
		Reader in = new Reader(System.in);
		int arr[][];
		arr=new int[1005][1005];
		int kol[];
		kol=new int[1005];
		int row[];
		row= new int[1005];
		int i,j;
		int n,m,k;
		int tmp;
		n=in.nextInt();
		m=in.nextInt();
		k=in.nextInt();
		for (i=0;i<n;++i)
			for (j=0;j<m;++j)
				arr[i][j]=in.nextInt();
		for (i=0;i<n;++i)
			row[i]=i;
		for (i=0;i<m;++i)
			kol[i]=i;
		for (i=0;i<k;++i)
		{
			String q1;
			int q2,q3;
			q1=in.nextString();
			q2=in.nextInt();
			q3=in.nextInt();
			--q2;--q3;
			if (q1.equals("g"))
				System.out.println(arr[row[q2]][kol[q3]]);
			else if (q1.equals("r"))
			{
				tmp=row[q2];
				row[q2]=row[q3];
				row[q3]=tmp;
			}
			else if (q1.equals("c"))
			{
				tmp=kol[q2];
				kol[q2]=kol[q3];
				kol[q3]=tmp;
			}
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
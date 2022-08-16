import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;
import static java.lang.Math.*;
import static java.lang.Character.*;
import static java.lang.System.*;
import static java.math.BigInteger.*;
import static java.lang.Integer.*;

public class Main
{
	static char T[] = new char[5002];
	static int D[] = new int[5002];
	
	static BigInteger solve( int lo, int hi )
	{
		BigInteger ret = BigInteger.ZERO;
		if( lo >= hi ) return ret;
		
		
		Hashtable< Integer, Integer > minT = new Hashtable();
		
		int maxp = -1; 
		int prevp = -1;
		for(int i=lo; i <= hi; i++)
		if( T[i] == 's' )
		{
			Integer PP = minT.get( D[i] );
			if( PP != null )
			{
				if( maxp == -1 || D[maxp] < D[i] )
				{
					maxp = i; prevp = PP;
				}
			}
		}
		else if( T[i] == 'w' )
		{
			minT.put( D[i], i );
		}
		if( maxp == -1 ) return ret;
		
		minT.clear();
		
		ret = ret.add( ret.ONE.shiftLeft( D[maxp] ) );
		ret = ret.add( solve( lo, prevp-1 ).add( solve( maxp+1, hi ) ) );
		
		return ret;
		
	}
	public static void main(String args[]) throws Exception
	{
		BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter out = new PrintWriter( System.out );
		
		int N = Integer.parseInt( in.readLine() );
		
		for(int i=0; i < N; i++)
		{
			String x[] = in.readLine().split(" ");
			T[i] = x[0].charAt( 0 );
			D[i] = Integer.parseInt( x[1] );
		}
		
		out.println( solve( 0, N-1 ) );
		out.close();
		
		
		
	}
}
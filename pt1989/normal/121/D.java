import java.io.*;
import java.util.*;


public class Solution {
    static long lucky[] = new long[1<<20];
    static int size = 0;
    
    static void gen(long x, long max) {
        if (x > max) return;
        if (x > 0) lucky[size++] = x;
        gen(x*10 + 4, max);
        gen(x*10 + 7, max);
    }
    
	public static void main (String args[]) throws Exception {		
		
        
        int n = ni();
        long k = nl();
        
        long lo[] = new long[n];
        long hi[] = new long[n];
        
        long minWidth = (long)2e18;
        for (int i=0; i < n; i++) {
            lo[i] = nl();
            hi[i] = nl();
            minWidth = Math.min(minWidth, hi[i] - lo[i]);
        }
        
        Arrays.sort(lo); Arrays.sort(hi);
        long T = DS.lim;
        gen(0, T); Arrays.sort(lucky, 0, size);
        
        //Find sum of (lucky[i]-hi[z]) for hi[z] <= lucky[i] for z
        DS d = new DS();
        long c1[] = new long[size];
        for (int i=0, z=0; i < size; i++) {
            
            long prev = i == 0 ? 0 : lucky[i-1];
            long inc = lucky[i] - prev;
            d.increment( inc );
            
            while (z < n && hi[z] <= lucky[i]) {
                d.add( lucky[i]-hi[z] );
                z++;
            }
            if (d.inf) {
                c1[i] = d.lim;
            } else {
                c1[i] = d.sum;
            }
        }
        
        //Find sum of (lo[z]-lucky[i]) for lo[z] >= lucky[i] for z
        long c2[] = new long[size];
        d = new DS();
        for (int i=size-1, z=n-1; i >= 0; i--) {
            long inc = i == size-1 ? -lucky[i] : lucky[i+1] - lucky[i];
            d.increment( inc );
            
            while (z >= 0 && lo[z] >= lucky[i]) {
                d.add( lo[z] - lucky[i] );
                z--;
            }
            
            if (d.inf) {
                c2[i] = d.lim;
            } else {
                c2[i] = d.sum;
            }
        }
        
        
        for (int i=0; i < size; i++) {
            //System.err.println( lucky[i] + " -> " + c2[i] + " " + c1[i] );
        }
        int ans = 0;
        for (int L=0; L < size; L++) {
            long v = c2[L];
            //Find H such that c1[H] <= k-v and H >= L
            int lH = L, hH = size, H = L;
            while (lH+1 < hH) {
                H = (lH + hH)/2;
                if (c1[H] <= k-v) {
                    lH = H;
                } else {
                    hH = H;
                }
            }
            H = lH;
            
            lH = L; hH = size; int H2 = L;
            while (lH+1 < hH) {
                H2 = (lH + hH)/2;
                if (lucky[H2] - lucky[L] <= minWidth) {
                    lH = H2;
                } else {
                    hH = H2;
                }
            }
            H = Math.min(H2 = lH, H);
            
            if (c1[H] + v <= k) {
                ans = Math.max(ans, H-L+1);
            }
        }
        System.out.println(ans);
	}
    
    
    
    final static int oo = (int)13e7;
	static BufferedInputStream in = new BufferedInputStream( System.in  );
	static int ni() throws IOException
	{
		
		int ret = 0;
		int x = in.read();
		while( x != -1 && (x < '0' || x > '9' )  && x != '-' )x=in.read();
		boolean neg = false;
		if( x=='-' ) { neg=true; x=in.read(); }
		ret = x-'0';
		x=in.read();
		while(  x >= '0' && x <= '9' && x != -1 )
		{ ret = (ret<<3)+(ret<<1) + x-'0'; x=in.read(); }
		return ret * ( neg ? -1 : 1 );
	}
	static long nl() throws IOException
	{
		
		long ret = 0;
		int x = in.read();
		while( x != -1 && (x < '0' || x > '9' )  && x != '-' )x=in.read();
		boolean neg = false;
		if( x=='-' ) { neg=true; x=in.read(); }
		ret = x-'0';
		x=in.read();
		while(  x >= '0' && x <= '9' && x != -1 )
		{ ret = (ret<<3)+(ret<<1) + x-'0'; x=in.read(); }
		return ret * ( neg ? -1 : 1 );
	}
}


class DS {
    final static long lim = 1000000000000000007L;
    
    long sum = 0;
    long count = 0;
    boolean inf = false;
    void add(long v) {
        count++;
        sum += v;
        if (sum > lim) {
            inf = true;
            sum = lim;
        }
    }
    
    void increment(long dx) {
        if (dx == 0) return;
        
        if ( (count * dx) / dx != count ) {
            inf = true;
            sum = lim;
            return;
        }
        long extra = count * dx;
        sum += extra;
        if (sum > lim) {
            inf = true;
            sum = lim;
        }
    }
}
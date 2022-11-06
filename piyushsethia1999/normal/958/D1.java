import java.io.*;
import java.util.*;
/*
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */
public class Main 
{
	static int gcd(int a, int b)
	{
		if(b==0)
			return a;
		return gcd(b, a%b);
	}
	public static void main(String[] args) throws IOException
	{
		int n=ni();
		String a[]=nsa(n);
		Set<Integer> ho=new HashSet<Integer>();
		Map<Integer, Integer> ho1=new HashMap<Integer, Integer>();
		int te[][]=new int[3][n];
		for(int i=0; i<n; i++)
		{
			int hola=0;
			for(int j=1; j<a[i].length(); j++)
			{
				if(a[i].charAt(j)<='9'&&a[i].charAt(j)>='0')
				{
					if(hola==0)
						te[0][i]=te[0][i]*10+a[i].charAt(j)-'0';
					else if(hola==1)
						te[1][i]=te[1][i]*10+a[i].charAt(j)-'0';
					else
						te[2][i]=te[2][i]*10+a[i].charAt(j)-'0';
				}
				else
					hola++;
			}
			te[0][i]+=te[1][i];
			te[1][i]=gcd(te[0][i], te[2][i]);
			te[0][i]/=te[1][i];
			te[2][i]/=te[1][i];
			if(ho.contains(te[0][i]*1000+te[2][i]))
				ho1.put(te[0][i]*1000+te[2][i], ho1.get(te[0][i]*1000+te[2][i])+1);
			else
				ho1.put(te[0][i]*1000+te[2][i], 1);
			ho.add(te[0][i]*1000+te[2][i]);
		}
		for(int i=0; i<n; i++)
			p(ho1.get(te[0][i]*1000+te[2][i])+" ");
		System.out.println(ans);
	}
	static final long mod=1000000007;
	static final double eps=1e-8;
	static final long inf=100000000000000000L;
	static final boolean debug=false;
	static Reader in=new Reader();
	static StringBuilder ans=new StringBuilder();
	static long powm(long a, long b, long m)
	{
		long an=1;
		long c=a;
		while(b>0)
		{
			if(b%2==1)
				an=(an*c)%m;
			c=(c*c)%m;
			b>>=1;
		}
		return an;
	}
	static Random rn=new Random();
	static void pd(){if(debug)ans.append("hola");}
	static void pd(Object a){if(debug)ans.append(a+"\n");}
	static void pr(Object a){ans.append(a+"\n");}
	static void pr(){ans.append("\n");}
	static void p(Object a){ans.append(a);}
	static void sop(Object a){System.out.println(a);}
	static int ni(){return in.nextInt();}
	static int[] nia(int n){int a[]=new int[n];for(int i=0; i<n; i++)a[i]=ni();return a;}
	static int[] ria(int n){int a[]=new int[n];for(int i=0; i<n; i++){a[i]=rn.nextInt(100);p(a[i]+" ");}pr();return a;}
	static long[] nla(int n){long a[]=new long[n];for(int i=0; i<n; i++)a[i]=nl();return a;}
	static node[] graph(int n) {
		node[] ho=new node[n];
		for(int i=0; i<n; i++)
			ho[i]=new node();
		return ho;
	}
	static String[] nsa(int n){String a[]=new String[n];for(int i=0; i<n; i++)a[i]=ns();return a;}
	static long nl(){return in.nextLong();}
	static String ns(){return in.next();}
	static double nd(){return in.nextDouble();}
	static String pr(String a, long b)
	{
		String c="";
		while(b>0)
		{
			if(b%2==1)
				c=c.concat(a);
			a=a.concat(a);
			b>>=1;
		}
		return c;
	}
	static class Reader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
    }
}
class node
{
	Set<Integer> adj=new HashSet<Integer>();
}
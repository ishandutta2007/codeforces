import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.*;

public class Main
{
	public static InputReader in;
	public static PrintWriter out;
	public static Task solver;
    public static void main(String[] args)
    {
		InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        in = new InputReader(inputStream);
        out = new PrintWriter(outputStream);
        solver = new Task();
        solver.solve();
        out.close();
    }
    public static class Pair
    {
		int first;
		int second;
		Pair(){}
		Pair(int a, int b)
		{
			first=a;
			second=b;
		}
	}
    public static class Task
    {
		Task(){}
		int nax=300*1007;
		
		int n, q;
		int tab[];
		ArrayList < ArrayList <Integer> > wys;
		
		ArrayList < ArrayList <Integer> > end_here;
		
		int lew[];
		int pra[];
		int k[];
		int wyn[];
		
		int how_many[];
		
		int how_many_left(int v, int a)
		{
			int bsa=-1;
			int bsb=wys.get(v).size()-1;
			int bss;
			while(bsa<bsb)
			{
				bss=(bsa+bsb+2)/2;
				if (wys.get(v).get(bss)<=a)
					bsa=bss;
				else
					bsb=bss-1;
			}
			return bsa;
		}
		int ask(int v, int a, int b)
		{
			return how_many_left(v, b)-how_many_left(v, a-1);
		}
		void consider(int v, int x)
		{
			//System.out.println("rozwazam "+v+" "+x);
			if (ask(x, lew[v], pra[v])>((pra[v]-lew[v]+1)/k[v]) && x<wyn[v])
				wyn[v]=x;
			//System.out.println("kuniec");
		}
		void rek(int l, int p, ArrayList <Integer> wek)
		{
			if (l==p)
			{
				for (int i=0; i<wek.size(); i++)
					consider(wek.get(i), tab[l]);
				return;
			}
			int s=(l+p)/2;
			ArrayList <Integer> ll = new ArrayList <Integer>();
			ArrayList <Integer> pp = new ArrayList <Integer>();
			ArrayList <Integer> tu = new ArrayList <Integer>();
			for (int i=0; i<wek.size(); i++)
			{
				int x=wek.get(i);
				if (pra[x]<=s)
				{
					ll.add(x);
					continue;
				}
				if (lew[x]>s)
				{
					pp.add(x);
					continue;
				}
				tu.add(x);
			}
			rek(l, s, ll);
			rek(s+1, p, pp);
			
			for (int i=l; i<=p; i++)
				end_here.get(i).clear();
			for (int i=0; i<tu.size(); i++)
			{
				int x=tu.get(i);
				end_here.get(lew[x]).add(x);
				end_here.get(pra[x]).add(x);
			}
			ArrayList <Pair> trz=new ArrayList <Pair>();
			
			//System.out.println("trzaskam"+l+" "+p);
			
			for (int i=l; i<=p; i++)
				how_many[tab[i]]=0;
			for(int i=s+1; i<=p; i++)
			{
				//System.out.println("w prawo "+i);
				int czy=0;
				for (int j=0; j<trz.size(); j++)
				{
					if (trz.get(j).first==tab[i])
					{
						trz.get(j).second++;
						czy=1;
					}
				}
				if (czy==0)
					trz.add(new Pair(tab[i], 1));
				while(trz.size()>5)
				{
					for (int j=0; j<trz.size(); j++)
					{
						trz.get(j).second--;
						if (trz.get(j).second==0)
						{
							trz.set(j, trz.get(trz.size()-1));
							trz.remove(trz.size()-1);
							j--;
						}
					}
				}
				for (int o=0; o<end_here.get(i).size(); o++)
					for (int j=0; j<trz.size(); j++)
						consider(end_here.get(i).get(o), trz.get(j).first);
			}
			//System.out.println("jade dalej");
			trz.clear();
			for (int i=l; i<=p; i++)
				how_many[tab[i]]=0;
			for(int i=s; i>=l; i--)
			{
				//System.out.println("w lewo "+i);
				int czy=0;
				for (int j=0; j<trz.size(); j++)
				{
					if (trz.get(j).first==tab[i])
					{
						trz.get(j).second++;
						czy=1;
					}
				}
				if (czy==0)
					trz.add(new Pair(tab[i], 1));
				while(trz.size()>5)
				{
					for (int j=0; j<trz.size(); j++)
					{
						trz.get(j).second--;
						if (trz.get(j).second==0)
						{
							trz.set(j, trz.get(trz.size()-1));
							trz.remove(trz.size()-1);
							j--;
						}
					}
				}
				for (int o=0; o<end_here.get(i).size(); o++)
					for (int j=0; j<trz.size(); j++)
						consider(end_here.get(i).get(o), trz.get(j).first);
			}
		}
		void solve()
		{
			n=in.nextInt();
			q=in.nextInt();
			tab = new int[nax];
			wys = new ArrayList <ArrayList <Integer> >();
			end_here = new ArrayList <ArrayList <Integer> >();
			for (int i=0; i<nax; i++)
			{
				wys.add(new ArrayList<Integer>());
				end_here.add(new ArrayList<Integer>());
			}
			for (int i=1; i<=n; i++)
			{
				tab[i]=in.nextInt();
				wys.get(tab[i]).add(i);
			}
			lew = new int[nax];
			pra = new int[nax];
			k = new int[nax];
			wyn = new int[nax];
			how_many = new int[nax];
			ArrayList <Integer> start = new ArrayList <Integer>();
			for (int i=1; i<=q; i++)
			{
				lew[i]=in.nextInt();
				pra[i]=in.nextInt();
				k[i]=in.nextInt();
				wyn[i]=nax;
				start.add(i);
			}
			rek(1, n, start);
			for (int i=1; i<=q; i++)
			{
				if (wyn[i]==nax)
					wyn[i]=-1;
				out.println(wyn[i]);
			}
		}
	}

    static class InputReader
    {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream)
        {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next()
        {
            while (tokenizer == null || !tokenizer.hasMoreTokens())
            {
                try
                {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e)
                {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt()
        {
            return Integer.parseInt(next());
        }

    }
}
#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug printf
using namespace std;
typedef long long ll;
typedef long double ld;


const int N = 105;
char res[N];

vector <string> p1, p2, niema, pc;

int liter['z'+1][N], ile['z'+1][N];

int main ()
{
	int n;
	cin>>n;
	
	if (n==1)
	{
		cout <<"? 1 1\n";
		cout.flush();
		string s;
		cin>>s;
		cout<<"! " << s<<"\n";
		return 0;
	}
	
	int p = n/2;
	
	cout<<"? 1 " <<p <<"\n";
	cout.flush();
	rep(i,0,((p+1) * p)/2)
	{
		string s;
		cin>>s;
		p1.pb(s);
	}
	
	
	p++;
	
	cout<<"? 1 " <<p <<"\n";
	cout.flush();
	rep(i,0,((p+1) * p)/2)
	{
		string s;
		cin>>s;
		p2.pb(s);
	}
	
	for (string &s: p1) sort(s.begin(), s.end());
	for (string &s: p2) sort(s.begin(), s.end());
	
	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());
	
	int i1 = 0, i2 = 0;
	
	while (i1 < (int)p1.size() || i2 < (int)p2.size())
	{
		while (i1 < (int)p1.size() && i2< (int)p2.size() && p1[i1]==p2[i2]) 
		{
			i1++;
			i2++;
		}
		
		if (i1 == (int)p1.size()) 
		{
			if(i2 < (int)p2.size()) 
			{
				niema.pb(p2[i2]);
				i2++;
			}
			continue;
		}
		
		if (i2 == (int)p2.size())
		{
			if (i1 <(int)p1.size())
			{
				niema.pb(p1[i1]);
				i1++;
			}
			continue;
		}
		
		if (p1[i1] < p2[i2])
		{
			niema.pb(p1[i1]);
			i1++;
		}
		else 
		{
			niema.pb(p2[i2]);
			i2++;
		}
	}
	
	for (string s: niema)
	{
		for (char c: s) liter[c][s.size()]++;
	}
	
	rep(i,1,p+2)
	{
		rep(l,'a','z'+1) if (liter[l][i] > liter[l][i-1]) res[p-i] = l;
	}
	
	cerr<<"! ";
	rep(i,0,p) cerr<<res[i];
	cerr<<"\n";
	
	//teraz trzeba zrobic druga polowke
	fprintf(stderr, "robimy drugie pol\n");
	
	cout<<"? 1 " <<n <<"\n";
	cout.flush();
	
	pc.resize((n * (n+1))/2);
	for (string &s: pc) 
	{
		cin>>s;
		for (char c: s) ile[c][(int)s.size()]++;
	}
	
	rep(len,2,2+n/2) //patrzymy komu ubylo 
	{
		vector <char> tab;
		
		fprintf (stderr, "przegladam dlugosc %d\n", len);
		
		rep(c,'a','c')
		{
			fprintf (stderr, "%d vs %d\n", ile[c][len], ile[c][len-1]);
		}
		
		rep(c,'a','z'+1) if (ile[c][len] < ile[c][len-1] + ile[c][1] ) 
		{
			fprintf (stderr, "mam litere %c\n", (char) c);
			tab.pb(c);
			int d = ile[c][len-1] + ile[c][1] - ile[c][len];
			fprintf(stderr, "brakuje %d\n", d);
			ile[c][1]-=d;
		}
		
		
		
		if ((int)tab.size()==1)
		{
			res[n - len +1] = tab[0];
		}
		else if ((int)tab.size()==2)
		{
			if (tab[0]==res[len-2]) res[n-len+1] = tab[1];
			else res[n-len+1] = tab[0];
		}
		else
		{
			assert(0);
		}
		
		fprintf(stderr, "wpisalem res[%d] = %c\n\n", n - len+1, res[n-len+1]);
	}
	
	cout<<"! ";
	rep(i,0,n) cout<<res[i];
	cout<<"\n";
}
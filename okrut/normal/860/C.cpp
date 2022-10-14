#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std; 
typedef long long ll;
typedef long double ld;

const int N = 1e5+3;
vector <string> BAD[2];
vector <int> NUM[2], OK;
int e, ile[N];
char buffer[50];


bool number (string &s, int &ans)
{
	if (s[0]=='0') return false;
	for (char c: s) if (c<'0' || c>'9') return false;
	ans = 0;
	for (char c: s)
	{
		ans = ans * 10 + int(c - '0');
	}
	return true;
}

string druk (int x)
{
	string s;
	int len = sprintf(buffer, "%d", x);
	rep(i,0,len) s.pb(buffer[i]);
	return s;
}
int main ()
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin>>n;
	vector <pair <string, int> > tab(n);
	for (auto &p: tab) 
	{
		cin>>p.fi >>p.se;
		e += p.se;
	}
	rep(i,0,n)
	{
		auto [s,type] = tab[i];
		type  ^= 1;
		int num;
		//cerr<<s <<" goes to \n";
		
		if (number(s, num) && num<=n)
		{
			if (type==0 && num<=e) 
			{
				debug ("OK\n");
				OK.pb(num);
				ile[num]++;
			}
			else if (type==1 && num > e)
			{
				debug ("OK\n");
				OK.pb(num);
				ile[num]++;
			}
			else
			{
				debug ("NUM[%d]\n", type);
				NUM[type].pb(num);
				ile[num]++;
			}
		}
		else 
		{
			debug ("BAD[%d]\n", type);
			BAD[type].pb(s);
		}
	}
	
	vector <string> ans;
	
	vector <int> puste;
	rep(i,1,n+1) if (ile[i]==0) puste.pb(i);
	
	while ((int)OK.size()<n)
	{
		if (!puste.empty())
		{
			int pos = puste.back();
			puste.pop_back();
			int type = 0;
			if (pos>e) type = 1;
			
			debug ("place smth in %d (type %d)\n", pos, type);
			
			string who;
			if (!NUM[type].empty())
			{
				int x = NUM[type].back();
				NUM[type].pop_back();
				
				who = druk(x);
				
				puste.pb(x);
				ile[x]--;
			}
			else if (!BAD[type].empty())
			{
				who = BAD[type].back();
				BAD[type].pop_back();
			}
			else
			{
				assert(0);
			}
			
			OK.pb(pos);
			ile[pos]++;
			
			string where = druk(pos);
			
			ans.pb("move " + who + " " + where);
			
			//cerr<<ans.back() <<"\n";
		}
		else
		{
			if (!NUM[0].empty())
			{
				int x = NUM[0].back();
				NUM[0].pop_back();
				string where = "aldine";
				BAD[0].pb(where);
				string who = druk(x);
				
				ans.pb("move " + who + " " + where);
				
				ile[x]--;
				puste.pb(x);
			}
		}
	}
	
	cout<<ans.size() <<"\n";
	for (string s: ans) cout<<s <<"\n";
}
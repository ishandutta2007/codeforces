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

int a, b;
bool win (int n, int l1, int l2) //ile jest duzych i ile jest w suie
{
	if (max(l1, l2) >=b*2) return false; //on sobie zrobi krotkiego
	if (l1>=b && l1 < a) return false;
	if (l2>=b && l2 < a) return false;
	
	if (l1>=b) n++;
	if (l2>=b) n++;
	
	if (n%2==0) return true;
	else return false;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(q,0,t)
	{
		string s;
		cin>>a >>b >>s;
		int sf = 0;
		vector <int> st;
		s.pb('X');
		for (char c: s)
		{
			if (c=='.') sf++;
			else
			{
				if (sf>=b) st.pb(sf);
				sf = 0;
			}
		}
		
		sort(st.begin(), st.end());
		reverse(st.begin(), st.end());
		
		if (st.empty())
		{
			cout<<"NO\n";
			continue;
		}
		
		if (st.back() < a)
		{
			cout<<"NO\n";
			continue;
		}
		
		int ile = 0;
		for (int x: st) if (x>=b*2) ile++;
		
		if (ile>1)
		{
			cout<<"NO\n";
			continue;
		}
		
		int m = (int)st.size();
		if (ile==1)
		{
			bool ok= false;
			rep(i,0,st[0]-a+1) 
			{
				//debug ("zostal 1 : %d (%d %d)\n", st[0], i, st[0]-a-i);
				if (win(m-1, i, st[0]-a-i)) ok = true;
			}
			if (ok) cout<<"YES\n";
			else cout<<"NO\n";
			
			continue;
		}
		
		
		if (m%2==0) cout<<"NO\n";
		else cout<<"YES\n";
	}
}
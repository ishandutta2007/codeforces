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
 

int main ()
{
	ios_base::sync_with_stdio(false);
	int n;
	vector <bool> on('z'+1, false);
	vector <int> st('z'+1,0), nast('z'+1,0), poprz('z'+1,0);
	cin>>n;
	rep(j,0,n)
	{
		vector <int> ile('z'+1, 0);
		string s;
		cin>>s;
		rep(i,0,(int)s.size())
		{
			if ( (++ile[s[i]]) > 1) 
			{
				cout<<"NO\n";
				return 0;
			}
			on[s[i]] = true;
		}
		rep(i,1,(int)s.size())
		{
			if (nast[s[i-1]]==0) nast[s[i-1]] = s[i];
			if (nast[s[i-1]]!=s[i])
			{
				cout<<"NO\n";
				return 0;
			}
			debug ("pal %c\n", s[i]);
			st[s[i]]++;
		}
		reverse(s.begin(), s.end());
		rep(i,1,(int)s.size())
		{
			if (poprz[s[i-1]]==0) poprz[s[i-1]] = s[i];
			if (poprz[s[i-1]]!=s[i])
			{
				cout<<"NO\n";
				return 0;
			}
		}
	}
	vector <string> res;
	rep(i,'a','z'+1) if (on[i] && st[i]==0)
	{
		string t;
		char x = i;
		t.pb(x);
		on[x] = false;
		int licznik = 0;
		while (nast[x]>0) 
		{
			t.pb(x = nast[x]);
			on[x] = false;
		}
		res.pb(t);
	}
	rep(i,'a','z'+1) if (on[i])
	{
		cout<<"NO\n";
		return 0;
	}
	
	sort(res.begin(), res.end());
	for (string t: res) cout<<t;
	cout<<"\n";
}
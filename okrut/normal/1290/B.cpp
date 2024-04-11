#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf 
using namespace std;
typedef long long ll;
typedef long double ld;

const int N= 2e5+100;

int Ile[N]['z'+1];
int main ()
{
	ios_base::sync_with_stdio(false);
	string s;
	int q;
	cin>>s >>q;
	s = '#' + s;
	int n = s.size();
	
	rep(i,1,n)
	{
		rep(c,'a','z'+1) 
		{
			Ile[i][c] = Ile[i-1][c] + ((char)c==s[i] ? 1: 0);
		
		}
	}
	
	
	
	rep(i,0,q)
	{
		int l, r;
		cin>>l >>r;
		
		if (l==r)
		{
			cout<<"Yes\n";
			continue;
		}
		
		int lit = 0;
		rep(c,'a','z'+1) if (Ile[r][c] > Ile[l-1][c]) lit++;
		
		if (lit==1) cout<<"No\n";
		else if (lit>2) cout<<"Yes\n";
		else
		{
			if (s[l]==s[r]) cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
}
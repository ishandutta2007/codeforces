#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;


int main ()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(q,0,t)
	{
		int n, k;
		string s;
		cin>>n >>k >>s;
		
		int jed = 0;
		for (char c: s) if (c=='W') jed++;
		if (jed==0)
		{
			cout<< max(0, k*2-1) <<"\n";
			continue;
		}
		
		int pkt = jed*2;
		rep(i,0,n) if ((i==0 or s[i-1]=='L') and s[i]=='W') pkt--;
		
		vector <int> seg;
		
		rep(i,1,n) if (s[i-1]=='W' and s[i]=='L')
		{
			int cnt = 0, j=i;
			for (; j<n and s[j]=='L'; j++)
			{
				cnt++;
			}
			if (j<n) seg.pb(cnt);
		}
		
		sort(seg.begin(), seg.end());
		
		pkt+=2*k;
		
		for (int len: seg)
		{
			if (len<=k) pkt++;
			k-=len;
		}
		
		cout<<min(pkt, 2*n-1) <<"\n";
	}
	
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define VV vector
#define pb push_back
#define bitc  __builtin_popcountl
#define inf 1500000000
#define MAXN 1000001
#define eps 0.0000000001
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

//////////////

#define S second
#define F first
#define int long long

/////////////

signed main()
{
	fastio;
	#ifdef ANIKET_GOYAL
		freopen("inputf.in","r",stdin);
		freopen("outputf.in","w",stdout);
	#endif
	int n;
	cin>>n;
	int m;
	cin>>m;
	int a[n];
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	pair<int,int> p[m];
	for(int i=0;i<m;++i)
	{
		cin>>p[i].F>>p[i].S;
	}
	sort(p,p+m);
	for(int i=1;i<m;++i)
	{
		p[i].S=p[i].S+p[i-1].S;
	}
	for(int i=0;i<n;++i)
	{
		int at=a[i];
		int l=0,r=m-1;
		while(l<r)
		{
			int mi=(l+r+1)/2;
			if(p[mi].F>at)
			{
				r=mi-1;
			}
			else
			{
				l=mi;
			}
		}
		int to=0;
		// coout<
		if(p[l].F<=at)
		{
			to+=p[l].S;
		}
		cout<<to<<"\n";
	}
}
//AFO countdown:8 Days
#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int all=(1ll<<45)-1;
int n,k,vis[45],F[45];
map<int,int>t;
vector<int>s[15];

signed main()
{
	n=read(),k=read();s[1].pb(0);
	for (int i=n-1;i>=0;i--)
		F[i]=F[i+1]+(1ll<<i);
	sort(F,F+n+1);
	if (n==1)return puts("ACCEPTED"),0;
	for (int w=1;w<=k;w++)
	{
		int p=read();vector<int>v;
		int cnt=0;t.clear();
		for (int i=1;i<=p;i++)
		{
			int x=read();
			if (!vis[x])vis[x]=1,cnt++;
			v.pb(x);
		}
		for (const int &x:s[w])
		{
			int res=0,X=x;
			for (int i=0;i<v.size();i++)
				if (x&(1ll<<(v[i]-1)))res++,X&=all^(1ll<<(v[i]-1));
			for (int i=v.size()-res;i<v.size();i++)
				X|=(1ll<<(v[i]-1));
			s[w+1].pb(X);
			for (int i=(int)(v.size())-res-1,k=1;k<=cnt;k++,i--)
			{
				X|=(1ll<<(v[i]-1));
				s[w+1].pb(X);
			}
		}
	}int f=0;
	for (int i=1;i<=n;i++)
		if (!vis[i])f=1;
	for (const int &x:s[k+1])
	{
		int tl=0,tr=n,p,pp=x;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (F[Mid]>=pp)p=Mid,tr=Mid-1;
			else tl=Mid+1;
		}
		if (F[p]!=x)f=1;
//		cout<<F[p]<<' '<<pp<<endl;
	}
	if (f)puts("REJECTED");
	else puts("ACCEPTED");
	return 0;
}
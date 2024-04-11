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

const int M=2e5+10;
int n,m,q,f[M],tmp[M],ans;
map<pair<int,int>,int>t;

signed main()
{
	n=read(),m=read(),q=read();int ff=0;
	if (n>m)swap(n,m),ff=1;f[1]=1;
	while(q--){int x=read(),y=read();if (ff)swap(x,y);t[mp(x,y)]=1;}
	while(f[n]!=m)
	{
		for (int i=1;i<=n;i++)tmp[i]=0;ans++;
		for (int i=1;i<=n;i++)
		{
			if (!f[i])continue;
			int now=i+f[i]+(t.find(mp(i,f[i]))!=t.end());
			tmp[i]=max(tmp[i],min(m,now)),tmp[min(n,now)]=max(tmp[min(n,now)],f[i]);
		}
		for (int i=n-1;i>=1;i--)tmp[i]=max(tmp[i],tmp[i+1]);
		for (int i=1;i<=n;i++)f[i]=tmp[i];
	}cout<<ans<<endl;
	return 0;
}
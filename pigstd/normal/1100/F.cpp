#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=5e5+10;
int n,q,a[M],b[40],t[40],ans[M];
vector<pii>v[M];

void insert(int x,int y)
{
	for (int i=20;i>=0;i--)
	{
		if ((x>>i)&1)
		{
			if (!b[i]){b[i]=x,t[i]=y;return;}
			else if (t[i]<y)swap(t[i],y),swap(b[i],x);
			x^=b[i];
		}
	}
}

int get(int x)
{
	int res=0;
	for (int i=20;i>=0;i--)
		if (t[i]>=x)ckmax(res,res^b[i]);
	return res;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	q=read();
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		v[r].pb(mp(l,i));
	}
	for (int i=1;i<=n;i++)
	{
		insert(a[i],i);
		for (auto x:v[i])ans[x.y]=get(x.x);
	}
	for (int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}
/*
5
12 14 23 13 7
1
2 5
*/
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

const int Mod=1e9+7;
const int M=1e5+10;
int n,m,k,a[M],opt[M],x[M],y[M];
vector<pair<int,int> >v[M];
pair<int,int>maxn[M];
struct node
{
	int p;
	double x;
}p[M];

bool cmp1(node a,node b){return a.x>b.x;}
bool cmp2(node a,node b){return opt[a.p]<opt[b.p];}

signed main()
{
	k=read(),n=read(),m=read();int cnt=0;
	for (int i=1;i<=k;i++)a[i]=read(),maxn[i]=mp(a[i],0);
	for (int i=1;i<=n;i++)
	{
		opt[i]=read(),x[i]=read(),y[i]=read();
		if (opt[i]==3)
			p[++cnt].p=i,p[cnt].x=y[i];
		if (opt[i]==2)
			v[x[i]].pb(mp(-y[i],i));
		if (opt[i]==1)
			maxn[x[i]]=max(maxn[x[i]],mp(y[i],i));
	}
	for (int i=1;i<=k;i++)
		if (maxn[i].x!=a[i])
			v[i].pb(mp(-(maxn[i].x-a[i]),maxn[i].y));
	for (int i=1;i<=k;i++)
	{
		sort(v[i].begin(),v[i].end());
		int res=a[i];
		for (int j=0;j<v[i].size();j++)
			p[++cnt].p=v[i][j].y,p[cnt].x=(res-v[i][j].x)*1.0/res,res-=v[i][j].x;
	}
//	for (int i=1;i<=cnt;i++)
//		cout<<p[i].p<<' '<<p[i].x<<endl; 
//	cout<<cnt<<endl;
	sort(p+1,p+1+cnt,cmp1);m=min(m,cnt);
	sort(p+1,p+1+m,cmp2);int res=1;
	for (int i=1;i<=m;i++)
		if (opt[p[i].p]==1)a[x[p[i].p]]=y[p[i].p];
		else if (opt[p[i].p]==2)a[x[p[i].p]]+=y[p[i].p];
		else res=res*y[p[i].p]%Mod;
	for (int i=1;i<=k;i++)
		res=res*a[i]%Mod;
//	cout<<res<<endl;
	cout<<m<<endl;
	for (int i=1;i<=m;i++)
		cout<<p[i].p<<' ';
	return 0;
}
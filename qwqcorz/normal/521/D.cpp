#include<bits/stdc++.h>
#define int long long
#define ll long long
#define piir pair<int,int>
#define pdir pair<long double,int>
#define fi first
#define se second
#define mk make_pair
#define mySort(x) sort(x.begin(),x.end(),greater<piir>())
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N],c[N];
piir cov[N];
vector<piir>add[N],mul;
vector<pdir>b[N];
int o[N];
signed main()
{
	int k=read(),n=read(),m=read();
	for (int i=1;i<=k;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		int opt=read(),x=read(),y=read();
		if (opt==1) cov[x]=max(cov[x],mk(y,i));
		if (opt==2) add[x].push_back(mk(y,i));
		if (opt==3) mul.push_back(mk(y,i));
		o[i]=opt;
	}
	mySort(mul);
	for (auto i:mul) b[0].push_back(mk(i.fi,0));
	for (auto i:mul) add[0].push_back(mk(i.fi,i.se));
	for (int i=1;i<=k;i++)
	{
		mySort(add[i]);
		long double lst=1;
		int now=a[i],siz=add[i].size();
		b[i].resize(siz+(cov[i].fi>a[i]));
		for (int j=0;j<siz;j++)
		{
			now+=add[i][j].fi;
			b[i][j]=mk(1.0L*now/a[i],0);
		}
		if (cov[i].fi>a[i])
		{
			now=cov[i].fi;
			b[i][0]=max(b[i][0],mk(1.0L*now/a[i],1LL));
			for (int j=0;j<siz;j++)
			{
				now+=add[i][j].fi;
				b[i][j+1]=max(b[i][j+1],mk(1.0L*now/a[i],1LL));
			}
		}
		for (int j=siz+(cov[i].fi>a[i])-1;j>0;j--) b[i][j].fi/=b[i][j-1].fi;
	}
	priority_queue<pdir>q;
	for (int i=0;i<=k;i++) if (!b[i].empty()) q.push(mk(b[i][0].fi,i));
	for (int i=1;i<=m;i++)
	{
		if (q.empty()) break;
		int now=q.top().se; q.pop();
		if (++c[now]<(int)b[now].size())
		q.push(mk(b[now][c[now]].fi,now));
	}
	vector<int>ans;
	for (int i=k;i>=0;i--)
	{
		if (c[i]--==0) continue;
		bool flag=b[i][c[i]].se;
		if (flag) ans.push_back(cov[i].se);
		for (int j=0;j<=c[i]-flag;j++) ans.push_back(add[i][j].se); 
	}
	print(ans.size());
	for (int i:ans) print(i,' ');
	
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
struct data
{
	int l,r,x;
	bool operator<(const data&a)const{return x<a.x;}
}a[200010],b[100010];
int c[1000010],n,m;
long long ans;
void modify(int x,int y){for(;x<=(int)1e6;x+=x&(-x))c[x]+=y;}
int get(int x){int s=0;for(;x;x-=x&(-x))s+=c[x];return s;}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)
	{
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		a[2*i-1]={1,x,l};
		a[2*i]={-1,x,r+1};
		if(l==0&&r==(int)1e6)ans++;
	}
	sort(a+1,a+2*n+1);
	rep(i,m)
	{
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		b[i]={l,r,x};
		if(l==0&&r==(int)1e6)ans++;
	}
	sort(b+1,b+m+1);
	int now=1;
	rep(i,m)
	{
		for(;now<=2*n&&a[now].x<=b[i].x;now++)modify(a[now].r,a[now].l);
		ans+=get(b[i].r)-get(max(0,b[i].l-1));
	}
	printf("%lld\n",ans+1);
    return 0;
}
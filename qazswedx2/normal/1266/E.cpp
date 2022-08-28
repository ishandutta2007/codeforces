#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y;
	pt(int x=0,int y=0):x(x),y(y){}
	bool operator<(const pt xx) const
	{
		return x==xx.x?y<xx.y:x<xx.x;
	}
};
map<pt,int> mp;
int n,m,a[1000005],b[1000005];
ll tans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),tans+=a[i];
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(mp.count(pt(u,v)))
		{
			int nw=mp[pt(u,v)];
			if(b[nw]<=a[nw]) tans++;
			b[nw]--;
			mp.erase(pt(u,v));
		}
		if(w)
		{
			b[w]++;
			if(b[w]<=a[w]) tans--;
			mp[pt(u,v)]=w;
		}
		printf("%I64d\n",tans);
	}
	return 0;
}
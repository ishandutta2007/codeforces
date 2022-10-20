#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int h[N],a[N],n,m,k,p,l=0,r=0;
struct node
{
	int pos,val;
	bool operator <(const node &a)const
	{
		return val>a.val;
	}
};
int now[N];
bool check(int H)
{
	priority_queue<node>q;
	for (int i=1;i<=n;i++)
	{
		now[i]=H;
		if (now[i]-m*a[i]<h[i]) q.push((node){i,now[i]/a[i]});
	}
	for (int j=1;j<=m;j++)
	for (int i=1;i<=k;i++)
	{
		if (q.empty()) return 1;
		int x=q.top().pos; q.pop();
		if (now[x]-j*a[x]<0) return 0;
		now[x]+=p;
		if (now[x]-m*a[x]<h[x]) q.push((node){x,now[x]/a[x]});
	}
	return q.empty();
}

signed main()
{
	n=read(),m=read(),k=read(),p=read();
	for (int i=1;i<=n;i++)
	{
		h[i]=read(),a[i]=read();
		r=max(r,h[i]+a[i]*m);
	}
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
				   else l=mid+1;
	}
	print(l);
	
	return 0;
}
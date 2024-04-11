#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

pair<int,int>ask(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int x=read(),y=read();
	return make_pair(x,y);
}
int a[N];
void solve(int l,int r,int vl,int vr)
{
	if (l>r) return;
	if (vl==vr)
	{
		for (int i=l;i<=r;i++) a[i]=vl;
		return;
	}
	auto [x,y]=ask(l,r);
	int L=r-y+1,R=l+y-1;
	if (L<=R)
	{
		for (int i=L;i<=R;i++) a[i]=x;
		solve(l,L-1,vl,x);
		solve(R+1,r,x,vr);
	}
	else
	{
		int mid=(l+r)/2;
		solve(l,mid,vl,vr);
		solve(mid+1,r,vl,vr);
	}
}
signed main()
{
	int n=read();
	solve(1,n,1,1e9);
	printf("! ");
	for (int i=1;i<=n;i++) print(a[i]," \n"[i==n]);
	
	return 0;
}
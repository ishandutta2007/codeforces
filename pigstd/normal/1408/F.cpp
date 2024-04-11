#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

const int M=5e5;
int cnt,a[M],b[M],n;

void solve(int l,int r)
{
	if (l==r)return;
	int Mid=(l+r)>>1;
	solve(l,Mid),solve(Mid+1,r);
	int ll=l,rr=r;
	while(ll<=rr)
	{
		a[++cnt]=ll,b[cnt]=rr;
		ll++,rr--;
	}
}

signed main()
{
	n=read();int k=1;
	while(k*2<n)k*=2;
	solve(1,k),solve(n-k+1,n);
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++)
		cout<<a[i]<<' '<<b[i]<<endl;
	return 0;
}
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

const int M=3e5+10;
int n,a[M];

struct BIT
{
	int c[M];
	int lowbit(int x){return x&(-x);}
	void add(int k,int x)
	{
		for (int i=k;i<M;i+=lowbit(i))
			c[i]+=x;
	}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))
			res+=c[i];
		return res;
	}
	int query(int l,int r){return ask(min(r,M-1))-ask(l-1);}
}T1,T2;

signed main()
{
	n=read();int res=0,sum=0;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)
	{
		res+=a[i]*(i-1)-T2.ask(a[i]);int s1=0;
		for (int j=1;j<=M/a[i]+1;j++)
			s1+=(T1.query((j-1)*a[i],a[i]*j-1))*(j-1);
		res+=sum-s1*a[i];
		cout<<res<<' ';sum+=a[i];
		T1.add(a[i],1);
		for (int j=2;j<=M/a[i]+1;j++)
			T2.add((j-1)*a[i],a[i]);
	}
	return 0;
}
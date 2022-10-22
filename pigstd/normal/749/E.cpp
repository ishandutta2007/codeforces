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

const int M=1e5+10;
int n,p[M];
double ans;
struct BIT
{
	int c[M];
	int lowbit(int x){return x&(-x);}
	void add(int u,int x)
	{
		for (int i=u;i<=n;i+=lowbit(i))
			c[i]+=x;
	}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))res+=c[i];
		return res;
	}
	int query(int l,int r){return ask(r)-ask(l-1);}
}T1,T2;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)p[i]=read();
	for (int i=n;i>=1;i--)
	{
		int res=0;
		res+=T1.ask(p[i])*(i*(i+1)+(n-i)*(n-i+1));
		res+=i*(2*T1.ask(p[i])*(n-i)+T2.query(p[i]+1,n)-T2.ask(p[i]));
		ans+=res*1.0/(n*(n+1));
//		cout<<res<<endl;
		T1.add(p[i],1),T2.add(p[i],n-i+1);
	}printf("%.12lf",ans);
	return 0;
}
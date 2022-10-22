#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18;
const int M=5e5+10;
int n,b[M],a[M],k;

pii check(int x)
{
	priority_queue<int>q1,q2;
	int res=0;
	for (int i=n;i>=1;i--)
	{
		q2.push(-(b[i]-x));
//		cerr<<"qwq\n";assert(q2.size());
		int t1=(q1.size()?q1.top():-inf),t2=q2.top();
		if (a[i]>t1&&a[i]>t2);
		else if (t1>t2)res+=a[i]-t1,q1.pop(),q1.push(a[i]);
		else res+=a[i]-t2,q2.pop(),q1.push(a[i]);
	}
	return mp(q1.size(),res);
}

signed main()
{
//	freopen("cof.in","r",stdin);
//	freopen("cof.out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)b[i]=read();
	int tl=-2e9,tr=2e9,res=-1;
	while(tl<=tr)
	{
//		cerr<<tl<<' '<<tr<<'\n';
		int Mid=(tl+tr)/2;
		auto x=check(Mid);
		if (x.x>=k)res=x.y+k*Mid,tr=Mid-1;
		else tl=Mid+1;
	}
	cout<<res<<'\n';
	return 0;
}
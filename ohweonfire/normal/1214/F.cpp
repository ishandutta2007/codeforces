// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int n,L,ans[200111],pre[400111];
pii a[400111];
int main()
{
	get2(L,n);
	for(int i=0;i<n;i++)
	{
		get1(a[i].ff);
		a[i].ss=i+1;
	}
	for(int i=0;i<n;i++)
	{
		get1(a[i+n].ff);
		a[i+n].ss=-i-1;
	}
	sort(a,a+n+n);
	int cur=0;
	vector<pii>vs;
	for(int i=0;i<n+n;i++)
	{
		if(a[i].ss<0)cur--;
		else cur++;
		pre[i]=-inf;
		if(i<n+n-1&&a[i].ff!=a[i+1].ff)
		{
			vs.pb(mp(cur,a[i+1].ff-a[i].ff));
			pre[i]=cur;
		}
		else if(i==n+n-1)
		{
			vs.pb(mp(cur,a[0].ff+L-a[i].ff));
			pre[i]=cur;
		}
	}
	sort(vs.begin(),vs.end());
	int sum=0,piv=0;
	for(int i=0;i<(int)vs.size();i++)
	{
		sum+=vs[i].ss;
		if(sum>=(L+1)/2)
		{
			piv=vs[i].ff;
			break;
		}
	}
	LL ans2=0;
	for(int i=0;i<(int)vs.size();i++)ans2+=1ll*abs(piv-vs[i].ff)*vs[i].ss;
	printendl(ans2);
	
	for(int i=0;i<n+n;i++)if(pre[i]==piv){piv=i+1;break;}
	cur=piv;if(cur==n+n)cur=0;
	for(int i=piv;i<n+n;i++)if(a[i].ss>0)
	{
		while(a[cur].ss>0){cur++;if(cur==n+n)cur=0;}
		ans[a[i].ss]=-a[cur].ss;cur++;if(cur==n+n)cur=0;
	}
	for(int i=0;i<piv;i++)if(a[i].ss>0)
	{
		while(a[cur].ss>0){cur++;if(cur==n+n)cur=0;}
		ans[a[i].ss]=-a[cur].ss;cur++;if(cur==n+n)cur=0;
	}
	
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
// Author: Little09
// Problem: B. Rain
// Contest: Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
ll n,m,T; 
struct point
{
	ll x,y,id,h,p,ans;
}a[N];
bool cmp(point x,point y)
{
	return x.x<y.x;
}
bool cmp2(point x,point y)
{
	return x.id<y.id;
}

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
multiset<ll>s;
ll tot,sum;
void del(ll x)
{
	while (!s.empty()&&(*s.begin())<=tot+x) 
	{
		sum-=(*s.begin())-tot;
		s.erase(s.begin());
	}
	tot+=x;
	sum-=1ll*x*(s.size());
}
void add(ll x)
{
	sum+=x;
	s.insert(x+tot);
}
void work(int id)
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) 
	{
		a[i].x=read(),a[i].y=read();
		a[i].id=i,a[i].h=0,a[i].ans=1;
	}
	sort(a+1,a+n+1,cmp);
	int las=-1;
	sum=0,tot=0;
	s.clear();
	for (int i=1;i<=n;i++)
	{
		if (i!=1) del(a[i].x-las);
		las=a[i].x;
		add(a[i].y);
		a[i].h+=sum;
	}
	las=-1,sum=0,tot=0;
	s.clear();
	for (int i=n;i>=1;i--)
	{
		if (i!=n) del(las-a[i].x);
		las=a[i].x;
		add(a[i].y);
		a[i].h+=sum;
	}
	for (int i=1;i<=n;i++) a[i].h-=a[i].y;
	for (int i=1;i<=n;i++)
	{
		if (a[i].h>m)
		{
			a[i].p=a[i].h-m;
		}
		else a[i].p=0;
	}
	sum=0,tot=0;
	s.clear();
	for (int i=1;i<=n;i++)
	{
		if (i!=1) del(las-a[i].x);
		las=a[i].x;
		if (a[i].p!=0) add(a[i].p);
		if (!s.empty()&&a[i].y<*s.rbegin()-tot) a[i].ans=0;
	}
	sum=0,tot=0;
	s.clear();
	for (int i=n;i>=1;i--)
	{
		if (i!=n) del(a[i].x-las);
		las=a[i].x;
		if (a[i].p!=0) add(a[i].p);
		if (!s.empty()&&a[i].y<*s.rbegin()-tot) a[i].ans=0;
	}
	sort(a+1,a+n+1,cmp2);
	for (int i=1;i<=n;i++) printf("%d",a[i].ans);
	cout << endl;
}

int main()
{
	T=read();
	for (int i=1;i<=T;i++) work(i);
	return 0;
}
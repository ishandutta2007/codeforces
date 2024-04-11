#include<bits/stdc++.h>
using namespace std;
clock_t __t=clock();
#define rep(i,x,y) for (int i=(x);i<=(y);++i)
#define drep(i,y,x) for (int i=(y);i>=(x);--i)
#define temp template<typename T>
temp bool chkmin(T &x,T y){return x>y?x=y,1:0;}
temp bool chkmax(T &x,T y){return x<y?x=y,1:0;}
#define ll long long
#define db long double
void file()
{
	#ifdef NTFAKIOI
	freopen("a.in","r",stdin);
	#endif
}
void chktime()
{
	#ifdef NTFAKIOI
	cout<<1.0*(clock()-__t)/1000;
	#endif
}
temp void read(T &x)
{
	x=0;char ch=getchar(),t=0;
	while (ch>'9'||ch<'0') t|=(ch=='-'),ch=getchar();
	while (ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	x=(t?-x:x);
}
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define pii pair<int,int>
#define fir first
#define sec second
#define MP make_pair
#define sz 1010

int n,m;
db a[sz],b[sz];
#define CHK if (tot<m-1e-9||w<-1e-9) return 0
bool check(db w)
{
	db tot=w+m;
	db cur=tot/a[1];tot-=cur,w-=cur;CHK;
	rep(i,2,n)
	{
		cur=tot/b[i],tot-=cur,w-=cur;
		CHK;
		cur=tot/a[i],tot-=cur,w-=cur;
		CHK;
	}
	cur=tot/b[1];tot-=cur,w-=cur;CHK;
	return 1;
}

int main()
{
	file();
	read(n),read(m);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) read(b[i]);
	db l=0,r=1e9,ans=1e9;
	while (r-l>1e-9)
	{
		db mid=(l+r)/2;
		if (check(mid)) ans=mid,r=mid;
		else l=mid;
	}
	if (!check(1e9)) return puts("-1"),0;
	cout<<setprecision(8)<<fixed<<ans;
	return 0;
}
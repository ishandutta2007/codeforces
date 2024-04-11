#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i=(x);i<=(y);++i)
#define drep(i,y,x) for (int i=(y);i>=(x);--i)
#define temp template<typename T>
temp bool chkmax(T &x,T y){return x<y?x=y,1:0;}
temp bool chkmin(T &x,T y){return x>y?x=y,1:0;}
#define pii pair<int,int>
#define fir first
#define sec second
#define MP make_pair
temp void read(T &x)
{
	x=0;char ch=getchar(),t=0;
	while (ch>'9'||ch<'0') t|=(ch=='-'),ch=getchar();
	while (ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	if (t) x=-x;
}
void file()
{
	#ifdef NTFAKIOI
	freopen("a.in","r",stdin);
	#endif
}
#define db double
#define ll long long
#define sz 202200

int n;
int tr[sz];
void add(int x,int w){while (x<=n) tr[x]+=w,x+=(x&(-x));}
int query(int x){int ret=0;while (x) ret+=tr[x],x-=(x&(-x));return ret;}
int a[sz],pos[sz];

int main()
{
	file();
	read(n);
	rep(i,1,n) read(a[i]),add(i,1),pos[a[i]]=i;
	drep(i,n-1,1)
	{
		int l=pos[n],r=pos[i];
		if (l>r) swap(l,r);
		int s=query(r)-query(l-1);
		if (s!=2) return puts("NO"),0;
		add(pos[i],-1);
	}
	puts("YES");
	return 0;
}
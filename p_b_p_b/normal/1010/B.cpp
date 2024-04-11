#include<bits/stdc++.h>
using namespace std;
clock_t __t=clock();
#define rep(i,x,y) for (int i=(x);i<=(y);++i)
#define drep(i,y,x) for (int i=(y);i>=(x);--i)
#define temp template<typename T>
temp bool chkmin(T &x,T y){return x>y?x=y,1:0;}
temp bool chkmax(T &x,T y){return x<y?x=y,1:0;}
#define ll long long
#define db double
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

ll m;
int n;
bool type[35];

int ask(int x){printf("%d\n",x);fflush(stdout);int ret;read(ret);if (ret==-2||!ret) exit(0);return ret;}

int main()
{
//	file();
	read(m),read(n);
	rep(i,1,n) type[i]=(ask(m)==-1);
	int l=1,r=m,i=1;
	while (l<=r)
	{
		int mid=(l+r)>>1,c=ask(mid);
		if (!c) return 0;
		if (!type[i]) c=-c;
		if (c>0) l=mid+1;
		else r=mid-1;
		++i;if (i>n) i-=n;
	}
	return 0;
}
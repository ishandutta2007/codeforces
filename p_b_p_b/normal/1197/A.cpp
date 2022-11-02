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
#define sz 101010

int n;
int a[sz];
void work()
{
	read(n);
	rep(i,1,n) read(a[i]);
	sort(a+1,a+n+1);
	int ans=min(n-2,a[n-1]-1);
	printf("%d\n",ans);
}

int main()
{
	file();
	int T;read(T);
	while (T--) work();
	return 0;
}
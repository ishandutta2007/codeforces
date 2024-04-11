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
#define sz 303030

int n,K;
int a[sz];
int aa[sz];

int main()
{
	file();
	read(n),read(K);
	rep(i,1,n) read(a[i]);
	rep(i,1,n-1) aa[i]=a[i+1]-a[i];
	sort(aa+1,aa+n);
	int ans=a[n]-a[1];
	drep(i,n-1,n-1-K+2) ans-=aa[i];
	cout<<ans;
	return 0; 
}
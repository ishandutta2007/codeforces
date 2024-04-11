#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void answer(int n,string s)
{
	if (n<0) puts("IMPOSSIBLE"),exit(0);
	if (n<=2e5) puts("SMALL"),print(s.size()),reverse(s.begin(),s.end()),cout<<s<<endl;
		   else puts("BIG"),print(n);
	exit(0);
}
int a[N],b[N];
bool check0(int *a,int *b,int n)
{
	for (int i=1;i<=n;i++) if (a[i]!=b[i]) return 0;
	return 1;
}
bool check1(int *a,int *b,int n)
{
	for (int i=1;i<=n;i++) if (a[i]!=b[n-i+1]) return 0;
	return 1;
}
bool up(int *a,int n)
{
	for (int i=1;i<n;i++) if (a[i]>a[i+1]) return 0;
	return 1;
}
bool down(int *a,int n)
{
	for (int i=1;i<n;i++) if (a[i]<a[i+1]) return 0;
	return 1;
}
int gcd(int x,int y)
{
	if (x==0) return -1;
	if (x==a[1]&&y%x==a[2]%x&&y%x<=a[2]&&a[2]<=y) return (y-a[2])/x;
	if (x==a[2]&&y%x==a[1]%x&&y%x<=a[1]&&a[1]<=y) return (y-a[1])/x;
	int ret=gcd(y%x,x);
	if (ret<0) return -1;
	return ret+y/x;
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	if (n==1) answer(a[1]==b[1]?0:-1,"");
	if (n==2)
	{
		int ans=gcd(b[1],b[2]);
		if (ans<0) answer(-1,"");
		if (ans>2e5) answer(ans,"");
	}
	int ans=0;
	string s;
	for (int i=1;i<=2e6;i++)
	{
		if (check0(a,b,n)) answer(ans,s);
		if (check1(a,b,n)) answer(ans,s+='R');
		if (down(b,n)) reverse(b+1,b+1+n),s+='R';
		if (!up(b,n)) answer(-1,"");
		ans++,s+='P';
		for (int i=n;i>1;i--) b[i]-=b[i-1];
	}
	answer(-1,"");
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
ll a,b,c,d,ans,ansi,ansj,ansk,ansp;

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
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

void f(ll i,ll j,ll k,ll p)
{
	ll res=abs(c-i)+abs(d-j)+abs(i-k)+abs(j-p)+abs(k-c)+abs(p-d);
	if (res>=ans) ansi=i,ansj=j,ansk=k,ansp=p,ans=res;
}

void work()
{
	cin >> a >> b >> c >> d;
	ans=0;
	f(1,1,a,1);
	f(1,1,a,b);
	f(1,1,1,b);
	f(1,b,a,1);
	f(1,b,a,b);
	f(a,1,a,b);
	printf("%lld %lld %lld %lld\n",ansi,ansj,ansk,ansp);
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}
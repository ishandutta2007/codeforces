//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 500010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
void rout(ll x){
	if(x<0) putchar('-'),rout(-x);
	else if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll n,ans[705][705],a[N];
int main(){
	ll i,x,y,t;
	n=rint();
	while(n--)
	{
		t=rint(),x=rint(),y=rint();
		if(t==1)
		{
			for(i=1;i<705;++i)
			{
				ans[i][x%i]+=y;
			}
			a[x]+=y;
		}
		else
		{
			if(x>=705)
			{
				ll res=0;
				for(i=y;i<N;i+=x)
				{
					res+=a[i];
				}
				rout(res),putchar('\n');
			}
			else
			{
				rout(ans[x][y]),putchar('\n');
			}
		}
	}
	return 0;
}
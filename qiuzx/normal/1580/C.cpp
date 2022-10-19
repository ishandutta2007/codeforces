//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 200010
#define B 600
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,m,upd[N],del[N],curans=0,beg[N],hvmod[B+5][B+5],ad[N];
int main(){
	ll i,op,x,j;
	n=rint(),m=rint();
	for(i=1;i<=n;i++)
	{
		upd[i]=rint(),del[i]=upd[i]+rint();
	}
	for(i=0;i<m;i++)
	{
		op=rint(),x=rint();
		if(op==1)
		{
			beg[x]=i;
			++curans;
			if(del[x]>B)
			{
				for(j=beg[x];j<m;j+=del[x])
				{
					--ad[j];
					if(j+upd[x]<m)
					{
						++ad[j+upd[x]];
					}
				}
			}
			else
			{
				--hvmod[del[x]][i%del[x]];
				++hvmod[del[x]][(i+upd[x])%del[x]];
			}
		}
		else
		{
			if((i-beg[x])%del[x]>upd[x]||(i-beg[x])%del[x]==0)
			{
				--curans;
			}
			if(del[x]>B)
			{
				for(j=beg[x];j<m;j+=del[x])
				{
					++ad[j];
					if(j+upd[x]<m)
					{
						--ad[j+upd[x]];
					}
				}
			}
			else
			{
				++hvmod[del[x]][beg[x]%del[x]];
				--hvmod[del[x]][(beg[x]+upd[x])%del[x]];
			}
		}
		curans+=ad[i];
		for(j=1;j<=B;j++)
		{
			curans+=hvmod[j][i%j];
		}
		printf("%d\n",curans);
	}
	return 0;
}
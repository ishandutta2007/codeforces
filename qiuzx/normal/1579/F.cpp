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
#define N 1000010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,d,a[N],ans;
bool vis[N];
void solve()
{
	ll i,j,cnt,st;
	bool hv0;
	n=rint(),d=rint();
	for(i=0;i<n;i++)
	{
		vis[i]=false;
		a[i]=rint();
	}
	ans=0;
	for(i=0;i<d;i++)
	{
		if(!vis[i])
		{
			hv0=false;
			cnt=0;
			st=0;
			for(j=i;!vis[j];j=(j+d)%n)
			{
				vis[j]=true;
				if(a[j]==0)
				{
					hv0=true;
					cnt=0;
				}
				else
				{
					st+=(!hv0);
					cnt++;
					ans=max(ans,cnt);
				}
			}
			if(!hv0)
			{
				puts("-1");
				return;
			}
			ans=max(ans,cnt+st);
		}
	}
	printf("%d\n",ans);
	return;
}
int main(){
	ll T;
	T=rint();
	while(T--)
	{
		solve();
	}
	return 0;
}
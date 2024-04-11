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
ll n,mx[(1<<20)+5],ans=0;
bool vis[(1<<20)+5];
char buf[N];
string s;
int main(){
	ll i,j,mask,nmask;
	scanf("%s",&buf);
	s=buf;
	n=s.size();
	for(i=0;i<n;i++)
	{
		mask=0;
		for(j=i;j>=0;j--)
		{
			if(mask&(1<<(s[j]-'a')))
			{
				break;
			}
			mask|=(1<<(s[j]-'a'));
			vis[mask]=true;
			mx[mask]=max(mx[mask],i-j+1);
		}
	}
	for(i=0;i<(1<<20);i++)
	{
		for(j=0;j<20;j++)
		{
			mx[i|(1<<j)]=max(mx[i|(1<<j)],mx[i]);
		}
	}
	for(i=0;i<(1<<20);i++)
	{
		if(vis[i])
		{
			nmask=((1<<20)-1)^i;
			ans=max(ans,mx[nmask]+mx[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
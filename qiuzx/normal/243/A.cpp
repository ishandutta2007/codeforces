#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,a[N],lst[26],ans=0;
bool vis[30*N];
vector<ll> v;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
int main(){
	ll i,j,st;
	n=rint();
	for(i=0;i<n;i++)
	{
		a[i]=rint();
	}
	memset(lst,-1,sizeof(lst));
	for(i=0;i<n;i++)
	{
		vis[a[i]]=true;
		if(a[i]==0)
		{
		    continue;
		}
		for(j=0;j<22;j++)
		{
			if(a[i]&(1<<j))
			{
				lst[j]=i;
			}
		}
		st=a[i];
		v.clear();
		for(j=0;j<22;j++)
		{
			if(lst[j]!=-1)
			{
				v.push_back(lst[j]);
			}
		}
		sort(v.begin(),v.end());
		for(j=v.size()-1;j>=0;j--)
		{
			st|=a[v[j]];
			vis[st]=true;
		}
	}
	for(i=0;i<=(1<<20);i++)
	{
		if(vis[i])
		{
			ans++;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
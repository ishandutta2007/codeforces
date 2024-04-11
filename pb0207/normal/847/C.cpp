#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+1;
ll n,k,g,a[N],tot,ans[N];

void solve(ll r,ll k)
{
	if(!k)return;
	if(k<=g)ans[k]++;
	else    {printf("Impossible");exit(0);}
	tot++;
	return;
}

void dfs(int x)
{
	if(!ans[x])return;
	printf("(");
	dfs(x+1);
	printf(")");
	for(int i=2;i<=ans[x];++i)
	{
		printf("(");
		printf(")");
	}
}
// 0 1 2 2 3 4
//( ( () ((())) ) )
int main()
{
//	freopen("c.i-+n","w",stdout);
	for(ll i=1;i<N;++i)a[i]=a[i-1]+i;
	cin>>n>>k;
	g=upper_bound(a+1,a+n+1,k)-a-1;
	for(int i=0;i<=g;++i)ans[i]++;
	tot+=g+1;
	solve(g,k-a[g]);
	if(tot>n)return 0*printf("Impossible");
	if(tot<n)for(int i=1;i<=n-tot;++i)printf("()");
	dfs(0);
}
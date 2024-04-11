#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

long long i,j,m,n,p,k,ans,l,r;

long long f[N];

long long work(long long x,int dep)
{
		if (x<=1) return f[dep]=x;
		return f[dep]=2*work(x/2,dep+1)+1; 
}

void dfs(long long n,int dep,long long k)
{
		if (n<=1) ans+=n;
		else if (f[dep+1]+1==k) ans+=n%2;
		else if (k<=f[dep+1]) dfs(n/2,dep+1,k);
		else dfs(n/2,dep+1,k-f[dep+1]-1);
}

int main()
{
	cin>>n>>l>>r;
	work(n,0);
	for (i=l;i<=r;++i) dfs(n,0,i);
	printf("%d\n",ans);
}
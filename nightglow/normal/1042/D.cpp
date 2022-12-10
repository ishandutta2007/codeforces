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

int i,j,m,n,p,k;

long long sum[N],t,tree[N],ans,c[N];

int lowbit(int x)
{
		return x&-x;
}

int ask(int x)
{
		int s=0;
		for (;x;x-=lowbit(x)) s+=tree[x];
		return s;
}

void insert(int x)
{
		for (;x<=c[0];x+=lowbit(x)) tree[x]++;
}

int main()
{
	 scanf("%d%lld",&n,&t);
	 for (i=1;i<=n;++i) scanf("%lld",&sum[i]),sum[i]+=sum[i-1];
	 for (i=0;i<=n;++i) c[++c[0]]=sum[i];
	 sort(c+1,c+c[0]+1); c[0]=unique(c+1,c+c[0]+1)-(c+1);
	 for (i=0;i<=n;++i)
	 {
	 		ans+=ask(upper_bound(c+1,c+c[0]+1,sum[i]-t)-c-1);
	 		insert(lower_bound(c+1,c+c[0]+1,sum[i])-c);
	 }
	 cout<<1ll*n*(n+1)/2-ans<<endl;
}
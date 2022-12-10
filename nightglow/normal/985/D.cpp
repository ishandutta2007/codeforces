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

int i,j,p,k;

long long n,m,ans=(long long)1e18;

long long get(long long p)
{
		long long l=0,r=2e9,Mid=0;
		while ((l+r)>>1!=Mid)
		{
				Mid=(l+r)>>1;
				if (1ll*Mid*(Mid+1)/2<=p) l=Mid;
				else r=Mid;	
		}
		return l;
}

long long get_Value(long long p)
{
		return 1ll*p*(p-1)+p-1ll*m*(m-1)/2;
}

long long get1(long long p)	
{
		long long l=m+1,r=2e9,Mid=0;
		while ((l+r)>>1!=Mid)
		{
				Mid=(l+r)>>1;
				if (get_Value(Mid)<=p) l=Mid;
				else r=Mid;	
		}
		return l;
}

int main()
{
	scanf("%I64d%I64d",&n,&m);
	long long now=n;
	long long p=get(now),g;
	//first type
	{
			long long sum=0,g=min(p,m);
			now-=1ll*g*(g+1)/2;
			sum+=g;
			sum+=(now/g)+(now%g>0);
			ans=min(ans,sum);
	}
	//second type
	if (m<=(int)2e9)
	{
		if (1ll*m*(m+1)/2+m+m+1<=n)
		{ 
			long long sum=0,g=get1(n);
			n-=get_Value(g); sum+=2*g-m;
			sum+=(n/g)+(n%g>0);
			ans=min(ans,sum);
		} 
	}
	cout<<ans<<endl;
}
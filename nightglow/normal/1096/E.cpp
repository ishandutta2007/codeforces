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

#define Mo 998244353

using namespace std;

int i,j,m,n,p,k,Min,Max,fac[N],inv[N],a,b,ans,wc;

int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
				if (y&1) sum=1ll*sum*x%Mo;
				x=1ll*x*x%Mo; 
		}
		return sum;
}

int C(int x,int y)
{
		if (x<y) return 0;
		return 1ll*fac[x]*inv[x-y]%Mo*inv[y]%Mo; 
}

int W(int x,int y)
{
		if (y==0) return x==0;
		return C(x+y-1,y-1)%Mo;
}

int main()
{
		scanf("%d",&p); scanf("%d%d",&Max,&Min); 
		if (p==1)
		{
				puts("1");
				return 0;
		}
		fac[0]=1; for (i=1;i<N;++i) fac[i]=1ll*fac[i-1]*i%Mo;
		for (i=0;i<N;++i) inv[i]=power(fac[i],Mo-2);
		--p;
		for (i=Min;i<=Max;++i)
		{
				for (a=0;a<=p;++a)
				{
					   int rest=Max-i*(a+1);
					   if (rest<0) continue;
					   int sum=0;
					   for (b=0;a+b<=p;++b)
					   		if (rest-b*i>=0) 
					   {
					   		if  ((b%2)==0) sum=(sum+1ll*C(p,a)*C(p-a,b)%Mo*W(rest-b*i,p-a)%Mo)%Mo;
					   		else sum=(sum-1ll*C(p,a)*C(p-a,b)%Mo*W(rest-b*i,p-a)%Mo+Mo)%Mo;
					   }
					   ans=(ans+1ll*power(a+1,Mo-2)*sum%Mo)%Mo; 
				}
				wc=(wc+W(Max-i,p))%Mo; 
		}
		printf("%d\n",1ll*ans*power(wc,Mo-2)%Mo);
}
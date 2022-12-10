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
 
#define N 3000005
#define M 8000005
 
#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)
 
#define mk make_pair
#define pb push_back
#define fi first
#define se second
 
#define Mo 998244353
#define g 3
 
using namespace std;
 
int i,j,m,n,p,k,NN,rev[N],w[2][N],A[N];
 
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
 
void NTT(int *A,int f)
{
		int i,j,k,l,t;
		for (i=0;i<NN;++i) if (i<rev[i]) swap(A[i],A[rev[i]]); 
		for (i=1;i<NN;i<<=1)	
			for (j=0,t=NN/(i<<1);j<NN;j+=(i<<1))
				for (k=0,l=0;k<i;++k,l+=t)
				{
						int x=A[j+k],y=1ll*A[j+k+i]*w[f][l]%Mo;
						A[j+k]=(x+y)%Mo; A[j+k+i]=(x-y+Mo)%Mo;
				}
		if (f)
		{
				int invn=power(NN,Mo-2);
				for (i=0;i<NN;++i) A[i]=1ll*A[i]*invn%Mo; 
		}
}
 
int main()
{
		scanf("%d",&n); scanf("%d",&k);
		for (;k--;)
		{
				int x;
				scanf("%d",&x);
				A[x]=1; 
		}
		for (NN=1;NN<(n/2)*10;NN<<=1);  
		w[0][0]=1; w[0][1]=power(g,(Mo-1)/NN);
		for (i=2;i<NN;++i) w[0][i]=1ll*w[0][i-1]*w[0][1]%Mo;
		for (i=0;i<NN;++i) w[1][i]=power(w[0][i],Mo-2);
		for (i=0;i<NN;++i) 
 		{
 				for (j=1,k=i;j<NN;j<<=1,k>>=1) (rev[i]<<=1)|=(k&1);
 		}
		NTT(A,0);
		for (i=0;i<NN;++i) A[i]=power(A[i],n/2);
		NTT(A,1);
		int ans=0;
		for (i=0;i<NN;++i) ans=(ans+1ll*A[i]*A[i]%Mo)%Mo;
		printf("%d\n",ans);
}
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

int i,j,m,n,p,k,A[N];

int Work(int x)
{
		x++;
		while (x%10==0) x/=10;
		return x;
}

int main()
{
		scanf("%d",&n);
		for (i=1;i<=1000;++i)
			A[++A[0]]=n,n=Work(n);
		sort(A+1,A+A[0]+1);
		A[0]=unique(A+1,A+A[0]+1)-(A+1);
		printf("%d\n",A[0]); 
}
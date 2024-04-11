#include <bits/stdc++.h>

using namespace std;

long long n,fw[3][400069],fi;

inline void ud(long long xx,long long x,long long w)
{
	for(fi=x;fi<=n*2+1;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

inline long long qr(long long xx,long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[xx][fi];
	}
	return z;
}

int main()
{
	long long t,rr,i,j,sm,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<3;i++)
		{
			for(j=-n;j<=n;j++)
			{
				fw[i][n+1+j]=0;
			}
		}
		z=0;
		sm=0;
		ud(n%3,n/3+1,1);
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			sm+=(ch=='-')*2-1;
			z+=qr((n+sm)%3,(n+sm)/3+1);
			ud((n+sm)%3,(n+sm)/3+1,1);
		}
		printf("%lld\n",z);
	}
}
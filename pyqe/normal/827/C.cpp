#include <bits/stdc++.h>

using namespace std;

const long long mmm=26,mm=4,ma=10;
const string ks="ATGC";
long long n,yk[mmm],a[100069],fw[ma+1][ma][mm][100069],fi;

inline void ud(long long y,long long y2,long long y3,long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[y][y2][y3][fi]+=w;
	}
}

inline long long qr(long long y,long long y2,long long y3,long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[y][y2][y3][fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[y][y2][y3][fi];
	}
	return z;
}

int main()
{
	long long t,rr,i,j,ky,k,l,w,ln,z;
	char ch;
	string s;
	
	for(i=0;i<mm;i++)
	{
		yk[ks[i]-'A']=i;
	}
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=yk[s[i-1]-'A'];
		for(j=1;j<=ma;j++)
		{
			ud(j,i%j,a[i],i,1);
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld %lld",&ky,&k);
		if(ky==1)
		{
			scanf(" %c",&ch);
			l=yk[ch-'A'];
			for(i=1;i<=ma;i++)
			{
				ud(i,k%i,a[k],k,-1);
				ud(i,k%i,l,k,1);
			}
			a[k]=l;
		}
		else
		{
			scanf("%lld",&l);
			cin>>s;
			z=0;
			ln=s.length();
			for(i=0;i<ln;i++)
			{
				w=yk[s[i]-'A'];
				z+=qr(ln,(k+i)%ln,w,k,l);
			}
			printf("%lld\n",z);
		}
	}
}
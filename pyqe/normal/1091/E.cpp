#include <bits/stdc++.h>

using namespace std;

const int d=19;
int n,aa[500069],a[500069],fw[500069],fi;

inline void ud(int x,int w)
{
	for(fi=x;fi<=n+1;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

inline int qr(int x)
{
	int z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

inline int bl(int x)
{
	int i,sm=0;
	
	fi=0;
	for(i=d-1;i+1;i--)
	{
		if((fi|1<<i)<=n+1&&sm+fw[fi|1<<i]>=x)
		{
			fi|=1<<i;
			sm+=fw[fi];
		}
	}
	return fi;
}

inline int val(int x)
{
	int i,j,k,w,lb,rb,z=0;
	
	for(i=1;i<=n+1;i++)
	{
		a[i]=aa[i];
		fw[i]=0;
	}
	for(i=1;i<=n+1;i++)
	{
		if(x>=a[i])
		{
			for(j=n+1;j>i;j--)
			{
				a[j]=a[j-1];
			}
			a[i]=x;
			break;
		}
	}
	for(i=1;i<=n+1;i++)
	{
		ud(i,a[i]-a[i-1]);
	}
	for(i=1;i<=n+1;i++)
	{
		k=qr(i);
		w=min(k,max(bl(1),i)-i);
		z+=k-w;
		k=qr(i+w);
		lb=max(bl(k+1),i);
		rb=bl(k);
		ud(i+1,-1);
		ud(lb+1,1);
		ud(rb-(i+w-lb)+1,-1);
		ud(rb+1,1);
	}
	return z;
}

int main()
{
	int i,z,z2;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",aa+i);
	}
	sort(aa+1,aa+n+1,greater<int>());
	z=val(0);
	if(val(z))
	{
		printf("-1\n");
		return 0;
	}
	z2=n-val(n);
	for(i=z;i<=z2;i+=2)
	{
		printf("%d%c",i," \n"[i==z2]);
	}
}
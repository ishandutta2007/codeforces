#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 200005

using namespace std;


int i,j,m,n,p,k,a[N],Bit[N],Next[N][31];

long long s[N];

int Work()
{
		int i,ans=0;
		for (i=1;i<=n;++i)
		{
				int bit=0,k=a[i];
				while (k) bit++,k>>=1;
				Bit[i]=bit;
				s[i]=s[i-1]+a[i];
		}
		for (i=0;i<=30;++i) Next[n+1][i]=n+1;
		for (i=n;i>=1;--i)
		{
				for (j=0;j<=30;++j) Next[i][j]=Next[i+1][j];
				for (j=0;j<=Bit[i];++j) Next[i][j]=i;
		}
		for (i=1;i<=n-2;++i) 
		{
			int nextid=i+1;
			for (j=Bit[i];j<=30&&nextid!=n+1;++j)
				for (k=0;k<2;++k)
				{
						int id=Next[nextid+1][j];
						if (id==n+1)
						{
							nextid=n+1;
							break;
						}
						if (a[id]>a[i]&&(s[id-1]-s[i])==(a[id]^a[i])) ++ans;
						nextid=id;
				}
		}
	return ans;
}

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) scanf("%d",&a[i]);
		int ans=Work();
		for (i=1;i<=n/2;++i) swap(a[i],a[n-i+1]);
		ans+=Work();
		printf("%d\n",ans); 
}
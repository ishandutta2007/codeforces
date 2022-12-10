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

int i,j,m,n,p,k,a[N],b[N],ans;

int cal()
{
		sort(a+1,a+n/2+1);
		sort(b+1,b+n/2+1);
		int s=0,i;
		for (i=1;i<=n/2;++i) s+=abs(a[i]-b[i]);
		return s;
}

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n/2;++i) scanf("%d",&a[i]);
		for (i=1;i<=n;i+=2) b[++b[0]]=i;
		ans=cal();
		b[0]=0;
		for (i=2;i<=n;i+=2) b[++b[0]]=i;
		ans=min(ans,cal());
		printf("%d\n",ans); 
}
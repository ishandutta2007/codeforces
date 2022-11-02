#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=100010;
int a[N<<1],b[N<<1],sa[N<<1],sb[N<<1],n;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)scanf("%d",&b[i]);
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		rep(i,n)a[i+n]=100,b[i+n]=0;
		rep(i,(n<<1))sa[i]=sa[i-1]+a[i],sb[i]=sb[i-1]+b[i];
		int l=n-1,r=(n<<1)+1;
		for(;l<r-1;)
		{
			int mid=(l+r)>>1;
			if(sa[mid]-sa[mid/4]>=sb[mid]-sb[max(0,mid/4-(mid-n))])r=mid;else l=mid;
		}
		printf("%d\n",r-n);
	}
    return 0;
}
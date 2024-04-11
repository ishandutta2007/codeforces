#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int n,a[300010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		int mx=0;
		rep(i,n)scanf("%d",&a[i]),mx=max(mx,a[i]);
		int ans=-1;
		rep(i,n)if(a[i]==mx&&(i>1&&a[i-1]!=mx||i<n&&a[i+1]!=mx)){ans=i;break;}
		printf("%d\n",ans);
	}
    return 0;
}
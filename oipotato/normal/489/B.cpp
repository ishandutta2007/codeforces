#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,a[110],b[110];
int main()
{
	scanf("%d",&n);
	rep(i,n){int x;scanf("%d",&x);a[x]++;}
	scanf("%d",&m);
	rep(i,m){int x;scanf("%d",&x);b[x]++;}
	int ans=0;
	rep(i,100)
	for(int d=-1;d<=1;d++)
	{
		int tmp=min(a[i],b[i+d]);
		a[i]-=tmp;b[i+d]-=tmp;
		ans+=tmp;
	}
	printf("%d\n",ans);
    return 0;
}
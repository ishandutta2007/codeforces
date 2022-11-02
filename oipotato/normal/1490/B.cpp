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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		int c[3]={0,0,0};
		rep(i,n){int x;scanf("%d",&x);c[x%3]++;}
		int ans=0;
		rep(i,2)for(int j=0;j<3;j++)if(c[j]>n/3)c[(j+1)%3]+=c[j]-n/3,ans+=c[j]-n/3,c[j]=n/3;
		printf("%d\n",ans);
	}
    return 0;
}
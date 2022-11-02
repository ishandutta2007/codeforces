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
int pos[200010],n,c[200010];
int main()
{
	scanf("%d",&n);
	rep(i,n){int x;scanf("%d",&x);pos[x]=i;}
	rep(i,n){int x;scanf("%d",&x);c[(pos[x]-i+n)%n]++;}
	int ans=0;
	rep(i,n)ans=max(ans,c[i-1]);
	printf("%d\n",ans);
    return 0;
}
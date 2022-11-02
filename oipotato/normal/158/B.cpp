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
int cnt[10],n;
int main()
{
	int n;scanf("%d",&n);
	rep(i,n){int x;scanf("%d",&x);cnt[x]++;}
	int ans=cnt[4];
	int tmp=min(cnt[3],cnt[1]);
	ans+=tmp;
	cnt[3]-=tmp;cnt[1]-=tmp;
	ans+=cnt[3];
	ans+=cnt[2]/2;
	cnt[1]+=(cnt[2]&1)*2;
	if(cnt[1])ans+=(cnt[1]-1)/4+1;
	printf("%d\n",ans);
    return 0;
}
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
int cnt[110],ans[110],n;
int main()
{
	scanf("%d",&n);
	rep(i,n){int x;scanf("%d",&x);rep(j,x)cnt[j]++;}
	rep(i,100)rep(j,cnt[i])ans[n-j+1]=i;
	rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}
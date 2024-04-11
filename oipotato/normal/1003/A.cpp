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
int n,cnt[110];
int main()
{
	scanf("%d",&n);
	rep(i,n){int x;scanf("%d",&x);cnt[x]++;}
	int mx=0;
	rep(i,100)mx=max(mx,cnt[i]);
	printf("%d\n",mx);
    return 0;
}
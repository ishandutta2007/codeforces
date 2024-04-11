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
int n,k,s[200010];
int main()
{
	scanf("%d%d",&n,&k);
	rep(i,n){int x;scanf("%d",&x);s[i]=s[i-1]+x;}
	int ans=s[k],ansp=1;
	rep(i,n-k+1)if(s[i+k-1]-s[i-1]<ans)ans=s[i+k-1]-s[i-1],ansp=i;
	printf("%d\n",ansp);
    return 0;
}
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
LL s[500010];
int main()
{
	int n;scanf("%d",&n);
	rep(i,n)scanf("%lld",&s[i]),s[i]+=s[i-1];
	if(s[n]%3){puts("0");return 0;}
	int now=0;
	LL ans=0;
	for(int i=n-1;i;i--)
	{
		if(s[i]==s[n]/3)ans+=now;
		if(s[i]==s[n]/3*2)now++;
	}
	printf("%lld\n",ans);
    return 0;
}
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
char s[1010],t[1010];
int ans,n;
int main()
{
	scanf("%d%s%s",&n,s+1,t+1);
	rep(i,n)
	{
		int x=(t[i]-'0'-(s[i]-'0')+10)%10;
		ans+=min(x,10-x);
	}
	printf("%d\n",ans);
    return 0;
}
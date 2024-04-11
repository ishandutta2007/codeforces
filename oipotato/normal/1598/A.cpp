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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;char s[2][110];
		scanf("%d%s%s",&n,s[0]+1,s[1]+1);
		bool flag=1;
		rep(i,n)if(s[0][i]=='1'&&s[1][i]=='1')flag=0;
		puts(flag?"YES":"NO");
	}
    return 0;
}
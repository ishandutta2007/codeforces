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
bool check(char* s)
{
	int n=strlen(s+1);
	if(n&1)return 0;
	rep(i,n/2)if(s[i]!=s[i+n/2])return 0;
	return 1;
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		char s[110];
		scanf("%s",s+1);
		puts(check(s)?"YES":"NO");
	}
    return 0;
}
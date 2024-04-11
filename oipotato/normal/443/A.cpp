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
int cnt[1010];
char s[1010];
int main()
{
	fgets(s,2000,stdin);
	int n=strlen(s+1);
	rep(i,n)cnt[s[i]]++;
	int ans=0;
	for(int i='a';i<='z';i++)if(cnt[i])ans++;
	printf("%d\n",ans);
    return 0;
}
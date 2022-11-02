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
	int k;char s[1010];
	scanf("%d%s",&k,s+1);
	int n=strlen(s+1);
	int cnt[26];
	rep(i,26)cnt[i-1]=0;
	rep(i,n)cnt[s[i]-'a']++;
	rep(i,26)if(cnt[i-1]%k){puts("-1");return 0;}
	rep(i,k)rep(j,26)rep(t,cnt[j-1]/k)putchar(j-1+'a');
	puts("");
    return 0;
}
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
char s[110];
int n,cnt[30];
int main()
{
	scanf("%d%s",&n,s+1);
	rep(i,n)
	{
		char c=s[i];
		if('A'<=c&&c<='Z')c=c-'A'+'a';
		cnt[c-'a']++;
	}
	for(int i=0;i<26;i++)if(!cnt[i]){puts("NO");return 0;}
	puts("YES");
    return 0;
}
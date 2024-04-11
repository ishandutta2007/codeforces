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
int cnt[30];
int main()
{
	rep(i,3)
	{
		int x;
		if(i<=2)x=1;else x=-1;
		scanf("%s",s+1);
		int n=strlen(s+1);
		rep(j,n)cnt[s[j]-'A']+=x;
	}
	rep(i,26)if(cnt[i-1]){puts("NO");return 0;}
	puts("YES");
    return 0;
}
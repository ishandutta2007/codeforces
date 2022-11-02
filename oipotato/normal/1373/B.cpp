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
char s[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%s",s+1);int n=strlen(s+1);
		int f[2]={0,0};
		rep(i,n)f[s[i]-'0']++;
		int x=min(f[0],f[1]);
		puts((x&1)?"DA":"NET");
	}
    return 0;
}
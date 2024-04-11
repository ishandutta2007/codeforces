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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%s",s+1);
		n=strlen(s+1);
		putchar(s[1]);
		for(int i=2;i<=n;i+=2)putchar(s[i]);
		puts("");
	}
    return 0;
}
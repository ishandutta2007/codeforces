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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;char s[110];
		scanf("%s",s+1);n=strlen(s+1);
		rep(i,n)if(i&1)s[i]=s[i]=='a'?'b':'a';else s[i]=s[i]=='z'?'y':'z';
		puts(s+1);
	}
    return 0;
}
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
char b[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		scanf("%s",b+1);
		int last=3;
		rep(i,n)if(b[i]=='0')putchar(last==1?'0':'1'),last=last==1?0:1;else putchar(last==2?'0':'1'),last=last==2?1:2;
		puts("");
	}
    return 0;
}
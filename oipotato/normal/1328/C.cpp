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
char s[50010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d%s",&n,s+1);
		int pos=n+1;
		rep(i,n)if(s[i]=='1'){pos=i;break;}
		rep(i,n)printf("%d",i<=pos?s[i]!='0':0);puts("");
		rep(i,n)printf("%d",i<=pos?s[i]=='2':s[i]-'0');puts("");
	}
    return 0;
}
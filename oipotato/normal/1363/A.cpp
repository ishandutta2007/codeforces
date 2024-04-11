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
		int n,f[2]={0,0},x;
		scanf("%d%d",&n,&x);
		rep(i,n){int y;scanf("%d",&y);f[y&1]++;}
		if(n==x)puts((f[1]&1)?"Yes":"No");
		else puts(f[1]&&((x&1)||f[0])?"Yes":"No");
	}
    return 0;
}
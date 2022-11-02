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
		int sum=0,f[2]={0,0},n;
		scanf("%d",&n);
		rep(i,n){int x;scanf("%d",&x);f[x&1]++;sum^=x&1;}
		if((sum&1)||(f[0]&&f[1]))puts("YES");else puts("NO");
	}
    return 0;
}
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
int a[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		int f[2]={0,0};
		rep(i,n)scanf("%d",&a[i]),f[a[i]&1]++;
		sort(a+1,a+n+1);
		int flag=0;
		rep(i,n-1)if(a[i]==a[i+1]-1)flag=1;
		puts(flag||(f[0]&1)==0?"YES":"NO");
	}
    return 0;
}
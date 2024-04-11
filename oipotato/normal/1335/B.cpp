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
int a[10];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		rep(i,n)if(i<=a)putchar(min(i,b)-1+'a');else putchar(min((i-1)%a+1,b)-1+'a');puts("");
	}
    return 0;
}
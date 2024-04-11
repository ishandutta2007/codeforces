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
int a[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k;scanf("%d%d",&n,&k);
		int pos1,pos2;
		for(pos1=n-1;k>n-pos1;k-=n-pos1,pos1--);
		pos2=n-k+1;
		rep(i,n)printf("%c","ab"[i==pos1||i==pos2]);puts("");
	}
    return 0;
}
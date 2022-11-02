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
bool ok[1000010];
int main()
{
	ok[2020]=ok[2021]=1;
	for(int i=2022;i<=1000000;i++)ok[i]=ok[i-2020]|ok[i-2021];
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		puts(ok[n]?"YES":"NO");
	}
    return 0;
}
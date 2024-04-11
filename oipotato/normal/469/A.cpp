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
int v[110];
int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);rep(i,m){int x;scanf("%d",&x);v[x]=1;}
	scanf("%d",&m);rep(i,m){int x;scanf("%d",&x);v[x]=1;}
	rep(i,n)if(!v[i]){puts("Oh, my keyboard!");return 0;}
	puts("I become the guy.");
    return 0;
}
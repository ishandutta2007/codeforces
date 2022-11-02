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
int main()
{
	int n,d[200];
	scanf("%d",&n);
	rep(i,n)scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	printf("%d ",d[n]);
	for(int i=n-1;i;i--)if(d[i]==d[i+1]||d[n]%d[i]){printf("%d\n",d[i]);return 0;}
    return 0;
}
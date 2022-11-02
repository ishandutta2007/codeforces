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
int a[110],n;
int main()
{
	scanf("%d",&n);
	if(n>100){puts("YES");return 0;}
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)rep(j,i-1)rep(k,j-1)if(a[i]+a[j]>a[k]&&abs(a[i]-a[j])<a[k]){puts("YES");return 0;}
	puts("NO");
    return 0;
}
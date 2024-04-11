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
		int a[4];rep(i,3)scanf("%d",&a[i]);
		sort(a+1,a+4);
		puts(a[3]==a[1]+a[2]||a[1]==a[2]&&a[3]%2==0||a[2]==a[3]&&a[1]%2==0?"YES":"NO");
	}
    return 0;
}
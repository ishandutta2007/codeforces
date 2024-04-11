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
int n,a[100010];
void check(int l,int r)
{
	reverse(a+l,a+r+1);
	rep(i,n-1)if(a[i]>a[i+1]){reverse(a+l,a+r+1);return;}
	printf("yes\n%d %d\n",l,r);
	exit(0);
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	check(1,1);
	int l=1,r=n;
	for(;a[l]<a[l+1];l++);
	for(;a[r]>a[r-1];r--);
	check(l,r);
	puts("no");
    return 0;
}
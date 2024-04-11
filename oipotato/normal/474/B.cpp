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
int n,m,a[100010];
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)a[i]+=a[i-1];
	scanf("%d",&m);
	rep(i,m){int x;scanf("%d",&x);printf("%d\n",(int)(lower_bound(a+1,a+n+1,x)-a));}
    return 0;
}
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
int n,a[100010],b[100010],c[100010];
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n-1)scanf("%d",&b[i]);
	rep(i,n-2)scanf("%d",&c[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n);
	sort(c+1,c+n-1);
	int ans1=a[n],ans2=b[n-1];
	rep(i,n-1)if(a[i]!=b[i]){ans1=a[i];break;}
	rep(i,n-2)if(b[i]!=c[i]){ans2=b[i];break;}
	printf("%d\n%d\n",ans1,ans2);
    return 0;
}
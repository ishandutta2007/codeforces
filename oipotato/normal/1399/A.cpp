#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int a[55];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);rep(i,n)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		bool flag=1;
		rep(i,n-1)if(a[i]+1<a[i+1]){flag=0;break;}
		puts(flag?"YES":"NO");
	}
	return 0;
}
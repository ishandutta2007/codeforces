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
int a[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		int sum=0;
		rep(i,n)scanf("%d",&a[i]),sum+=a[i];
		sort(a+1,a+n+1);
		if(a[n]>sum-a[n])puts("T");
		else puts((sum&1)?"T":"HL");
	}
	return 0;
}
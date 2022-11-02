#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<bitset>
#include<cmath>
using namespace std;
int n,a[100010];
int main()
{
	scanf("%d",&n);
	int len=(int)floor(sqrt(n));
	for(int i=1,now=n;i<=n;now-=len)
	for(int j=max(1,now-len+1);j<=now&&i<=n;j++,i++)a[i]=j;
	for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}
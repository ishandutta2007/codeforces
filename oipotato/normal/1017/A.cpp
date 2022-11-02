#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<bitset>
using namespace std;
int sum,ans,n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=4;i++){int x;scanf("%d",&x);sum+=x;}
	for(int i=2;i<=n;i++){int x,s=0;for(int j=1;j<=4;j++){scanf("%d",&x);s+=x;}if(s>sum)ans++;}
	printf("%d\n",ans+1);
	return 0;
}
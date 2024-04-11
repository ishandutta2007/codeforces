#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int x;scanf("%d",&x);
		for(int i=3;i<=360;i++)if(x*i%180==0&&x*i/180<=i-2){printf("%d\n",i);break;}
	}
	return 0;
}
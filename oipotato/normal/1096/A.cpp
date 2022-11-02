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
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d %d\n",l,2*l);
	}
	return 0;
}
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
bool check(int r,int g,int b,int w)
{
	if(r<0||g<0||b<0)return 0;
	return (r&1)+(g&1)+(b&1)+(w&1)<=1;
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int r,g,b,w;scanf("%d%d%d%d",&r,&g,&b,&w);
		if(check(r,g,b,w)||check(r-1,g-1,b-1,w+3))puts("Yes");else puts("No");
	}
	return 0;
}
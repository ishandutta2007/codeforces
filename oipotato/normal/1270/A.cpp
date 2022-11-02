#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ctime>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;i++)
#define x1 fuckcjb
#define y1 fucksub
#define x2 fuckjtjl
#define y2 fucksf
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n,k1,k2;
		scanf("%d%d%d",&n,&k1,&k2);
		int pos=0;
		rep(i,k1){int x;scanf("%d",&x);}
		rep(i,k2){int x;scanf("%d",&x);if(x==n)pos=1;}
		puts(pos?"NO":"YES");
	}
	return 0;
}
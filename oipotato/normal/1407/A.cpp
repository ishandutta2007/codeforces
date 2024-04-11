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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		int cnt[2];
		cnt[0]=cnt[1]=0;
		rep(i,n){int x;scanf("%d",&x);cnt[x]++;}
		int x=0;
		if(cnt[0]<cnt[1])x=1;
		int CNT=n/2;if(x&&(CNT&1))CNT++;
		printf("%d\n",CNT);
		rep(i,CNT)printf("%d%c",x," \n"[i==CNT]);
	}
	return 0;
}
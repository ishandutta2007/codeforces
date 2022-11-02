#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k;scanf("%d%d",&n,&k);
		if(k>(n-1)/2){puts("-1");continue;}
		int now=n;
		for(;now&&(now-2)/2>=k;now--);
		rep(i,now)printf("%d%c",(i&1)?(i+1)/2:(now+1)/2+i/2," \n"[i==n]);
		for(int i=now+1;i<=n;i++)printf("%d%c",i," \n"[i==n]);
	}
    return 0;
}
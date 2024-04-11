#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
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
		int x;scanf("%d",&x);
		int a[20],cnt=0,now=9;
		for(;now&&x>=now;x-=now,a[++cnt]=now,now--);
		if(x&&x>=now){puts("-1");continue;}
		if(x)a[++cnt]=x;reverse(a+1,a+cnt+1);
		rep(i,cnt)printf("%d",a[i]);puts("");
	}
    return 0;
}
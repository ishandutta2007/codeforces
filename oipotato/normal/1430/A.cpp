#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define hash hsh
typedef long long LL;
bool ok[1010];
int cnt[10];
int main()
{
	ok[0]=1;
	rep(i,1000)
	{
		ok[i]|=i>=3?ok[i-3]:0;
		ok[i]|=i>=5?ok[i-5]:0;
		ok[i]|=i>=7?ok[i-7]:0;
	}
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		if(!ok[n])puts("-1");
		else
		{
			rep(i,3)cnt[i]=0;
			for(;n;)
			{
				if(n>=3&&ok[n-3])n-=3,cnt[1]++;
				else if(n>=5&&ok[n-5])n-=5,cnt[2]++;
				else if(n>=7&&ok[n-7])n-=7,cnt[3]++;
			}
			rep(i,3)printf("%d%c",cnt[i]," \n"[i==3]);
		}
	}
    return 0;
}
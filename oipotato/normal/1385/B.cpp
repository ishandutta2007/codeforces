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
int p[110],v[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		int cnt=0;
		rep(i,n)v[i]=0;
		rep(i,2*n)
		{
			int x;scanf("%d",&x);
			if(!v[x])p[++cnt]=x;
			v[x]=1;
		}
		rep(i,n)printf("%d%c",p[i]," \n"[i==n]);
	}
    return 0;
}
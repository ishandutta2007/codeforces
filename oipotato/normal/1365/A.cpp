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
		int n,m,r[55],c[55];scanf("%d%d",&n,&m);
		rep(i,n)r[i]=0;rep(i,m)c[i]=0;
		rep(i,n)rep(j,m){int x;scanf("%d",&x);if(x)r[i]=c[j]=1;}
		int x=0,y=0;
		rep(i,n)if(!r[i])x++;rep(i,m)if(!c[i])y++;
		puts((min(x,y)&1)?"Ashish":"Vivek");
	}
    return 0;
}
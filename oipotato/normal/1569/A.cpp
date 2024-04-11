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
		int n;char s[110];scanf("%d%s",&n,s+1);
		int l=-1,r=-1;
		rep(i,n)rep(j,i)
		{
			int a=0,b=0;
			for(int k=j;k<=i;k++)if(s[k]=='a')a++;else b++;
			if(a==b)l=j,r=i;
		}
		printf("%d %d\n",l,r);
	}
    return 0;
}
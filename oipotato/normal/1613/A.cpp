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
bool cmp(int x1,int p1,int x2,int p2)
{
	LL a=x1,b=x2;
	if(abs(p1-p2)>=8)return p1<p2;
	else
	{
		for(;p1>p2;a*=10,p1--);
		for(;p2>p1;b*=10,p2--);
		return a<b;
	}
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int x1,p1,x2,p2;
		scanf("%d%d%d%d",&x1,&p1,&x2,&p2);
		if(cmp(x1,p1,x2,p2))puts("<");
		else if(cmp(x2,p2,x1,p1))puts(">");
		else puts("=");
	}
    return 0;
}
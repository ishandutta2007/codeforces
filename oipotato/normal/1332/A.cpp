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
bool check(int a,int b,int l,int r)
{
	if(!a&&!b)return 1;
	if(!l&&!r)return 0;
	if(a>b)return a-b<=abs(l);
	else return b-a<=abs(r);
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int a,b,c,d,x,y,x1,y1,x2,y2;
		scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&x,&y,&x1,&y1,&x2,&y2);
		puts(check(a,b,x1-x,x2-x)&&check(c,d,y1-y,y2-y)?"YES":"NO");
	}
    return 0;
}
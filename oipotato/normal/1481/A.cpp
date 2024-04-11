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
char s[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int x,y;scanf("%d%d",&x,&y);
		scanf("%s",s+1);
		int n=strlen(s+1);
		rep(i,n)
		{
			int dx=0,dy=0;
			if(s[i]=='U')dy=-1;
			else if(s[i]=='D')dy=1;
			else if(s[i]=='R')dx=-1;
			else dx=1;
			if(abs(x)>abs(x+dx))x+=dx;
			if(abs(y)>abs(y+dy))y+=dy;
		}
		puts(!x&&!y?"YES":"NO");
	}
    return 0;
}
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
		char s[410][410];
		int n;scanf("%d",&n);
		rep(i,n)scanf("%s",s[i]+1);
		int x1=-1,y1,x2=-1,y2;
		rep(i,n)rep(j,n)if(s[i][j]=='*')if(x1==-1)x1=i,y1=j;else x2=i,y2=j;
		if(x1==x2)s[x1==n?n-1:x1+1][y1]=s[x2==n?n-1:x2+1][y2]='*';
		else if(y1==y2)s[x1][y1==n?n-1:y1+1]=s[x2][y2==n?n-1:y2+1]='*';
		else s[x1][y2]=s[x2][y1]='*';
		rep(i,n)puts(s[i]+1);
	}
    return 0;
}
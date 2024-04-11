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
		char s[10][10];
		rep(i,9)scanf("%s",s[i]+1);
		rep(i,3)rep(j,3)s[(i-1)*3+j][(j-1)*3+i]=s[(i-1)*3+j][(j-1)*3+i]=='9'?'1':'9';
		rep(i,9)puts(s[i]+1);
	}
    return 0;
}
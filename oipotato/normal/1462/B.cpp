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
const char* aim="2020";
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		char s[210];int n;scanf("%d%s",&n,s+1);
		int mxl=0,mxr=0;
		for(;mxl<4&&s[mxl+1]==aim[mxl];mxl++);
		for(;mxr<4&&s[n-mxr]==aim[3-mxr];mxr++);
		puts(mxl+mxr>=4?"YES":"NO");
	}
    return 0;
}
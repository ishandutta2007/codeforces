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
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d %d %d\n",max(0,max(b,c)+1-a),max(0,max(a,c)+1-b),max(0,max(a,b)+1-c));
	}
    return 0;
}
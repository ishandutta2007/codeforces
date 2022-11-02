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
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		bool flag=0;
		for(int a=x;a&&!flag;a=a==y?0:y)
		for(int b=x;b&&!flag;b=b==z?0:z)
		for(int c=y;c&&!flag;c=c==z?0:z)
		if(max(a,b)==x&&max(a,c)==y&&max(b,c)==z)
		{
			flag=1;puts("YES");printf("%d %d %d\n",a,b,c);
		}
		if(!flag)puts("NO");
	}
    return 0;
}
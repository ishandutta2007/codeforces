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
int main()
{
	int a,b;scanf("%d%d",&a,&b);
	int re=0,cnt=0;
	for(;a;)
	{
		a--;
		re++;cnt++;
		if(re>=b)re-=b,a++;
	}
	printf("%d\n",cnt);
    return 0;
}
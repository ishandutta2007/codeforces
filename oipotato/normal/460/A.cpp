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
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;;i++)
	{
		n--;
		if(i%m==0)n++;
		if(!n){printf("%d\n",i);return 0;}
	}
    return 0;
}
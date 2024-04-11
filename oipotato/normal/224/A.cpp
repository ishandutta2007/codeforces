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
	int x,y,z;scanf("%d%d%d",&x,&y,&z);
	rep(i,x)if(x%i==0)
	{
		int a=i,b=x/i;
		if(y%a||z%b)continue;
		if(y/a!=z/b)continue;
		int c=y/a;
		printf("%d\n",4*(a+b+c));
		return 0;
	}
    return 0;
}
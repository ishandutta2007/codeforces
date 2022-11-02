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
const int bill[6]={0,100,20,10,5,1};
int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	rep(i,5)
	{
		int x=bill[i];
		ans+=n/x;
		n%=x;
	}
	printf("%d\n",ans);
    return 0;
}
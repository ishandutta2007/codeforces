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
	LL n;scanf("%lld",&n);
	int cnt=0;
	for(;n;n/=10)if(n%10==4||n%10==7)cnt++;
	bool flag=cnt;
	for(;cnt;cnt/=10)if(cnt%10!=4&&cnt%10!=7){flag=0;break;}
	puts(flag?"YES":"NO");
    return 0;
}
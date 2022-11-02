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
	int a=0,b=0,n;
	rep(i,3){int x;scanf("%d",&x);a+=x;}
	rep(i,3){int x;scanf("%d",&x);b+=x;}
	scanf("%d",&n);
	puts((int)ceil(1.*a/5)+(int)ceil(1.*b/10)<=n?"YES":"NO");
    return 0;
}
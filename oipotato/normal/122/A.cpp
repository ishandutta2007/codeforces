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
bool check(int x)
{
	for(;x;x/=10)if(x%10!=4&&x%10!=7)return 0;
	return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,n)if(n%i==0&&check(i)){puts("YES");return 0;}
	puts("NO");
    return 0;
}
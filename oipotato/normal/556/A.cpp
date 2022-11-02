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
char s[200010];
int n;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans=0;
	rep(i,n)ans+=s[i]=='0'?1:-1;
	printf("%d\n",abs(ans));
    return 0;
}
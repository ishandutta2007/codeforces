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
const char* s[2]={"I love ","I hate "};
int main()
{
	int n;scanf("%d",&n);
	rep(i,n-1)printf("%sthat ",s[i&1]);
	printf("%sit\n",s[n&1]);
    return 0;
}
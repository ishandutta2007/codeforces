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
	int n;char t[60];scanf("%d%s",&n,t+1);
	int now=1;
	rep(i,10)
	{
		putchar(t[now]);
		now+=i;
		if(now>n)break;
	}
	puts("");
    return 0;
}
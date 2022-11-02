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
char s[100010];
int n;
int main()
{
	scanf("%d%s",&n,s+1);
	int a=0,b=0;
	rep(i,n)if(s[i]=='n')a++;else if(s[i]=='z')b++;
	rep(i,a+b)printf("%d%c",i<=a," \n"[i==a+b]);
    return 0;
}
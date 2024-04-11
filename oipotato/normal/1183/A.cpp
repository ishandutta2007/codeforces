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
int cal(int x){int res=0;for(;x;res+=x%10,x/=10);return res;}
int main()
{
	int a;scanf("%d",&a);
	for(;cal(a)%4;a++);
	printf("%d\n",a);
    return 0;
}
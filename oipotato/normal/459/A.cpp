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
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==c)printf("%d %d %d %d\n",a+b-d,b,c+b-d,d);
	else if(b==d)printf("%d %d %d %d\n",a,b+a-c,c,d+a-c);
	else if(abs(a-c)==abs(b-d))printf("%d %d %d %d\n",a,d,c,b);
	else puts("-1");
    return 0;
}
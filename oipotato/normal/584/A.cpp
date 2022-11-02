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
	int n,t;
	scanf("%d%d",&n,&t);
	if(n==1)printf("%d\n",t<10?t:-1);
	else if(t==10){rep(i,n-1)printf("1");puts("0");}
	else{rep(i,n)printf("%d",t);puts("");}
    return 0;
}
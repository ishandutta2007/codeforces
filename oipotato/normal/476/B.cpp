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
int C(int n,int m)
{
	int res=1;
	rep(i,m)res*=n-i+1;
	rep(i,m)res/=i;
	return res;
}
int main()
{
	char s[20],t[20];
	scanf("%s%s",s+1,t+1);
	int a=0,b=0,cnt=0,n=strlen(s+1);
	rep(i,n)a+=s[i]=='+'?1:-1;
	rep(i,n)if(t[i]=='?')cnt++;else b+=t[i]=='+'?1:-1;
	int x=(a-b+cnt)/2,y=cnt-x;
	if(x<0||y<0)puts("0");else printf("%.15Lf\n",1.L*C(cnt,x)/(1<<cnt));
    return 0;
}
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
int a[100010],n,m;
char s[100010];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,n-1)a[i]=a[i-1]+(s[i]==s[i+1]);
	scanf("%d",&m);
	rep(i,m)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",a[r-1]-a[l-1]);
	}
    return 0;
}
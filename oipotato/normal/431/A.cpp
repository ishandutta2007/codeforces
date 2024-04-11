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
int a[10];
char s[100010];
int main()
{
	rep(i,4)scanf("%d",&a[i]);
	scanf("%s",s+1);int n=strlen(s+1);
	int ans=0;
	rep(i,n)ans+=a[s[i]-'0'];
	printf("%d\n",ans);
    return 0;
}
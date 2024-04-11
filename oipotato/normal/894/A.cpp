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
	int n;char s[110];
	scanf("%s",s+1);n=strlen(s+1);
	int ans=0;
	rep(i,n)rep(j,i-1)rep(k,j-1)if(s[k]=='Q'&&s[j]=='A'&&s[i]=='Q')ans++;
	printf("%d\n",ans);
    return 0;
}
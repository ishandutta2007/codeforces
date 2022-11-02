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
char s[100010];
int n,q;
bool abc(int x)
{
	if(s[x]=='a')return x+2<=n&&s[x+1]=='b'&&s[x+2]=='c';
	else if(s[x]=='b')return x>1&&x<n&&s[x-1]=='a'&&s[x+1]=='c';
	else return x>2&&s[x-2]=='a'&&s[x-1]=='b';
}
int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	int ans=0;
	rep(i,n)ans+=abc(i);
	ans/=3;
	rep(i,q)
	{
		int x;char c[5];
		scanf("%d%s",&x,c);
		if(abc(x))ans--;
		s[x]=c[0];
		if(abc(x))ans++;
		printf("%d\n",ans);
	}
    return 0;
}
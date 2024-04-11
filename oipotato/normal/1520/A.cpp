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
char s[110];
int n,cnt[30];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%s",&n,s+1);
		rep(i,26)cnt[i]=0;
		bool flag=1;
		for(int i=1;i<=n;)
		{
			int j=i+1;
			for(;j<=n&&s[j]==s[i];j++);
			if(cnt[s[i]-'A'+1]){flag=0;break;}
			cnt[s[i]-'A'+1]=1;
			i=j;
		}
		puts(flag?"YES":"NO");
	}
    return 0;
}
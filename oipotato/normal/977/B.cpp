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
int n,cnt[30][30];
char s[110];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,n-1)cnt[s[i]-'A'+1][s[i+1]-'A'+1]++;
	int mx=0;
	rep(i,26)rep(j,26)mx=max(mx,cnt[i][j]);
	rep(i,26)rep(j,26)if(cnt[i][j]==mx){printf("%c%c\n",i+'A'-1,j+'A'-1);return 0;}
    return 0;
}
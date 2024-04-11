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
char s[100010];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,n-1)if(s[i]=='A'&&s[i+1]=='B')
	for(int j=i+2;j<n;j++)if(s[j]=='B'&&s[j+1]=='A')
	{
		puts("YES");
		return 0;
	}
	rep(i,n-1)if(s[i]=='B'&&s[i+1]=='A')
	for(int j=i+2;j<n;j++)if(s[j]=='A'&&s[j+1]=='B')
	{
		puts("YES");
		return 0;
	}
	puts("NO");
    return 0;
}
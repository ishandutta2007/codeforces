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
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,n)if((s[i]-'0')%2==0&&s[i]-'0'<s[n]-'0')
	{
		swap(s[i],s[n]);
		puts(s+1);
		return 0;
	}
	for(int i=n-1;i;i--)if((s[i]-'0')%2==0)
	{
		swap(s[i],s[n]);
		puts(s+1);
		return 0;
	}
	puts("-1");
    return 0;
}
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
int main()
{
	char s[210];
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,n)
	if(s[i]=='.')putchar('0');
	else putchar("12"[s[++i]=='-']);
    return 0;
}
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
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	bool flag=1;
	for(int i=2;i<=n;i++)if('a'<=s[i]&&s[i]<='z'){flag=0;break;}
	if(flag)
	{
		if('a'<=s[1]&&s[1]<='z')s[1]=s[1]-'a'+'A';else s[1]=s[1]-'A'+'a';
		for(int i=2;i<=n;i++)s[i]=s[i]-'A'+'a';
	}
	puts(s+1);
    return 0;
}
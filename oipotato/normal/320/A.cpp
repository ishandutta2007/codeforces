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
char s[110];
int main()
{
	scanf("%s",s+1);
	if(s[1]!='1'){puts("NO");return 0;}
	int n=strlen(s+1);
	rep(i,n)if(s[i]!='1')
	{
		if(s[i]!='4'){puts("NO");return 0;}
		int j=i;for(;j<=n&&s[j]=='4';j++);
		if(j-i>2){puts("NO");return 0;}
		i=j-1;
	}
	puts("YES");
    return 0;
}
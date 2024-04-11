#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
char s[310];
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		if(n==2&&s[1]>=s[2])puts("NO");
		else
		{
			puts("YES");
			puts("2");
			printf("%c ",s[1]);
			puts(s+2);
		}
	}
	return 0;
}
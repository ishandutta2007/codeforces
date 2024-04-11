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
char s[1010][10];
int n;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%s",s[i]+1);
	rep(i,n)
	{
		bool flag=0;
		if(s[i][1]=='O'&&s[i][2]=='O')s[i][1]=s[i][2]='+',flag=1;
		else if(s[i][4]=='O'&&s[i][5]=='O')s[i][4]=s[i][5]='+',flag=1;
		if(flag){puts("YES");rep(i,n)puts(s[i]+1);return 0;}
	}
	puts("NO");
    return 0;
}
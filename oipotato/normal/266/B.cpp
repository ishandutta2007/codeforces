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
int n,t;
int main()
{
	scanf("%d%d",&n,&t);
	scanf("%s",s+1);
	rep(i,t)
	{
		rep(i,n-1)if(s[i]=='B'&&s[i+1]=='G')swap(s[i],s[i+1]),i++;
	}
	puts(s+1);
    return 0;
}
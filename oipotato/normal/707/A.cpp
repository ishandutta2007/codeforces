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
	int n,m;char s[5];
	scanf("%d%d",&n,&m);
	rep(i,n)rep(j,m)
	{
		scanf("%s",s);
		if(s[0]=='C'||s[0]=='M'||s[0]=='Y'){puts("#Color");return 0;}
	}
	puts("#Black&White");
    return 0;
}
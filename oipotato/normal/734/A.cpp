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
int n;
char s[100010];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int cnt=0;
	rep(i,n)if(s[i]=='A')cnt++;else cnt--;
	if(cnt>0)puts("Anton");
	else if(cnt<0)puts("Danik");
	else puts("Friendship");
    return 0;
}
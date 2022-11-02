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
	int n;
	scanf("%d",&n);
	int ans=1,last=-1;
	rep(i,n)
	{
		char s[5];scanf("%s",s);
		int x=s[0]-'0';
		ans+=x==last;
		last=x^1;
	}
	printf("%d\n",ans);
    return 0;
}
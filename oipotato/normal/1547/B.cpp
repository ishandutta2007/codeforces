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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;char s[30];scanf("%s",s+1);
		n=strlen(s+1);
		int l=-1,r=-1;
		rep(i,n)if(s[i]=='a'){l=r=i;break;}
		if(l==-1){puts("NO");continue;}
		rep(i,n-1)if(l>1&&s[l-1]==i+'a')l--;else if(r<n&&s[r+1]==i+'a')r++;else break;
		puts(l==1&&r==n?"YES":"NO");
	}
    return 0;
}
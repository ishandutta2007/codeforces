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
char s[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		LL x;scanf("%lld",&x);
		bool flag=0;
		rep(i,10000)
		{
			LL y=x-(LL)i*i*i;
			if(y<=0)break;
			int b=(int)pow(y,1/3.);
			if((LL)i*i*i+(LL)b*b*b==x){flag=1;break;}
			b++;
			if((LL)i*i*i+(LL)b*b*b==x){flag=1;break;}
		}
		puts(flag?"YES":"NO");
	}
    return 0;
}
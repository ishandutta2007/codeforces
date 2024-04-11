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
typedef unsigned long long ULL;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		printf("2\n");
		set<int>s;s.clear();
		rep(i,n)s.insert(i);
		int last;
		rep(i,n)
		{
			int ans;
			if(i==1)ans=1;
			else if(last*2<=n)ans=last*2;
			else ans=*s.begin();
			s.erase(ans);
			printf("%d%c",ans," \n"[i==n]);
			last=ans;
		}
	}
    return 0;
}
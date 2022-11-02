#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
pair<int,int>a[100010];
int n;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i].first),a[i].second=i;
		sort(a+1,a+n+1);
		bool flag=1;
		for(int i=1;i<=n;)
		{
			int j=i,num[2]={0,0};
			for(;j<=n&&a[j].first==a[i].first;j++)num[a[j].second%2==i%2]++;
			if((j-i+1)/2!=num[1]||(j-i)/2!=num[0]){flag=0;break;}
			i=j;
		}
		puts(flag?"YES":"NO");
	}
    return 0;
}
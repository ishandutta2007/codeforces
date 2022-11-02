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
pair<int,int>a[5010];
int n;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	int last=0;
	rep(i,n)
	{
		int j=i;
		for(;j<=n&&a[j].first==a[i].first;j++);
		j--;
		last=a[i].second>=last?a[j].second:a[i].first;
		i=j;
	}
	printf("%d\n",last);
    return 0;
}
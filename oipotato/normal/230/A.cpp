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
int s,n;
pair<int,int>a[1010];
int main()
{
	scanf("%d%d",&s,&n);
	rep(i,n)scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	rep(i,n)
	{
		if(s<=a[i].first){puts("NO");return 0;}
		s+=a[i].second;
	}
	puts("YES");
    return 0;
}
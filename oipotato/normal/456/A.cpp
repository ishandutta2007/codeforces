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
pair<int,int>a[100010];
int n;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	rep(i,n-1)if(a[i].first<a[i+1].first&&a[i].second>a[i+1].second){puts("Happy Alex");return 0;}
	puts("Poor Alex");
    return 0;
}
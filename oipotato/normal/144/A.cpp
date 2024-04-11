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
int n,a[110];
int main()
{
	scanf("%d",&n);
	int mx=0,mn=100;
	rep(i,n)scanf("%d",&a[i]),mx=max(mx,a[i]),mn=min(mn,a[i]);
	int pos1,pos2;
	rep(i,n)if(a[i]==mx){pos1=i;break;}
	for(int i=n;i;i--)if(a[i]==mn){pos2=i;break;}
	printf("%d\n",pos1-1+(n-pos2)-(pos2<pos1));
    return 0;
}
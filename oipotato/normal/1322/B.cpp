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
const int N=400010;
int a[N],tmp[N],n;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	int ans=0;
	for(int i=0;i<25;i++)
	{
		int cnt=0,full=(1<<(i+1))-1;
		rep(j,n)if(!((a[j]>>i)&1))tmp[++cnt]=a[j];
		rep(j,n)if((a[j]>>i)&1)tmp[++cnt]=a[j];
		rep(j,n)a[j]=tmp[j];
		int p1=n,p2=n,p3=n,tans=0;
		rep(j,n-1)
		{
			p1=max(p1,j+1);p2=max(p2,j+1);p3=max(p3,j+1);
			for(;p1>j&&(a[p1]&full)+(a[j]&full)>=(1<<i);p1--);
			for(;p2>j&&(a[p2]&full)+(a[j]&full)>=(1<<(i+1));p2--);
			for(;p3>j&&(a[p3]&full)+(a[j]&full)>=(1<<(i+1))+(1<<i);p3--);
			tans^=(n^p3^p2^p1)&1;
		}
		ans^=tans<<i;
	}
	printf("%d\n",ans);
    return 0;
}
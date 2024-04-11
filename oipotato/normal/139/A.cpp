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
	int T;
	for(T=1;T--;)
	{
		int n,a[8];scanf("%d",&n);
		int sum=0;
		rep(i,7)scanf("%d",&a[i]),sum+=a[i];
		n%=sum;
		if(!n){for(int i=7;i;i--)if(a[i]){printf("%d\n",i);break;}continue;}
		rep(i,7)if(n<=a[i]){printf("%d\n",i);break;}else n-=a[i];
	}
    return 0;
}
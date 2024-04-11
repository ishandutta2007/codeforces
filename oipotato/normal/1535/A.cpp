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
int a[10];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		rep(i,4)scanf("%d",&a[i]);
		int A=max(a[1],a[2]),B=max(a[3],a[4]);
		if(A<B)swap(A,B);
		sort(a+1,a+5);
		puts(A==a[4]&&B==a[3]?"YES":"NO");
	}
    return 0;
}
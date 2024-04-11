#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
signed main(){
	int a[4];
	cin>>a[1]>>a[2]>>a[3];
	puts("First");
	int ma=max(max(a[1],a[2]),a[3]);
	printf("%d\n",ma);fflush(stdout);
	int x;
	scanf("%lld",&x);
	a[x]+=ma;
	int p=3*a[x]-a[1]-a[2]-a[3];
	printf("%lld\n",p);fflush(stdout);
	int y;
	scanf("%lld",&y);
	a[y]+=p;
	printf("%lld\n",a[y]-a[x]);
	fflush(stdout);
	int g;
	scanf("%lld",&g);
	RE 0;
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3e5 + 5;
int a[MAXN],n;

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	int ans = 0;
	FOR(i,1,n) if(a[1] != a[i]) ans = std::max(ans,i-1);
	FOR(i,1,n) if(a[i] != a[n]) ans = std::max(ans,n-i);
	printf("%d\n",ans);
	return 0;
}
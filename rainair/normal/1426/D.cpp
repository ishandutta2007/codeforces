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

const int MAXN = 2e5 + 5;
LL a[MAXN];
int n;
std::map<LL,int> lst;
int pre[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld",a+i),a[i] += a[i-1];
	FOR(i,0,n){
		if(lst.count(a[i]) == 0) pre[i] = -1;
		else pre[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	int now = 0,ans = 0;
	FOR(i,1,n){
		if(pre[i] >= now) ans++,now=i-1;
	}
	printf("%d\n",ans);
	return 0;
}
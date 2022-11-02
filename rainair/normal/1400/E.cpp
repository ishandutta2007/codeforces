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

const int MAXN = 5000+5;
int a[MAXN],n;

inline int work(int l,int r){
	if(l > r) return 0;
	if(l == r) return (a[l] != 0);
	int mn = 1e9,cnt = 0;
	FOR(i,l,r) mn = std::min(mn,a[i]),cnt += (a[i] != 0);
	if(mn >= cnt) return cnt;
	int ps = 0;
	FOR(i,l,r) if(a[i] == mn) ps = i;
	FOR(i,l,r) a[i] -= mn;
	int p1 = work(l,ps-1),p2 = work(ps+1,r);
	return std::min(p1+p2+mn,cnt);
}

int main(){
	scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i);
	printf("%d\n",work(1,n));
	return 0;
}
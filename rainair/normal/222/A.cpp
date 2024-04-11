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

const int MAXN = 1e5 + 5;
int n,k,a[MAXN];
int cnt[MAXN],now;

inline void add(int x){
	cnt[x]++;if(cnt[x] == 1) now++;
}

inline void del(int x){
	cnt[x]--;if(cnt[x] == 0) now--;
}

int main(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n) scanf("%d",a+i);
	bool flag = 1;
	FOR(i,k+1,n) flag &= (a[i] == a[i-1]);
	if(!flag){
		puts("-1");
		return 0;
	}
	ROF(i,k-1,0){
		if(a[i] != a[k]){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
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

const int MAXN = 5e5 + 5;

struct BIT{
	LL tree[MAXN];
	#define lowbit(x) ((x)&(-(x)))
	
	inline void add(int pos,LL x){
		pos++;
		while(pos < MAXN){
			tree[pos] += x;
			pos += lowbit(pos);
		}
	}
	
	inline LL query(int pos){
		LL res = 0;pos++;
		while(pos){
			res += tree[pos];
			pos -= lowbit(pos);
		}
		return res;
	}
}bit;

int n,m;
int a[MAXN],w[MAXN],b[MAXN];

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,n) scanf("%d",w+i);
	scanf("%d",&m);
	FOR(i,1,m) scanf("%d",b+i);
	bit.add(1,1e18);
	FOR(i,1,n){
		int p = std::lower_bound(b+1,b+m+1,a[i])-b;
		LL v = -1;
		if(b[p] == a[i]){
			v = bit.query(p-1);
		}
		// [p,m]
		bit.add(0,w[i]);
		if(w[i] > 0) bit.add(p,-w[i]);
		if(b[p] == a[i]){
			LL now = bit.query(p);
			if(now > v){
				bit.add(p,-now+v);
				bit.add(p+1,now-v);
			}
		}
	}
	LL res = bit.query(m);
	if(res > 1e17){
		puts("NO");
	}
	else{
		printf("YES\n%lld\n",res);
	}
	return 0;
}
/*
f[i][j]: ai,bj
f[i][j] -> f[i+1][j]+p[i+1]
f[i][j] -> f[i+1][j] (a[i+1] <= b[j+1]) b  
f[i][j] -> f[i+1][j+1] (a[i+1] == b[j+1]) !! 
 
*/
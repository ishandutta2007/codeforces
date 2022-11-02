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

const int ha = 1e9 + 9;
const int MAXN = 1e5 + 5;
int x[MAXN],y[MAXN];
int n;
std::map<P,int> S;

inline bool chk(int p){
	int x = ::x[p],y = ::y[p];
	bool f1 = S.count(MP(x-1,y+1)),f2 = S.count(MP(x,y+1)),f3 = S.count(MP(x+1,y+1));
	bool f4 = S.count(MP(x-2,y)),f5 = S.count(MP(x-1,y)),f7 = S.count(MP(x+1,y)),f8 = S.count(MP(x+2,y));
	if(f1 && !f4 && !f5) return 0;
	if(f2 && !f5 && !f7) return 0;
	if(f3 && !f7 && !f8) return 0;
	return 1;
}

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int main(){
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d%d",x+i,y+i),S[MP(x[i],y[i])] = i;
	std::set<int> q;
	FOR(i,1,n) if(chk(i)) q.insert(i);
	int ans = 0;
	FOR(i,1,n){
		// assert(!q.empty());
		int v = 0;
		if(i&1) v = *q.rbegin(),q.erase((--q.end()));
		else v = *q.begin(),q.erase(q.begin());
		(ans += 1ll*qpow(n,n-i)*(v-1)%ha) %= ha;
		// ans = 1ll*ans*n%ha;
		// (ans += (v-1)) %= ha;
		// DEBUG(qpow(n,n-i));DEBUG(v-1);
		// DEBUG(ans);
		S.erase(MP(x[v],y[v]));
		FOR(dx,-2,2){
			FOR(dy,-2,2){
				if(dx == 0 && dy == 0) continue;
				int xx = x[v]+dx,yy = y[v]+dy;
				if(S.count(MP(xx,yy))){
					int id = S[MP(xx,yy)];
					if(q.count(id) && !chk(id)) q.erase(id);
					else if(chk(id) && !q.count(id)) q.insert(id);
					// if(chk(S[MP(xx,yy)]))
				}
			}
		}
		// DEBUG(chk(4));
		// DEBUG(q.size());
		// exit(0);
	}
	printf("%d\n",ans);
	return 0;
}
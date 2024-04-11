#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define pf emplace_front
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
int n;LL C;
LL w[MAXN];
int k;LL b;

struct Node{
	LL l,r;
	Node(LL l=0,LL r=0) : l(l),r(r) {}
};

std::deque<Node> q;
LL now;

inline LL get(LL x){
	return x*k+b;
}

inline int chk(Node v){
	if(get(v.l) >= 0 && get(v.l) <= now && get(v.r) >= 0 && get(v.r) <= now) return 0;
	if((get(v.l) < 0 && get(v.r) < 0) || (get(v.l) > now && get(v.r) > now)) return 1;
	return 2;
}

inline LL getmax(){
	return std::max(std::max(get(q[0].l),get(q[0].r)),std::max(get(q.back().l),get(q.back().r)));
}

inline LL getmin(){
	return std::min(std::min(get(q[0].l),get(q[0].r)),std::min(get(q.back().l),get(q.back().r)));
}

inline void fix(Node &v){
	if(get(v.l) <= get(v.r)){
		if(get(v.l) < 0) v.l = (0-b)/k;
		if(get(v.r) > now) v.r = (now-b)/k;//get(v.r)-now;
	}
	else{
		if(get(v.r) < 0) v.r = (0-b)/k;//get(v.r);
		if(get(v.l) > now) v.l = (now-b)/k;//get(v.l)-now;
	}
}

inline void relax(){
	while(!q.empty() && chk(q[0])){
		if(chk(q[0]) == 1) q.pop_front();
		else{
			fix(q[0]);
			break;
		}
	}
	while(!q.empty() && chk(q.back())){
		if(chk(q.back()) == 1) q.pop_back();
		else{
			fix(q[SZ(q)-1]);
			break;
		}	
	}
}

LL res[MAXN],mn[MAXN];
bool ok[MAXN];

int main(){
	scanf("%d%lld",&n,&C);
	FOR(i,1,n-2) scanf("%lld",w+i);
	q.pb(Node(0,1e18));k = 1;b = 0;
	FOR(i,1,n-2){
		// first delete all x > w[i]
		// then check if < w[i],=w[i] exists
		// if no =w[i] exists  , reverse all deque
		//DEBUG(i);
		//for(auto x:q) printf("%lld %lld\n",get(x.l),get(x.r));
		mn[i] = getmin();
		now = w[i];
		relax();
		ok[i] = getmax() == w[i];
		if(q.empty()){
			puts("NO");
			return 0;
		}
		if(getmax() == w[i]){
			q.clear();
			k = 1;b = 0;
			q.pb(Node(0,w[i]));
			continue;
		}
		// kx+b = w[i]-kx-b
		b = -b+w[i];
		k = -k;
		relax();
		if(getmax() < w[i]){
			if(k == 1){
				q.pb(Node((w[i]-b)/k,(w[i]-b)/k));
			}
			else{
				q.pf(Node((w[i]-b)/k,(w[i]-b)/k));
			}
		}
	}
	puts("YES");
	LL now = get(q[0].l);
	res[n-1] = now;
	ROF(i,n-2,1){
		// now: w[i], w[i]-x, (now==w[i]: x<w[i])
		if(std::fabs(now) == w[i]){
			//assert(getmin() <= w[i]);
			now = (now>=0?-1:1)*mn[i];
		}
		else{
			// now, -w[i], w[i]-now
			if(ok[i]){
				now = (now >= 0 ? -1 : 1)*w[i];
			}
			else{
				if(now >= 0) now = w[i]-now;
				else now = -w[i]-now;

				//now = w[i]-now;
			}
		}
		res[i] = now;
	}
	FOR(i,1,n-1) res[i] += res[i-1];
	LL mn = *std::min_element(res,res+n);
	FOR(i,0,n-1) res[i] -= mn;
	FOR(i,0,n-1) printf("%lld%c",res[i]," \n"[i==n-1]);
	//FOR(i,0,n-3) DEBUG(i),assert(std::max({res[i],res[i+1],res[i+2]})-std::min({res[i],res[i+1],res[i+2]}) == w[i+1]);
	return 0;
}
/*
w[i] = max(|d[i]|,|d[i+1]|,|d[i]+d[i+1]|)
f[i][j]: i d[i]=j
f[i-1][w[i]] -> f[i][<=w[i]]
f[i-1][x<w[i]] -> f[i][w[i]-x]
f[i-1][x<w[i]] -> f[i][w[i]]

 w[i] 



 tag kx+b
*/
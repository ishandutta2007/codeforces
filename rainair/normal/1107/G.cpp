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

const int MAXN = 3e5+ 5;
const int MAXM = 18;

struct Node{
	LL val,ps,gx;
	Node(LL val=0,LL ps=0,LL gx=0) : val(val),ps(ps),gx(gx) {}
};

int n,a;
int d[MAXN];
LL c[MAXN];
Node st[MAXN];
int tp;
LL mn[MAXM+1][MAXN];// 
int pc[MAXN];

inline LL calc(int l,int r){
	int c = pc[r-l+1];
	l = std::max(l,0);r = std::min(r,n);
	return std::min(mn[c][l],mn[c][r-(1<<c)+1]);
}

std::multiset<LL> S;

int main(){
	pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
	scanf("%d%d",&n,&a);
	FOR(i,1,n) scanf("%d%lld",d+i,c+i);
	FOR(i,1,n) c[i] = a-c[i],c[i] += c[i-1];
	FOR(i,1,n) mn[0][i] = c[i];
	FOR(i,1,MAXM){
		for(int j = 0;j+(1<<(i-1)) < MAXN;++j){
			mn[i][j] = std::min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
		}
	}
	LL ans = 0;
	FOR(r,1,n){
		ans = std::max(ans,c[r]-c[r-1]);
		if(r != 1){
			LL now = 1ll*(d[r]-d[r-1])*(d[r]-d[r-1]);
			while(tp && st[tp].val <= now){
				S.erase(S.find(st[tp].gx));
				tp--;
			}
			// if(r == 4){
				// DEBUG(calc(st[tp].ps,r-2));
			// }
			st[tp+1] = Node(now,r,calc(st[tp].ps-1,r-1)+now);
			++tp;S.insert(st[tp].gx);
		}
		// if(r == 4){
			// FOR(i,1,tp) DEBUG(st[i].ps),DEBUG(st[i].gx);
			// DEBUG((*S.begin()));/
			// DEBUG(c[r]);
		// }
		if(!S.empty()) ans = std::max(ans,c[r]-*S.begin());
	}
	printf("%lld\n",ans);
	return 0;
}
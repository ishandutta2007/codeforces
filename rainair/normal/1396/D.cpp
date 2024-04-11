#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 4000+5;
const int ha = 1e9 + 7;
#define ll long long
namespace FASTIO{
    const int S=(1<<23)+5;static char b[S],o[S],p[20],*H=b,*T=b,*O=o,*P;static int r,s,c;
    inline char gc(){return H==T?T=(H=b)+fread(b,1,S,stdin):0,H!=T?*H++:-1;}
    inline int rf(){s=0;for(;!isdigit(c=gc());s=c);
                    for(r=c^48;isdigit(c=gc());(r*=10)+=c^48);
                    return s^45?r:-r;}
    inline ll rfl(){ll r;s=0;for(;!isdigit(c=gc());s=c);
                    for(r=c^48;isdigit(c=gc());(r*=10)+=c^48);
                    return s^45?r:-r;}
    inline int ef(){return fwrite(o,1,O-o,stdout),O=o,0;}
    inline int w(){return O-o>S-128?ef():0;}
    inline void wf(int x,char e=10){for(x<0?*O++=45,x=-x:0,x?:*O++=48,P=p;x;*++P=x%10+48,x/=10);
                                    for(;P!=p;*O++=*P--);e?*O++=e,w():0;}
    inline void wfl(ll x,char e=10){for(x<0?*O++=45,x=-x:0,x?:*O++=48,P=p;x;*++P=x%10+48,x/=10);
                                    for(;P!=p;*O++=*P--);e?*O++=e,w():0;}
    inline void ws(const char *e){strcpy(O,e);O+=strlen(e);w();}
    inline void wc(char e){*O++=e;w();}
}
using FASTIO::rf;using FASTIO::rfl;using FASTIO::ef;
using FASTIO::wf;using FASTIO::wfl;using FASTIO::ws;using FASTIO::wc;

int mn[MAXN<<2],cmn[MAXN<<2],coe[MAXN<<2],sm[MAXN<<2],cnt[MAXN<<2],mx[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)
int n,k,L; 

inline void pushup(int x){
	if(mn[lc] < mn[rc]){
		mn[x] = mn[lc];cnt[x] = cnt[lc];coe[x] = coe[lc];
		cmn[x] = std::min(mn[rc],cmn[lc]);
	}
	else if(mn[lc] > mn[rc]){
		mn[x] = mn[rc];cnt[x] = cnt[rc];coe[x] = coe[rc];
		cmn[x] = std::min(mn[lc],cmn[rc]);
	}
	else{
		mn[x] = mn[lc];cnt[x] = cnt[lc]+cnt[rc];coe[x] = (coe[lc]+coe[rc])%ha;
		cmn[x] = std::min(cmn[lc],cmn[rc]);
	}
	sm[x] = (sm[lc]+sm[rc])%ha;
	mx[x] = std::max(mx[lc],mx[rc]);
}

// v[i] = max(v[i],d)
std::vector<int> row,col;

inline void cover(int x,int d){ 
	if(mn[x] < d){
		if(mx[x] == mn[x]) mx[x] = d;
		(sm[x] += ha-1ll*coe[x]%ha*mn[x]%ha) %= ha;
		mn[x] = d;
		(sm[x] += 1ll*coe[x]*mn[x]%ha) %= ha;
	} 
}

int f[MAXN];

inline void pushdown(int x){
	cover(lc,mn[x]);cover(rc,mn[x]);
}

inline void build(int x,int l,int r){
	if(l == r){
		mn[x] = mx[x] = f[l];cmn[x] = 1e9+1919810;cnt[x] = 1;coe[x] = col[l-1]-(l==1?-1:col[l-2]);
		sm[x] = 1ll*coe[x]*f[l]%ha;
		return;
	}
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(x);
}

inline void modify(int x,int l,int r,int L,int R,int d){
	if(L > R) return;
	if(mn[x] >= d) return;
	if(l == L && r == R && cmn[x] > d){
		cover(x,d);
		return;
	}
	int mid = (l + r) >> 1;pushdown(x);
	if(R <= mid) modify(lc,l,mid,L,R,d);
	else if(L > mid) modify(rc,mid+1,r,L,R,d);
	else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
	pushup(x);
}

int x[MAXN],y[MAXN],c[MAXN];
int t[MAXN],cnt0;
std::vector<int> R[MAXN],C[MAXN];
std::set<std::pair<int,int> > G[MAXN];

inline void add(int o){
	for(auto x:C[o]){
		++t[c[x]];cnt0 -= t[c[x]]==1;
	}
}

inline void del(int o){
	for(auto x:C[o]){
		--t[c[x]];cnt0 += t[c[x]]==0;
	}
}

inline int suf(int i){
	auto it = G[c[i]].lower_bound(MP(y[i],i));
	++it;
	if(it == G[c[i]].end()) return L;
	return y[it->se];
}

inline int pre(int x,int l,int r,int d){
	if(mx[x] < d) return 1e9;
	if(l == r) return l;
	int mid = (l + r) >> 1;
	pushdown(x);
	int t = pre(lc,l,mid,d);
	if(t == 1e9) t = pre(rc,mid+1,r,d);
	return t;
}

inline int pre(int i){
	auto it = G[c[i]].lower_bound(MP(y[i],i));
	if(it == G[c[i]].begin()) return 0;
	--it;
	return it->fi;
}

inline int query(int x,int l,int r,int p){
	if(l == r) return mn[x];
	int mid = (l + r) >> 1;
	pushdown(x);
	if(p <= mid) return query(lc,l,mid,p);
	else return query(rc,mid+1,r,p);
}

int main(){
//	freopen("A.in","r",stdin);
	n = rf();k = rf();L = rf(); 
	FOR(i,1,n){
		x[i] = rf();y[i] = rf();c[i] = rf();
		row.pb(x[i]);col.pb(y[i]);
	}
	std::sort(all(row));row.erase(std::unique(all(row)),row.end());
	std::sort(all(col));col.erase(std::unique(all(col)),col.end());
	FOR(i,1,n){
		x[i] = std::lower_bound(all(row),x[i])-row.begin()+1;
		y[i] = std::lower_bound(all(col),y[i])-col.begin()+1;
	}
	int N = row.size(),M = col.size(),ans = 0;
	FOR(i,1,n) R[x[i]].pb(i);
	FOR(up,1,N){
		int d1 = row[up-1]-(up==1?-1:row[up-2]);
		FOR(i,1,M) f[i] = L,C[i].clear();FOR(i,1,k) t[i] = 0,G[i].clear();cnt0 = k;
		FOR(i,1,n) if(x[i] >= up) C[y[i]].pb(i),G[c[i]].insert(MP(y[i],i));
		int p = 0;
		FOR(i,1,M){
			while(p <= M && cnt0) ++p,add(p);
			f[i] = p<=M?col[p-1]:L;
			del(i);
		}
		build(1,1,M);
//		FOR(i,1,M) printf("%d ",f[i]);puts("");
		ROF(down,N,up){
			int d2 = (down==N?L:row[down])-row[down-1];
			int gx = ha-sm[1];
			(gx += 1ll*(col[M-1]+1)*L%ha) %= ha;
			(ans += 1ll*d1*d2%ha*gx%ha) %= ha;
//			printf("up=%d down=%d %d\n",up,down,gx);
//			if(down == 4) exit(0);
			for(auto x:R[down]){
				int p = std::max(pre(1,1,M,col[y[x]-1]),pre(x)+1);
				int v = suf(x);if(v != L) v = col[v-1];
				modify(1,1,M,p,y[x],v);
//				printf("%d %d %d %d\n",p,y[x],v,(col[M-1]+1)*L-sm[1]);
				G[c[x]].erase(MP(y[x],x));
			}
		}
	}
	wf(ans);
	ef();
	return 0;
}
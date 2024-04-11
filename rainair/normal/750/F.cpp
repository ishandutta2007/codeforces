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

const int MAXN = 128 + 5;
std::vector<int> G[MAXN];// 
bool vis[MAXN];
std::vector<int> T[MAXN];
int CNT = 0;

inline void query(int x){
	vis[x] = 1;
	if(!G[x].empty()) return;
	++CNT;
	#ifdef RainAir
	G[x] = T[x];
	return;
	#endif
	printf("? %d\n",x);std::fflush(stdout);
	int k;scanf("%d",&k);std::vector<int> res;
	FOR(i,1,k){
		int x;scanf("%d",&x);res.pb(x);
	}
	G[x] = res;
}

inline int go(int x){
	// assert(vis[x]);
	for(auto y:G[x]) if(!vis[y]) return y;
	return 0;
}

inline void answer(int x){
	printf("! %d\n",x);std::fflush(stdout);
}

int v1[MAXN],v2[MAXN];
std::mt19937 g(4141);
int id[MAXN],cs;

inline void Solve(){CNT = 0;
	int h=7;scanf("%d",&h);
	FOR(i,1,(1<<h)-1) G[i].clear(),vis[i] = 0;
	int n = (1<<h)-1;
	#ifdef RainAir
	FOR(i,1,n) T[i].clear();
	FOR(i,1,n) id[i] = i;//std::shuffle(id+1,id+n+1,g);
	int cnt= 0;
	FOR(i,1,n-1){
		 int u,v;scanf("%d%d",&u,&v);
//		if((i<<1) > n) break;
//		T[id[i]].pb(id[i<<1]);cnt += 2;
//		T[id[i<<1]].pb(id[i]);
//		T[id[i]].pb(id[i<<1|1]);
//		T[id[i<<1|1]].pb(id[i]);
		 T[u].pb(v);T[v].pb(u);
	}
//	FOR(i,1,n) std::shuffle(all(T[i]),g);
	#endif
//	if(cs != 2) return;
	int v = 1;query(v);
	// DEBUG(v);
	if(G[v].size() == 2){
		answer(v);return;
	}
	int las=-1;
	int dep = 0;// 
	if(G[v].size() == 1){
		las = v;v = G[v][0];
		dep = 1;
	}
	else{
		int cnt1 = 0,cnt2 = 0;
		for(int x=go(v);;x=go(x)){
			query(x);
			// if(G[x].size() == 2){
				// answer(x);return;
			// }
			v1[++cnt1] = x;
			if(G[x].size() == 1) break;
		}
		for(int x=go(v);;x=go(x)){
			query(x);
			// if(G[x].size() == 2){
				// answer(x);return;
			// }
			v2[++cnt2] = x;
			if(G[x].size() == 1) break;
		}
		dep = (cnt2+cnt1+1)>>1;
		if(cnt1 < cnt2){
			las = v2[((cnt2-cnt1)>>1)-1];
			if(!las) las = v;
			v = v2[(cnt2-cnt1)>>1];
		}
		else if(cnt1 > cnt2){
			las = v1[((cnt1-cnt2)>>1)-1];;
			if(!las) las = v;
			v = v1[(cnt1-cnt2)>>1];
		}
		else{
			las = v;
			v = go(v);
			dep = cnt1+1;
		}
	}
	// DEBUG(id[1]);
	while(dep < h-3){
		int cnt = 0;//if(CNT == 16){answer(go(v));return;}
		query(v);vis[v] = 1;
		if(G[v].size() == 2) break;
		// DEBUG(v);
		// if(dep == 2) exit(0);
		int tt = go(v),x = tt;
		for(int i=1;i<=dep-1;x=go(x),++i){
			query(x);
//			if(cs == 4 && v == 12) DEBUG(x);
			if(G[x].size() == 2){
				answer(x);return;
			}
//			if(cs == 4 && v == 12) DEBUG(vis[24]),DEBUG(x);
			v1[++cnt] = x;
			if(G[x].size() == 1) break;
		}
//		if(cs == 4 && v == 12) DEBUG(x);
		v1[++cnt] = x;
		query(x);las = v;
		if(G[x].size() != 1){
			FOR(i,1,cnt) vis[v1[i]] = 0;
			vis[v] = 1;
			v = tt;
		}
		else v = go(v);
		++dep;
	}
	if(dep == h-1){
		answer(v);
		return;
	}
	if(dep == h-2){
		query(v);
		for(auto x:G[v]){
			query(x);
			if(G[x].size() == 2){
				answer(x);
				return;
			}
		}
	}
	if(dep == h-3){
		query(v);
		int v1=-1,v2=-1;
		for(auto x:G[v]){
			if(x != las){
				if(v1 == -1) v1 = x;
				else v2 = x;
			}
		}
		query(v1);query(v2);
		for(auto x:G[v1]){
			if(x != v){
				query(x);
				if(G[x].size() == 2) return answer(x);
			}
		}
		for(auto x:G[v2]){
			if(x != v){
				if(CNT == 16) return answer(x);
				query(x);
				if(G[x].size() == 2) return answer(x);
			}
		}
	}
}

int main(){
	int T;scanf("%d",&T);
	FOR(i,1,T){
//		DEBUG(i);
		cs=i;
		Solve();
		#ifdef RainAir
		printf("Case #%d uses %d queries.\n",i,CNT);
		#endif
	}
	return 0;
}
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

const int MAXN = 3e6 + 5;

int n,k;
int s[MAXN],a[MAXN],b[MAXN];
char str[MAXN];
int l[MAXN],r[MAXN],_l[MAXN],_r[MAXN];
int ans[MAXN];
std::vector<int> G[MAXN];

inline bool chk(){
	std::set<P> S;
	FOR(i,1,k) if(l[i] > r[i]) return 0;
	FOR(i,1,k) G[i].clear(),ans[i] = 0;
	FOR(i,1,k) G[l[i]].pb(i);
	FOR(i,1,k){
		for(auto x:G[i]) S.insert(MP(r[x],x));
		if(S.empty()){
			return 0;
		}
		auto p = S.begin();
		if(p->fi < i) return 0;
		ans[p->se] = i;
		S.erase(p);
	}
	return 1;
}

inline void Solve(){
	scanf("%d",&k);scanf("%s",str+1);n = strlen(str+1);
	FOR(i,1,n) s[i] = str[i]-'a'+1;
	scanf("%s",str+1);
	FOR(i,1,n) a[i] = str[i]-'a'+1;
	scanf("%s",str+1);
	FOR(i,1,n) b[i] = str[i]-'a'+1;
	FOR(i,1,k) l[i] = 1,r[i] = k;
	int ps = 1;
	while(ps <= n && a[ps] == b[ps]){
		l[s[ps]] = std::max(l[s[ps]],a[ps]);
		r[s[ps]] = std::min(r[s[ps]],b[ps]);++ps;
	}
	if(ps > n){
		if(chk()){
			// FOR(i,1,k) DEBUG(l[i]),DEBUG(r[i]);
			puts("YES");
			FOR(i,1,k) printf("%c",ans[i]+'a'-1);puts("");
			return;
		}
		puts("NO");
		return;
	}
	FOR(i,1,k) _l[i] = l[i],_r[i] = r[i];
	r[s[ps]] = std::min(r[s[ps]],b[ps]-1);
	FOR(i,ps,n){// a
		int t = l[s[i]];
		l[s[i]] = std::max(l[s[i]],a[i]+1);
		if(chk()){
			puts("YES");
			FOR(i,1,k) printf("%c",ans[i]+'a'-1);puts("");
			return;
		}
		l[s[i]] = std::max(t,a[i]);
	}
	if(chk()){
		puts("YES");
		FOR(i,1,k) printf("%c",ans[i]+'a'-1);puts("");
		return;
	}
	FOR(i,1,k) l[i] = _l[i],r[i] = _r[i];
	l[s[ps]] = std::max(l[s[ps]],a[ps]+1);
	FOR(i,ps,n){
		int t = r[s[i]];
		r[s[i]] = std::min(r[s[i]],b[i]-1);
		// if(i == 3){
				// FOR(i,1,k) DEBUG(l[i]),DEBUG(r[i]);
		// }
		if(chk()){
			puts("YES");
			FOR(i,1,k) printf("%c",ans[i]+'a'-1);puts("");
			return;
		}
		r[s[i]] = std::min(t,b[i]);
	}
	if(chk()){
		puts("YES");
		FOR(i,1,k) printf("%c",ans[i]+'a'-1);puts("");
		return;
	}
	puts("NO");
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		Solve();
	}
	return 0;
}
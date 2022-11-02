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

int ch[MAXN][26],tot = 1,fail[MAXN],rt = 1,n;
std::string s[MAXN],t;
LL sm[MAXN];

inline void clear(){
	FOR(i,1,tot) FOR(j,0,25) ch[i][j] = 0;
	FOR(i,1,tot) fail[i] = sm[i] = 0;
	tot = rt = 1;
}

inline void insert(int id){
	int v = rt;
	FOR(i,0,(int)s[id].length()-1){
		int o = s[id][i]-'a';
		if(!ch[v][o]) ch[v][o] = ++tot;
		v = ch[v][o];
	}
	sm[v]++;
}

inline void build(){
	std::queue<int> q;
	FOR(i,0,25){
		if(ch[rt][i]) fail[ch[rt][i]] = rt,q.push(ch[rt][i]);
		else ch[rt][i] = rt;
	}
	while(!q.empty()){
		int v = q.front();q.pop();
		FOR(i,0,25){
			if(ch[v][i]) fail[ch[v][i]] = ch[fail[v]][i],q.push(ch[v][i]),sm[ch[v][i]] += sm[fail[ch[v][i]]];
			else ch[v][i] = ch[fail[v]][i];
		}
	}
}

LL pre[MAXN],suf[MAXN];

int main(){
	std::ios::sync_with_stdio(false);
	std::cin >> t >> n;
	FOR(i,1,n) std::cin >> s[i];
	FOR(i,1,n) insert(i);build();
	int v = 1;
	FOR(i,0,(int)t.size()-1){
		int o = t[i]-'a';v = ch[v][o];
		pre[i+1] = sm[v];
	}
	clear();
	FOR(i,1,n) std::reverse(all(s[i])),insert(i);build();
	v = 1;
	ROF(i,(int)t.size()-1,0){
		int o = t[i]-'a';v = ch[v][o];
		suf[i+1] = sm[v];
	}
	LL ans = 0;
	FOR(i,1,(int)t.size()-1) ans += 1ll*pre[i]*suf[i+1];
	printf("%lld\n",ans);
	return 0;
}
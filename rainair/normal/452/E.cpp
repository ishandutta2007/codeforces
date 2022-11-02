#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 6e5 + 5;
const int ha = 1e9 + 7;
int ch[MAXN][26],len[MAXN],fail[MAXN],tot=1;

inline int work(int p,int c){
	int q = ch[p][c],nq = ++tot;
	memcpy(ch[nq],ch[q],sizeof(ch[nq]));
	len[nq] = len[p]+1;fail[nq] = fail[q];fail[q] = nq;
	for(;p&&ch[p][c]==q;p=fail[p]) ch[p][c] = nq;
	return nq;
}

inline int insert(int p,int c){
	int q = ch[p][c];
	if(q){
		if(len[q] == len[p]+1) return q;
		return work(p,c);
	}
	int np = ++tot;len[np] = len[p]+1;
	for(;p&&!ch[p][c];p=fail[p]) ch[p][c] = np;
	if(!p) fail[np] = 1;
	else{
		q = ch[p][c];
		if(len[q] == len[p]+1) fail[np] = q;
		else fail[np] = work(p,c);
	}
	return np;
}

std::vector<int> pos[4];
char str[MAXN];
std::vector<int> G[MAXN];
LL val1[MAXN],val2[MAXN],sm[MAXN],ans[MAXN];
LL s1[MAXN],s2[MAXN];

inline void dfs(int v){
	sm[v] = s1[v] = s2[v] = 0;
	for(auto x:G[v]){
		dfs(x);
		sm[v] -= s1[x]*s2[x];
		s1[v] += s1[x];
		s2[v] += s2[x];
	}
	s1[v] += val1[v];
	s2[v] += val2[v];
	sm[v] += s1[v]*s2[v];
}

int main(){
	int m = 1e9;
	FOR(i,1,3){
		scanf("%s",str+1);int len = strlen(str+1);m = std::min(m,len);
		pos[i].resize(len+1);pos[i][0] = 1;
		FOR(j,1,len) pos[i][j] = insert(pos[i][j-1],str[j]-'a');
	}
	FOR(i,2,tot) G[fail[i]].pb(i);
	FOR(i,1,SZ(pos[1])-1) ++val1[pos[1][i]];
	FOR(i,1,SZ(pos[2])-1) ++val2[pos[2][i]];
	dfs(1);
	FOR(i,1,tot) val1[i] = sm[i],val2[i] = 0;
	FOR(i,1,SZ(pos[3])-1) ++val2[pos[3][i]];
	dfs(1);
	FOR(i,1,tot) (ans[len[i]] += sm[i]) %= ha;
	ROF(i,m,1) (ans[i] += ans[i+1]) %= ha;
	FOR(i,1,m) printf("%lld%c",ans[i]," \n"[i==m]);
	return 0;
}
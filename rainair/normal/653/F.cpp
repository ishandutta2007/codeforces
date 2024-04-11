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

const int MAXN = 1e6 + 5;
const int MAXM = 18;
int mn[MAXM+1][MAXN];
int sm[MAXN];
char str[MAXN];int n;
int pc[MAXN];

inline int calc(int l,int r){
	int c = pc[r-l+1];
	return std::min(mn[c][l],mn[c][r-(1<<c)+1]);
}

int ch[MAXN][2],len[MAXN],fail[MAXN],r[MAXN],tot=1;

inline int work(int p,int c){
	int q = ch[p][c],nq = ++tot;
	memcpy(ch[nq],ch[q],sizeof(ch[nq]));
	len[nq] = len[p]+1;fail[nq] = fail[q];
	fail[q] = nq;for(;p&&ch[p][c]==q;p=fail[p]) ch[p][c] = nq;
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

int sa[MAXN],tax[MAXN];
int lst[MAXN];
std::vector<P<int,int> > G[MAXN];
std::map<int,int> S;

int main(){
	pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
	scanf("%d",&n);scanf("%s",str+1);
	FOR(i,1,n) sm[i] = sm[i-1]+(str[i]=='(' ? 1 : -1),mn[0][i] = sm[i];
	FOR(i,1,MAXM) for(int j = 1;j+(1<<(i-1)) <= n;++j) mn[i][j] = std::min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
	FOR(i,1,n){
		int l = i,r = n,ans = i-1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(calc(i,mid)-sm[i-1] >= 0) ans = mid,l = mid+1;
			else r = mid-1;
		}
		lst[i] = ans;
	}
	int p = 1;
	ROF(i,n,1) p = insert(p,str[i]==')'),r[p] = i;
	FOR(i,1,tot) ++tax[len[i]];
	FOR(i,1,n) tax[i] += tax[i-1];
	FOR(i,1,tot) sa[tax[len[i]]--] = i;
	ROF(i,tot,1) if(!r[fail[sa[i]]]) r[fail[sa[i]]] = r[sa[i]];
	FOR(i,2,tot){
		int l = r[i],r1 = l+len[fail[i]],r2 = l+len[i]-1;
		r2 = std::min(r2,lst[l]);
		if(r1 > r2) continue;
		G[r1].pb(sm[l-1],1);
		G[r2+1].pb(sm[l-1],-1);
	}
	LL ans = 0;
	ROF(i,n,1){
		++S[sm[i]];
		for(auto x:G[i]) ans += x.se*S[x.fi];
	}
	printf("%lld\n",ans);
	return 0;
}
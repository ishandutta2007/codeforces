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

const int MAXN = 500+5;
const int MAXM = 16;
const int ha = 1e9 + 7;

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}

int ch[MAXN][2],tot;
char a[MAXN],str[MAXN];
int rt;

inline int work(int l,int r){
	if(l > r) return 0;
	if(l == r){
		a[++tot] = str[l];
		return tot;
	}
	int sm = 0,ps = 0;
	FOR(i,l,r){
		if(str[i] == '(') ++sm;
		if(str[i] == ')') --sm;
		if(sm == 0){
			ps = i;break;
		}
	}
	if(ps == r) return work(l+1,r-1);
	int x = ++tot;
	a[x] = str[ps+1];
	ch[x][0] = work(l+1,ps-1);
	ch[x][1] = work(ps+3,r-1);
	return x;
}

int f[MAXN][(1<<16)+3];
int g[9][(1<<16)+3];
// v,  T S,

inline int ctoi(char c){
	if(c >= 'A' && c <= 'D') return c-'A';
	if(c >= 'a' && c <= 'd') return c-'a';
	return -1;
}

int N = (1<<16);

inline void OR(int f[]){for(int mid = 1;mid < N;mid <<= 1) for(int i = 0;i < N;i += (mid<<1)) FOR(j,0,mid-1) add(f[i+mid+j],f[i+j]);}
inline void iOR(int f[]){for(int mid = N>>1;mid;mid >>= 1) for(int i = 0;i < N;i += (mid<<1)) FOR(j,0,mid-1) add(f[i+mid+j],ha-f[i+j]);}
inline void AND(int f[]){for(int mid = 1;mid < N;mid <<= 1) for(int i = 0;i < N;i += (mid<<1)) FOR(j,0,mid-1) add(f[i+j],f[i+mid+j]);}
inline void iAND(int f[]){for(int mid = N>>1;mid;mid >>= 1) for(int i = 0;i < N;i += (mid<<1)) FOR(j,0,mid-1) add(f[i+j],ha-f[i+mid+j]);}
inline void COR(int A[],int B[],int C[]){OR(A);OR(B);FOR(i,0,N-1) C[i] = 1ll*A[i]*B[i]%ha;iOR(C);iOR(A);iOR(B);}
inline void CAND(int A[],int B[],int C[]){AND(A);AND(B);FOR(i,0,N-1) C[i] = 1ll*A[i]*B[i]%ha;iAND(C);iAND(A);iAND(B);}

int tmp[(1<<16)+5];

inline void dfs(int v){
	if(!ch[v][0] && !ch[v][1]){
		int id = ctoi(a[v])+(4*(a[v] >= 'a' && a[v] <= 'd'));
		if(id == -1) id = 8;
		FOR(S,0,(1<<16)-1) f[v][S] = g[id][S];
		return;
	}
	dfs(ch[v][0]);dfs(ch[v][1]);
	if(a[v] == '&') return CAND(f[ch[v][0]],f[ch[v][1]],f[v]);
	if(a[v] == '|') return COR(f[ch[v][0]],f[ch[v][1]],f[v]);
	CAND(f[ch[v][0]],f[ch[v][1]],tmp);
	COR(f[ch[v][0]],f[ch[v][1]],f[v]);
	FOR(S,0,N-1) add(f[v][S],tmp[S]);
}

int main(){
	FOR(i,0,3){
		int t = 0;
		FOR(S,0,(1<<4)-1) t |= (((S>>i)&1)<<S);
		++g[i][t];++g[i+4][t^((1<<16)-1)];
		++g[8][t];++g[8][t^((1<<16)-1)];
	}
	scanf("%s",str+1);int len = strlen(str+1);
	rt = work(1,len);
	dfs(rt);
	int n;scanf("%d",&n);
	int t0=0,t1=0;
	FOR(i,1,n){
		int a,b,c,d,e;scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		int t = a|(b<<1)|(c<<2)|(d<<3);
		if(e) t1 |= (1<<t);
		else t0 |= (1<<t);
	}
	int ans = 0;
	FOR(S,0,(1<<16)-1) if(((S&t1) == t1) && ((S&t0) == 0)) add(ans,f[rt][S]);
	printf("%d\n",ans);
	return 0;
}
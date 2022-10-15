#include <bits/stdc++.h>
 
#define IM using
#define GAY namespace
#define LOL std;
 
IM GAY LOL
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
 
#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)
 
#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)
 
#define mp make_pair
 
#define pb push_back
#define F first
#define S second
 
const int OO = 1e9;
const ll INF = 1e18;
 
const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}
 
const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}
 
#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;
 
	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}
 
inline void ini(int& x){
	x = getnum<int>();
}
 
inline void scani(int& x){
	scanf("%d",&x);
}
 
const int N = 1e5 + 5;
const int B = 17;
 
int n;
vi roots;
vi lst[N];
int m;
int a[N], b[N];
 
int sz[N], depth[N];
int sparset[B+1][N];
int fakaa(int now){
	sz[now] = 1;
	FOR(i,lst[now].size()){
		int to = lst[now][i];
		depth[to] = depth[now]+1;
		sparset[0][to] = now;
		fakaa(to);
		sz[now] += sz[to];
	}
}
 
vi qq[N];
int ans[N];
 
int cnt[N];
int add(int now, int exx, int v){
	cnt[depth[now]] += v;
	FOR(i,lst[now].size()){
		int to = lst[now][i];
		if(to == exx)continue;
		add(to, exx, v);
	}
}
 
void dfs(int now, bool keep){
	int big = -1;
	FOR(i,lst[now].size()){
		int to = lst[now][i];
		if(big == -1 || sz[big] < sz[to])big = to;
	}
	FOR(i,lst[now].size()){
		int to = lst[now][i];
		if(to == big)continue;
		dfs(to, 0);
	}
	if(big != -1)dfs(big, 1);
	add(now, big, 1);
	
	FOR(i,qq[now].size()){
		int j = qq[now][i];
		ans[j] = cnt[depth[now]+b[j]]-1;
	}
	
	if(!keep)add(now, -1, -1);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n;
    REP(i,1,n){
    	int p;
    	cin>>p;
    	if(p == 0)roots.pb(i);
    	else lst[p].pb(i);
	}
	cin>>m;
	REP(i,1,m){
		cin>>a[i]>>b[i];
	}
	
	FOR(i,roots.size()){
		depth[roots[i]] = 1;
		sparset[0][roots[i]] = -1;
		fakaa(roots[i]);
	}
	
	REP(i,0,B-1){
		REP(j,1,n){
			if(sparset[i][j] == -1)sparset[i+1][j] = -1;
			else sparset[i+1][j] = sparset[i][sparset[i][j]];
		}
	}
	
	REP(i,1,m){
		int now = a[i];
		REV(j,B,0){
			if(sparset[j][now] != -1 && depth[sparset[j][now]] >= depth[a[i]]-b[i]){
				now = sparset[j][now];
			}
		}
		if(depth[now] == depth[a[i]]-b[i]){
			qq[now].pb(i);
		}
	}
	
	FOR(i,roots.size()){
		dfs(roots[i], 0);
	}
	
	REP(i,1,m){
		cout << ans[i] << " ";
	}
	cout << endl;
    
    return 0;
}
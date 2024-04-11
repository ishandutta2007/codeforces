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

const int MAXN = 3000+5;

int x;
int p[MAXN];

inline bool chk(int n){
	FOR(l,1,n){
		int sm = 0;
		FOR(r,l,n){
			if(l == 1 && r == n) continue;
			sm += p[r];
			if(x%sm == 0) return 0;
		}
	}
	return 1;
}

int ch[MAXN*20][9],tot = 1,rt = 1;
int ban[MAXN*20];

inline void insert(int len){
	int v = rt;
//	FOR(i,1,len) printf("%d",p[i]);puts("");
	FOR(i,1,len){
		if(!ch[v][p[i]-1]) ch[v][p[i]-1] = ++tot;
		v = ch[v][p[i]-1];
	}
	ban[v] = 1;
}

int fail[MAXN*20];

inline void build(){
	std::queue<int> q;
	FOR(i,0,8){
		if(ch[rt][i]) fail[ch[rt][i]] = rt,q.push(ch[rt][i]);
		else ch[rt][i] = rt;
	}
	while(!q.empty()){
		int v = q.front();q.pop();
		FOR(i,0,8){
			if(ch[v][i]) fail[ch[v][i]] = ch[fail[v]][i],q.push(ch[v][i]);
			else ch[v][i] = ch[fail[v]][i];
		}
	}
}

inline void dfs(int step,int now){
	if(now == 0){
		if(chk(step-1)){
			insert(step-1);		
		}
		return;
	}
	FOR(i,1,std::min(now,9)) p[step] = i,dfs(step+1,now-i);
}

char str[MAXN];
int n;
int f[2][MAXN*20];

int main(){
	scanf("%s",str+1);n = strlen(str+1);scanf("%d",&x);
	dfs(1,x);build();
	int now = 0;
	CLR(f,-0x3f);f[now][rt] = 0;
	FOR(i,1,n){
		CLR(f[now^1],-0x3f);
		FOR(v,1,tot){
			if(f[now][v] < 0) continue;
			if(ban[v]) continue;
			f[now^1][v] = std::max(f[now^1][v],f[now][v]);
			f[now^1][ch[v][str[i]-'1']] = std::max(f[now^1][ch[v][str[i]-'1']],f[now][v]+1);
		}
		now ^= 1;
	}
	int ans = 0;
	FOR(i,1,tot) if(!ban[i]) ans = std::max(ans,f[now][i]);
//	DEBUG(ans);
	printf("%d\n",n-ans);
	return 0;
}
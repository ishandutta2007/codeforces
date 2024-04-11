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

const int MAXN = 10000 + 5;
int f[MAXN][MAXN],nxt[MAXN];
char s[MAXN],t[MAXN];
int n,m;
int sm[MAXN];

inline void upmin(int &a,int b){
	if(a > b) a = b;
}

int main(){
	scanf("%s%s",s+1,t+1);n = strlen(s+1);m = strlen(t+1);
	FOR(i,1,n){
		nxt[i] = i;int sm = (s[i]=='.'?-1:1);
		while(nxt[i]+1 <= n && sm){
			if(sm < 0) break;
			++nxt[i];
			sm += (s[nxt[i]]=='.'?-1:1);
		}
		if(sm != 0) nxt[i] = n+1;
	}
	CLR(f,0x3f);
	f[0][0] = 0;
	nxt[n+1] = n+1;
	FOR(i,0,n){
		FOR(j,0,m){
			upmin(f[i+1][j],f[i][j]+1);
			if(s[i+1] == t[j+1]) upmin(f[i+1][j+1],f[i][j]);
			if(s[i+1] == '.' && j) upmin(f[i+1][j-1],f[i][j]);
			upmin(f[nxt[i+1]][j],f[i][j]);
		}
	}
	printf("%d\n",f[n][m]);
	return 0;
}
/*
f[i][j]: sitj 
f[i][j] ->
f[i+1][j]+1,
f[i+1][j+1],s[i+1]==t[j+1]
f[i+1][j-1],s[i+1]=='.'
,nxt[i]j>i[i,j]
f[nxt[i]][j],
*/
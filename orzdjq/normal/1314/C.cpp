#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=1005;
int n,m;
LL k;
char c[Maxn];
int nxt[Maxn*Maxn][26],kc,rt;
vector<pair<int,int> > V[Maxn*Maxn];
void Ins(int x){
	int now=rt;
	for (int i=x;i<n;i++){
		if (!nxt[now][c[i]-'a'])nxt[now][c[i]-'a']=++kc;
		now=nxt[now][c[i]-'a'];
		V[now].pb(mp(x,i));
	}
}
vector<pair<int,int> > d;
void dfs(int x){
	for (int i=0;i<V[x].size();i++) d.pb(V[x][i]);
	for (int i=0;i<26;i++){
		if (nxt[x][i]) dfs(nxt[x][i]);
	}
}
bool Av[Maxn][Maxn];
LL dp[Maxn][Maxn],S[Maxn][Maxn];
LL tree[Maxn][Maxn*4];
const LL NF=1e18+5;
int Nxt[Maxn];
LL calc(int ps){
	memset(Av,0,sizeof(Av));
	for (int i=ps;i<d.size();i++){
		Av[d[i].first][d[i].second]=true;
	}
	for (int i=0;i<n;i++){
		Nxt[i]=n+1;
		for (int j=i;j<n;j++){
			if (Av[i][j]){
				Nxt[i]=j;
				break;
			}
		}
	}
	memset(dp,0,sizeof(dp));
	memset(S,0,sizeof(S));
	dp[0][n]=1;
	for (int i=0;i<=n;i++) S[0][i]=1;
	for (int i=n-1;i>=0;i--){
		for (int j=1;j<=m;j++){
			int ni=Nxt[i];
			dp[j][i]=S[j-1][ni+1];
		}
		for (int j=1;j<=m;j++){
			S[j][i]=S[j][i+1]+dp[j][i];
			if (S[j][i]>=NF) S[j][i]=NF;
		}
	}
	return dp[m][0];
}
int main(){
	rt=++kc;
	scanf("%d %d %lld",&n,&m,&k);
	scanf("%s",c);
	for (int i=0;i<n;i++){
		Ins(i);
	}
	dfs(rt);
	int lo=0,hi=d.size();
//	for (int i=0;i<d.size();i++) cout<<d[i].first<<' '<<d[i].second<<endl;
//	cout<<calc(0)<<endl;
	while (hi-lo>1){
		int mid=lo+hi>>1;
		LL C=calc(mid);
		if (C>=k) lo=mid;
		else hi=mid;
	}
	for (int i=d[lo].first;i<=d[lo].second;i++){
		putchar(c[i]);
	}
	puts("");
	return 0;
}
#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
#define MOD 1000000007
#define MAXN 200005

ll r;
vi g[MAXN];int n;
bool tk[MAXN];
int fat[MAXN];
int szt[MAXN];ll v[MAXN];
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}

void dfs(int x, int f, int d, ll s, ll* a, int *q){
	d^=1;
	if(d)s+=v[x];
	else s-=v[x];
	a[d]+=s;q[d]++;
	for(int y:g[x]){
		if(tk[y]||y==f)continue;
		dfs(y,x,d,s,a,q);
	}
}

void cdfs(int x=0, int f=-1, int sz=-1){
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	tk[x]=1;fat[x]=f;

	r+=v[x];
	ll d[2]={0,v[x]};int q[2]={0,1};
	for(int y:g[x]){
		if(tk[y])continue;
		ll d2[2]={0,0};int q2[2]={0,0};
		dfs(y,x,0,0,d2,q2);
		//printf(" a %lld %lld\n",d2[0],d2[1]);
		d2[0]%=MOD;d2[1]%=MOD;
		r+=2*(q[0]*d2[1]+q2[1]*d[0]);r%=MOD;
		r+=2*(q[1]*(MOD-d2[0])+q2[0]*d[1]);r%=MOD;
		//printf(" %d %lld\n",y+1,r);
		q[0]+=q2[1];q[1]+=q2[0];
		d[0]+=(d2[1]-q2[1]*v[x]%MOD);d[0]%=MOD;
		d[1]+=((MOD-d2[0])+q2[0]*v[x]%MOD);d[1]%=MOD;
	}
	//r%=MOD;r+=MOD;r%=MOD;
	//printf("%d %lld\n",x,r);

	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){memset(tk,0,sizeof(tk));cdfs();}


int main(){
	scanf("%d",&n);
	FORN(i,n)scanf("%lld",v+i);
	FOR(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	centroid();r%=MOD;r+=MOD;r%=MOD;
	printf("%lld\n",r);
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n;
char c[2005][2005];
P<int,int> seg[2005];
int pos[2005];
int len;
int fa[2005];
void solve(){
	V<P<int,int> > ed;
	scanf("%d",&n);
	FOR(i,1,n)fa[i]=i;
	FOR(i,1,n)scanf("%s",c[i]+i);
	int cnt=0;
	FOR(tl,2,n){
		FOR(l,1,n-tl+1){
			int r=l+tl-1;
			if(c[l][r]=='0'||fa[l]==fa[r])continue;
			cnt++;
			len=0;
			pos[++len]=l;
			int tl=fa[l],tr=fa[r];
			FOR(i,l+1,r)if(fa[i]!=fa[i-1]&&fa[i]!=fa[r])pos[++len]=i;
			pos[++len]=r;
			ed.PB(MP(pos[1],pos[len]));
			if(len>2)ed.PB(MP(pos[2],pos[len]));
			for(int i=4;i<len;i+=2)ed.PB(MP(pos[i],pos[i-2]));
			for(int i=3;i<len;i+=2)ed.PB(MP(pos[i],pos[i-2]));
			FOR(i,1,n)if(fa[i]>=tl&&fa[i]<=tr)fa[i]=tl;
		}
	}
	for(auto u:ed)printf("%d %d\n",u.F,u.S);
}
signed main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();
	RE 0;
}